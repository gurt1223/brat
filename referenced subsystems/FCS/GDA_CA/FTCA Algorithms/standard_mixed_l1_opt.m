%% Mixed L_1 Optimization (Using Linprog)
% DESCRIPTION:
%   Solves the mixed l_1 optimization control allocation problem via linear programming,
%   following the formulation in Bodson (2002). The method minimizes both the control
%   error and the deviation from a preferred control vector u_pref, by solving:
%
%       J = ||CB*u - tau_cmd||_1 + epsilon * ||u - u_pref||_1
%
%   where epsilon is a scalar weighting the control minimization term. The LP is constructed
%   using slack variables:
%       - e⁺ and e⁻ to represent positive and negative error components (CB*u - tau_cmd),
%       - u⁺ and u⁻ to represent actuator deviations from u_pref.
%
%   Subject to:
%       CB*u = tau_cmd + e⁺ - e⁻,
%       u = u_pref + u⁺ - u⁻,
%       0 ≤ e⁺ ≤ e_max,    0 ≤ e⁻ ≤ e_max,
%       0 ≤ u⁺ ≤ u_max - u_pref,
%       0 ≤ u⁻ ≤ u_pref - u_min.
%
%   The optimization is solved using bounded-simplex LP with equality constraints.
%
% INPUTS:
%   tau_cmd   - Desired virtual control vector [q x 1] [unitless or rad/s^2].
%   B_raw     - Linear control effectiveness matrix [q x m].
%   lamVec    - Scaling vector for each actuator effectiveness (0: offline <==> 1: online) [m x 1].
%   u_min     - Lower bounds on actuator commands [m x 1] [rad].
%   u_max     - Upper bounds on actuator commands [m x 1] [rad].
%   u_pref    - Preferred actuator command [m x 1] [rad].
%   epsilon   - Weighting parameter (unitless) for control effort regularization.
%   zero_tol  - Tolerance when norm(tau_cmd) < zero_tol, u_opt = zeros
%               (necessary for LP solvers).
%
% OUTPUTS:
%   u         - Computed actuator command vector [m x 1] [rad].
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

function u = standard_mixed_l1_opt(tau_cmd, B_raw, lamVec, u_min, u_max, u_pref, u_prev, epsilon, zero_tol)
     % Suppress singularity warnings
    oldWarnState = warning('off','MATLAB:nearlySingularMatrix');
    cleanupObj = onCleanup(@() warning(oldWarnState));

    % Ensure inputs are formatted correctly
    tau_cmd = tau_cmd(:); u_min = u_min(:); u_max = u_max(:);

    % Create effective B matrix
    B_eff = B_raw*diag(lamVec);

    % Dimensions: tau_cmd is [p x 1] and CB is [p x m]
    p = size(B_eff,2);    % 11
    q = size(B_eff,1);    % 3

    if norm(tau_cmd) < zero_tol
        u = u_prev;
    else
    
    Iq = eye(q);       % 3x3 identity
    Aeq = [ Iq, -Iq, -B_eff,  B_eff ];   % 3x(3+3+11+11) = 3x28
    beq = B_eff*u_pref - tau_cmd;     % 3x1

    c = [ ones(q,1);
      ones(q,1);
      epsilon*ones(p,1);
      epsilon*ones(p,1) ];    
    
    % Compute e_max (see Bodson) but it's basically an error bound
    % Example: e_max = norm(CB*u_pref - a_d,1) from below [40] in Bodson
    % 2002
    e_max = norm(B_eff*u_pref-tau_cmd,1);

    init_e_plus  = e_max*ones(q,1);      % 3x1
    init_e_minus = e_max*ones(q,1);      % 3x1
    init_u_plus  = u_max-u_pref;         % 11x1
    init_u_minus = u_pref-u_min;         % 11x1

    h = [init_e_plus; init_e_minus; init_u_plus; init_u_minus];

    % Bounds: u_min <= u <= u_max, z >= 0, y >= 0
    ub = h;
    lb = zeros(size(ub));
    
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

    % Replace custom simplex with linprog
    options = optimoptions('linprog', ...
        'Algorithm','interior-point', ...
        'Display','none');
    [x, ~, exitflag] = linprog(c, [], [], Aeq, beq, lb, ub, options);
    if exitflag <= 0
        error('linprog did not converge (exitflag = %d)', exitflag);
    end

    
    % Pull the optimized control input
    e_plus  = x(1:q);
    e_minus = x(q+1:2*q);
    u_plus  = x(2*q+1:2*q+p);
    u_minus = x(2*q+p+1 : end);
    
    u = u_pref + u_plus - u_minus;
    end
end

function y = s(x)
% s(x): returns x if x > 0, else returns 0
y = max(x, 0);
end

