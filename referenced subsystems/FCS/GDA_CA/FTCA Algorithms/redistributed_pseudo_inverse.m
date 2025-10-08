%% Redistributed Pseudoinverse FTCA
% DESCRIPTION:
%   Implements the redistributed pseudoinverse (RPI) method for control allocation as described 
%   in Ref. [2]. The method computes an unconstrained pseudo–inverse 
%   solution for healthy actuators (those with effectiveness above faultThreshold), “pins” those 
%   that saturate, and iteratively redistributes the residual demand until the achieved virtual 
%   control approximates the desired tau within a specified tolerance.
%
% INPUTS:
%   tau           - Desired virtual control command [p x 1] [rad/s^2].
%   CB            - Control effectiveness matrix [p x m].
%   Lambda        - Actuator effectiveness vector [m x 1] (unitless, with 1 = healthy).
%   u_min         - Lower bounds on actuator commands [m x 1] [rad].
%   u_max         - Upper bounds on actuator commands [m x 1] [rad].
%   faultThreshold- Scalar threshold (unitless) below which an actuator is considered faulty.
%
% OUTPUTS:
%   u             - Computed actuator command vector [m x 1] [rad] 
%
% WRITTEN BY:
%   Garrett D. Asper <garrettasper@vt.edu>
%
% HISTORY:
%   20250211 - Created and debugged by GDA
%
% REFERENCES:
%   [2]

function u = redistributed_pseudo_inverse(tau, CB, Lambda, u_min, u_max, faultThreshold)
    % Dimensions: tau is [p x 1], CB is [p x m].
    nAct = size(CB,2);

    % Identify healthy actuators.
    healthy = (Lambda >= faultThreshold);
    CB_healthy = CB(:,healthy);
    u_full = zeros(nAct,1);
    u_healthy = pinv(CB_healthy)*tau;  % Unconstrained pseudo–inverse for healthy actuators.
    idxHealthy = find(healthy);
    u_full(idxHealthy,1) = u_healthy;
    
    % Initialize "pinned" indicators.
    pinned = false(nAct,1);
    torqueTol = 1e-15;  % Tolerance for matching tau.
    %torqueTol =  1e-4 * norm(tau,2);
    maxIter = length(u_min);
    %maxIter = 50;
    iter = 0;
    tau_resid = tau;
    done = false;
    
    % Loop to iteratively distribute residual command tau to unsaturated,
    % functional actuators
    while ~done && (iter < maxIter)
        iter = iter + 1;
        
        % Solve least-squares for currently free (healthy and not pinned) actuators.
        freeCols = find(healthy & ~pinned);
        CB_free = CB(:, freeCols);
        
        if isempty(CB_free)
            break;
        end
        
        u_free = pinv(CB_free) * tau_resid;
        u_full(freeCols) = u_free;
        
        % Check free actuators for saturation.
        for i = 1:length(freeCols)
            col = freeCols(i);
            if u_full(col) > u_max(col)
                u_full(col) = u_max(col);
                pinned(col) = true;
            elseif u_full(col) < u_min(col)
                u_full(col) = u_min(col);
                pinned(col) = true;
            end
        end
        
        % Update residual tau based on pinned actuators.
        pinnedCols = find(healthy & pinned);
        tau_pinned = CB(:, pinnedCols) * u_full(pinnedCols);
        tau_resid = tau - tau_pinned;
        
        % Attempt to un–pin actuators if possible.
        recheckCols = find(healthy & pinned);
        for i = 1:length(recheckCols)
            c = recheckCols(i);
            if u_full(c) > u_min(c) + 1e-12 && u_full(c) < u_max(c) - 1e-12
                pinned(c) = false;
            end
        end

        
        % Check if achieved tau is within tolerance.
        tau_achieved = CB*u_full;
        tau_error = norm(tau_achieved-tau);
        if tau_error < torqueTol
            done = true;
        end

        % if iter == maxIter
        %     disp('iter reached')
        % end
    end

    tau_final = CB*u_full;
    err = norm(tau-tau_final,2);
    if err > torqueTol && ~any(~pinned)   % no free actuators
        rho = norm(tau,2) / norm(tau_final,2);  % scale factor
        if rho > 1
           u_full = u_full*rho;
           % clamp again
           u_full = max(u_min, min(u_max, u_full));
        end
    end

    
    u = u_full;
end
