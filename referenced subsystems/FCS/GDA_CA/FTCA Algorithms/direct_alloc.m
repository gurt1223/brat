%% Direct Allocation FTCA
% DESCRIPTION:
%   Solves the direct allocation problem via linear programming as described in 
%   Ref. [2] The approach finds a scalar ρ and a control vector u such that:
%       CB * u - ρ * tau_cmd = 0,
%       u_min <= u <= u_max,  and  ρ >= 0.
%   The LP is cast to minimize -ρ. If the optimum ρ > 1, the actuator commands u are 
%   normalized by dividing by ρ.
%
% INPUTS:
%   tau_cmd   - Desired virtual control command [p x 1] [rad/s^2].
%   CB        - Control effectiveness matrix [p x m] (p = number of outputs, m = actuators).
%   u_min     - Lower bounds on actuator commands [m x 1] [rad].
%   u_max     - Upper bounds on actuator commands [m x 1] [rad].
%
% OUTPUTS:
%   u         - Computed actuator command vector [m x 1] [rad], satisfying u_min <= u <= u_max.
%
% WRITTEN BY:
%   Garrett D. Asper <garrettasper@vt.edu>
%
% HISTORY:
%   20250211 - Created and debugged by GDA
%
% REFERENCES:
%   [2]

function u = direct_alloc(tau_cmd, CB, u_min, u_max)
    % Ensure inputs are formatted correctly
    tau_cmd = tau_cmd(:); u_min = u_min(:); u_max = u_max(:);

    p = length(u_min); % number of outputs 
    q = length(tau_cmd); % m = size(CB,2) is the number accelerations

    % linprog will not work in this case, so zero control is commanded
    if all(tau_cmd == 0)
        u = zeros(p,1);
    else 
    
    %error('Invest time in making sure the LP setup matches Bodsons paper before working on LinProg again!')
    M = zeros(q-1, q);
    M(:,1) = tau_cmd(2:end);            % First column: a_d(2) to a_d(q)
    for i = 2:q
        M(i-1, i) = -tau_cmd(1);        % Diagonal shifted down: -a_d(1)
    end

    % Decision variable x = [u; rho] (dimension m+1). The cost is to maximize rho
    % by minimizing -rho.
    %f = [zeros(p,1)];
    
    % Equality constraint: CB*u - rho*tau_cmd = 0.
    %Aeq = [CB,-tau_cmd];
    Aeq = M*CB;
    beq = -Aeq*u_min;
    c_transpose = -tau_cmd'*CB;
    c = c_transpose';
    h = u_max - u_min;
    
    % Bounds: u_min <= u <= u_max, and rho >= 0.
    % lb = [u_min];  
    % ub = [u_max];
    lb = zeros(p,1);
    ub = h;

    % Use the way the linear problem (LP) was presented in Ref. [2] for linprog
    opts = optimoptions('linprog','Display','none');
    [x,~,exitflag] = linprog(c,[],[],Aeq,beq,lb,ub,opts);
    if exitflag <= 0
        error('LP did not converge in direct_alloc_simplex.');
    end
    
    % Pull the optimized control input
    u_opt   = x(1:p)+u_min;
    rho_opt = (tau_cmd'*CB*u_opt)/(norm(tau_cmd)^2);
    
    % Normalize if rho_opt > 1.
    if rho_opt > 1
        u = u_opt/rho_opt;
    else
        u = u_opt;
    end
    end
end
