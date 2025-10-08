%% Direct Allocation (Using Linprog)
% DESCRIPTION:
%   Solves the direct allocation control problem via linear programming, as formulated
%   in Bodson (2002). The objective is to maximize the achievable scaling factor rho,
%   defined as:
%
%       rho = ||CB*u|| / ||tau_cmd||
%
%   subject to actuator constraints. The method reformulates the problem as a standard
%   LP with equality constraints (M*CB*u = 0) and bounds (u_min <= u <= u_max), by 
%   eliminating rho through normalization of the command vector tau_cmd.
%
%   The optimization problem is constructed using:
%       Aeq = M*CB,      where M is defined to eliminate rho,
%       beq = -Aeq*u_min,
%       x = u - u_min,   bounded such that 0 <= x <= u_max - u_min.
%
%   The cost function to be minimized is:
%
%       J = -tau_cmd' * CB * u,
%
%   ensuring maximum alignment of CBu with tau_cmd. If rho > 1, the result is 
%   normalized to produce the final control vector.
%
% INPUTS:
%   tau_cmd   - Desired virtual control vector [q x 1] [unitless or rad/s^2].
%   B_raw     - Linear control effectiveness matrix [q x m].
%   lamVec    - Scaling vector for each actuator effectiveness (0: offline <==> 1: online) [m x 1].
%   u_min     - Lower bounds on actuator commands [m x 1] [rad].
%   u_max     - Upper bounds on actuator commands [m x 1] [rad].
%   zero_tol  - Tolerance when norm(tau_cmd) < zero_tol, u_opt = zeros
%               (necessary for LP solvers).
%
% OUTPUTS:
%   u         - Allocated actuator command [m x 1] [rad].
%
% WRITTEN BY:
%   Garrett D. Asper <garrettasper@vt.edu>
%
% HISTORY:
%   20250326 - Created and debugged by GDA.
%
% REFERENCES:
%   [1] M. Bodson, "Evaluation of Optimization Methods for Control Allocation",
%       Journal of Guidance, Control, and Dynamics, Vol. 25, No. 4, 2002.
%
% NOMENCLATURE:                                  UNITS:
%   Not Applicable                                  Not Applicable.


function u = standard_direct_alloc(tau_cmd, B_raw, lamVec, u_min, u_max, u_prev, zero_tol)
    % Suppress singularity warnings
    oldWarnState = warning('off','MATLAB:nearlySingularMatrix');
    cleanupObj = onCleanup(@() warning(oldWarnState));

    % Ensure inputs are formatted correctly
    tau_cmd = tau_cmd(:); u_min = u_min(:); u_max = u_max(:);

    % Create effective B matrix
    B_eff = B_raw*diag(lamVec);

    p = length(u_min); % number of outputs 
    q = length(tau_cmd); % m = size(CB,2) is the number accelerations

    % linprog will not work in this case, so zero control is commanded
    %if norm(tau_cmd) < zero_tol
    if all(abs(tau_cmd) < zero_tol)
        u = u_prev;
    else 
        M = zeros(q-1, q);
        M(:,1) = tau_cmd(2:end);            % First column: a_d(2) to a_d(q)
        for i = 2:q
            M(i-1, i) = -tau_cmd(1);        % Diagonal shifted down: -a_d(1)
        end
    
        % Decision variable x = [u; rho] (dimension m+1). The cost is to maximize rho
        % by minimizing -rho.
        %f = [zeros(p,1)];
        
        % Equality constraint: B_eff*u - rho*tau_cmd = 0.
        Aeq = M*B_eff;
        beq = -Aeq*u_min;
        c_transpose = -tau_cmd'*B_eff;
        c = c_transpose';
        h = u_max - u_min;
        
        % Bounds: u_min <= u <= u_max, and rho >= 0.
        % lb = [u_min];  
        % ub = [u_max];
        lb = zeros(p,1);
        ub = h;
    
        % Identify non-zero columns (columns involved in the constraint)
        % nonzero_cols = find(any(B_eff ~= 0, 1));      % columns with any nonzero values
        % num_actuators = numel(nonzero_cols);   % number of online actuators

        % Preallocate a fixed-size vector (p is the number of columns of B_eff)
        nonzero_cols = zeros(p, 1);
        k = 0;
        for j = 1:p
            % Check if any element in column j is nonzero
            if any(B_eff(:, j) ~= 0)
                k = k + 1;
                nonzero_cols(k) = j;
            end
        end
        num_actuators = k;
    
         % Solve LP using linprog instead of custom simplex
         intmax = 2.1475e9; % match dual-simplex-highs
        options = optimoptions('linprog', ...
        'Algorithm','interior-point', ...
        'Display','none', ...
        'OptimalityTolerance', 1e-7);        % match dual‑simplex‑highs
        [x, fval, exitflag] = linprog(c, [], [], Aeq, beq, lb, ub, options);
        if exitflag <= 0
            warning('linprog did not converge (exitflag = %d)', exitflag);
        end

        % Pull the optimized control input
        u_opt   = x(1:p)+u_min;
        rho_opt = (tau_cmd'*B_eff*u_opt)/(norm(tau_cmd)^2);
        
        % Normalize if rho_opt > 1.
        if (rho_opt) > 1
            u = u_opt/rho_opt;
        else
            u = u_opt;
        end
    end
end

