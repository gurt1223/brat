function u = quad_prog_sign(tau_cmd, B_raw,lamVec, u_min, u_max, u_pref, u_prev, zero_tol, Qsigma)
%% quad_prog_sign_refined
% DESCRIPTION:
%   Sign-Preserving Quadratic Programming for control allocation, based on
%   the approach in Simmons & Hodel (2004) for the X-33. Each commanded axis 
%   gets its own scalar sigma_i ∈ [0,1], preserving that axis's sign but 
%   allowing the magnitude to shrink if needed. 
%
%   We solve the QP:
%
%      minimize_{u, sigma}  0.5 * ||CB*u - diag(sigma)*tau_cmd||^2
%                           + 0.5 * Qsigma * sum_{i=1}^n (1 - sigma_i)^2
%
%      subject to: 
%          CB*u = diag(sigma)*tau_cmd
%          u_min <= u <= u_max
%          0 <= sigma_i <= 1
%
%   where Qsigma > 0 is a weighting factor that penalizes deviations of each
%   sigma_i from 1. Larger Qsigma => keep sigma_i ≈ 1 more strongly unless 
%   we must scale down for feasibility.
%
% INPUTS:
%   tau_cmd  - Desired command, n×1 (e.g. [roll; pitch; yaw]).
%   CB       - Control effectiveness matrix, size [n×m].
%   u_min    - Actuator lower bounds, m×1.
%   u_max    - Actuator upper bounds, m×1.
%   u_pref   - Prefered actuator positions, mx1.
%   Qsigma   - Scalar weighting on (1 - sigma_i)^2 (e.g. 1e4).
%
% OUTPUTS:
%   u        - Computed actuator command, m×1. If QP is infeasible, returns [].
%
% WRITTEN BY:
%   (Your Name / Date)
%
% REFERENCES:
%   [1] Simmons & Hodel, "Control Allocation for the X-33 using Existing 
%       and Novel Quadratic Programming Techniques," ACC 2004.
%   [2] Bodson, "Evaluation of Optimization Methods for Control Allocation,"
%       J. Guidance, Control, and Dynamics, 25(4), 2002.

% Create effective B matrix
    B_eff = B_raw*diag(lamVec);

    % Basic dimensions
    [n, m] = size(B_eff);      % n = dimension of tau, m = # of actuators
    if length(tau_cmd) ~= n
        error('tau_cmd must match the row-dimension of CB.');
    end

    % Dimensions: tau_cmd is [p x 1] and CB is [p x m]
    p = size(B_eff,2);    % 11
    q = size(B_eff,1);    % 3

    if norm(tau_cmd) < zero_tol
         u = u_prev;
    else

    % We create decision variables:
    %   x = [ u(1..m);  sigma(1..n) ],
    % for a total of (m + n) unknowns.
    %
    % The equality constraint is:  CB * u - diag(tau_cmd) * sigma = 0.
    % So Aeq is n×(m+n). 
    % For row i:
    %   Aeq(i, 1..m) = row i of CB
    %   Aeq(i, m+i)  = - tau_cmd(i)
    %
    % beq = 0 (n×1).

    nVars = m + n;  % # of unknowns
    Aeq   = zeros(n, nVars);
    for i = 1:n
        Aeq(i,1:m)       = B_eff(i,:);      % portion for u
        Aeq(i,m + i)     = -tau_cmd(i);  % portion for sigma_i
    end
    beq = zeros(n,1);

     % Build the starting point for the algorithm using u_pref
    u_pref_clamped = max(min(u_pref, u_max), u_min);

    % Build the initial guess x0:
    x0 = zeros(nVars, 1);
    x0(1:m) = u_pref_clamped;   % the first m elements are 'u'
    x0(m+1:end) = 1;            % the next n elements are 'sigma_i'

    % Next, set up the cost function. We have two parts:
    %
    %  (1) 0.5 * || CB*u - diag(sigma)*tau_cmd ||^2 
    %      => 0.5 * e^T e,  where e = [CB , -diag(tau_cmd)] * [u; sigma].
    %  (2) 0.5 * Qsigma * sum_{i=1..n} (1 - sigma_i)^2
    %
    % Combine into a standard QP form:
    %     0.5*x^T H x + f^T x   with H >= 0, 
    % by building H and f.

    % --- Part (1): e = M*x => M is n×(m+n). Minimizing 0.5*e^T e => 0.5*x^T(M^T M)x.
    M = Aeq;  % because Aeq * x = CB*u - diag(tau_cmd)*sigma
              % Minimizing that to zero is the same as (CB*u = diag(sigma)*tau_cmd).
    MtM = M' * M;

    % --- Part (2):  0.5 * Qsigma * sum((1 - sigma_i)^2 ) 
    % =>  0.5 * Qsigma * sum( sigma_i^2 ) 
    %     - Qsigma * sum( sigma_i ) 
    %     + 0.5 * Qsigma * n   (constant)
    % 
    % So we add Qsigma/2 to diagonal of H for each sigma_i. 
    % We add -Qsigma to f for each sigma_i.

    H = MtM;                     % Start from e^T e
    f = zeros(nVars,1);         % Start from zero
    
    % Original Qsigma logic
    % for i = 1:n
    %     idx = m + i;  % sigma_i index
    %     H(idx, idx) = H(idx, idx) + (Qsigma/2);
    %     f(idx)      = f(idx) - Qsigma;  % linear term -Qsigma * sigma_i
    % end

    % Auto Qsigma logic
    for i = 1:n
        qi = Qsigma(min(i,end));      % if scalar, min→1; if vector, picks Qsigma(i)
        idx = m + i;
        H(idx,idx) = H(idx,idx) + qi/2;
        f(idx)     = f(idx)     - qi;
    end

    % Also note that adding a constant doesn't affect the minimization,
    % so we ignore the 0.5*Qsigma*n offset.

    % Now define lb, ub for x = [u; sigma]
    lb = [-inf(m,1);  zeros(n,1)];
    ub = [ inf(m,1);  ones(n,1)];
    lb(1:m) = u_min;
    ub(1:m) = u_max;

    % Check for offline actuators
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

    % Solve the QP: min( 0.5*x^T H x + f^T x ), subject to Aeq x = 0 and lb <= x <= ub.
    %opts = optimoptions('quadprog','Display','off','Algorithm','interior-point-convex');
    opts = optimoptions('quadprog','Display','off','Algorithm','active-set');
    xOpt = quadprog(H, f, [], [], Aeq, beq, lb, ub, x0, opts);

    % Extract the actuator commands from x
    u = xOpt(1:m);

    % That’s it. The eq. constraint ensures sign-preserving scaling: 
    %  B_eff * u == diag(sigma)*tau_cmd  with 0 <= sigma_i <= 1.
    end
end
