%% Mixed l_1 Optimization FTCA
% DESCRIPTION:
%   Solves the mixed l_1 optimization control allocation problem via linear programming.
%   The method minimizes the cost function:
%
%       J = ||CB*u - tau_cmd||_1 + epsilon * ||u - u_pref||_1
%
%   where epsilon is a weighting parameter. Absolute values are modeled using slack variables.
%   The LP is formulated by introducing:
%       - z for all R^q such that z_i >= |(CB*u - tau_cmd)_i|, for i = 1,...,q.
%       - y for all R^m such that y_j >= |(u - u_pref)_j|, for j = 1,...,m.
%
%   Subject to:
%       CB*u - tau_cmd <= z,
%      -CB*u + tau_cmd <= z,
%       u - u_pref     <= y,
%      -u + u_pref     <= y,
%       u_min <= u <= u_max,  z >= 0,  y >= 0.
%
% INPUTS:
%   tau_cmd   - Desired virtual control command [p x 1] [rad/s^2].
%   CB        - Control effectiveness matrix [p x m].
%   u_min     - Lower bounds on actuator commands [m x 1] [rad].
%   u_max     - Upper bounds on actuator commands [m x 1] [rad].
%   u_pref    - Preferred actuator command [1 x m] [rad].
%   epsilon   - Weighting parameter (unitless) for the control effort term.
%
% OUTPUTS:
%   u         - Computed actuator command vector [m x 1] [rad].
%
% WRITTEN BY:
%   Garrett D. Asper <garrettasper@vt.edu>
%
% HISTORY:
%   20250211 - Created and debugged by GDA.
%
% REFERENCES:
%   [2] 

function u = mixed_l1_opt(tau_cmd, CB, u_min, u_max, u_pref, epsilon)
    % Ensure inputs are formatted correctly
    tau_cmd = tau_cmd(:); u_min = u_min(:); u_max = u_max(:);

    % Dimensions: tau_cmd is [p x 1] and CB is [p x m]
    p = size(CB,2);    % 11
    q = size(CB,1);    % 3
    
    Iq = eye(q);       % 3x3 identity
    Aeq = [ Iq, -Iq, -CB,  CB ];   % 3x(3+3+11+11) = 3x28
    beq = CB*u_pref - tau_cmd;     % 3x1

    c = [ ones(q,1);
      ones(q,1);
      epsilon*ones(p,1);
      epsilon*ones(p,1) ];    
    
    % Compute e_max (see Bodson) but it's basically an error bound
    % Example: e_max = norm(CB*u_pref - a_d,1) from below [40] in Bodson
    % 2002
    e_max = norm(CB*u_pref-tau_cmd,1);

    init_e_plus  = e_max*ones(q,1);      % 3x1
    init_e_minus = e_max*ones(q,1);      % 3x1
    init_u_plus  = u_max-u_pref;         % 11x1
    init_u_minus = u_pref-u_min;         % 11x1

    h = [init_e_plus; init_e_minus; init_u_plus; init_u_minus];

    % Bounds: u_min <= u <= u_max, z >= 0, y >= 0
    ub = h;
    lb = zeros(size(ub));
    
    options = optimoptions('linprog','Display','none');
    [x,~,exitflag] = linprog(c,[],[],Aeq,beq,lb,ub,options);
    if exitflag <= 0
        error('LP did not converge in mixed_l1_opt.');
    end

    e_plus  = x(1:q);
    e_minus = x(q+1:2*q);
    u_plus  = x(2*q+1:2*q+p);
    u_minus = x(2*q+p+1 : end);
    
    u = u_pref + u_plus - u_minus;

end

function y = s(x)
% s(x): returns x if x > 0, else returns 0
y = max(x, 0);
end

