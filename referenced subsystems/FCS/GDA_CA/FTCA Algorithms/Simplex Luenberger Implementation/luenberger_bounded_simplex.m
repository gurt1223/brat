%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main Simplex Algorithm
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function x_opt = luenberger_bounded_simplex(A_, b_, c_, lb_, ub_)
% DESCRIPTION:
%   Solves the linear programming (LP) problem
%       minimize    c^T x
%       subject to  A*x = b,  lb <= x <= ub
%   using a revised simplex algorithm that incorporates anti-cycling rules
%   and efficient basis inverse updates. The function also removes “offline”
%   actuators (columns where A is nearly zero) and converts the original problem 
%   into a standard form (via variable transformation) before applying a two-phase 
%   simplex procedure (Phase 1 with artificial variables, then Phase 2 for the real LP).
%
% INPUTS:
%   A_   - m-by-n constraint matrix.
%   b    - m-by-1 right-hand side vector.
%   c_   - n-by-1 cost vector.
%   lb_  - n-by-1 lower bounds on x (s.t. x >= lb_).
%   ub_  - n-by-1 upper bounds on x (s.t. x <= ub_).
%
% OUTPUTS:
%   x_opt - Optimal solution vector (n-by-1). If offline actuators were removed,
%           the returned vector is padded with zeros in those positions.
%
% WRITTEN BY:
%   Garrett D. Asper <garrettasper@vt.edu>
%
% HISTORY:
%   20250326 - Created and debugged.
%
% REFERENCES:
%   [1] Standard texts on linear programming and revised simplex methods.
%   [2] Luenberger, D., "Introduction to Linear and Nonlinear Programming", Addison-Wesley.
%
% NOMENCLATURE:
%   A, b, c   - Standard LP matrices and vectors.
%   lb, ub    - Lower and upper bound vectors.


A = A_; b = b_; c = c_; lb = lb_; ub = ub_;
A_n = size(A_,1); A_m = size(A_,2);

coder.varsize("A", [A_n, A_m], [1, 1]);
%coder.varsize("b", [28, 1], [1, 0]);
coder.varsize("c", [A_m, 1], [1, 0]);
coder.varsize("lb", [A_m, 1], [1, 0]);
coder.varsize("ub", [A_m, 1], [1, 0]);
coder.varsize("b",   [A_n,   1], [1,0]);

%% Check if the right-hand side vector b is all zeros.
if all(b == 0)
    % If b is all zeros, we return the zero vector of appropriate dimension.
    x_opt = zeros(size(A_,2), 1);
    return;
end

%% Preliminary input error checks
if size(A_,1) ~= numel(b)
    error('A and b must have the same number of rows.');
elseif size(A_,2) ~= numel(c_)
    error('A must have the same number of columns as the length of c.');
elseif size(A_,2) ~= numel(lb_) || size(A_,2) ~= numel(ub_)
    error('Dimensions of lb and ub must match number of columns in A.');
end

%% Remove Offline Actuators (columns where A is near zero)
tol_offline = 1e-22;
offlineIdx = find(all(abs(A_) < tol_offline, 1));
onlineIdx = setdiff(1:size(A_,2), sort(offlineIdx));
n_original = size(A_,2);
if ~isempty(offlineIdx)
    A = A_(:, onlineIdx);
    c = c_(onlineIdx);
    lb = lb_(onlineIdx);
    ub = ub_(onlineIdx);
end

% Improved row-redundancy elimination using QR on A'
tol_rank = 1e-14;  % tolerance for determining rank

% Perform QR factorization on A'
[Q, R, E] = qr(A', 0);  % economy QR on the transpose; E indicates the pivoted row indices
diagonalR = abs(diag(R));
r_est = sum(diagonalR > tol_rank);  % estimated rank of A (number of independent rows)

if r_est < size(A,1)
    % The first r_est indices from the permutation E correspond to the independent rows.
    indepRows = sort(E(1:r_est));  % sort for natural ordering, if desired
    depRows   = setdiff(1:size(A,1), indepRows);  % these are the rows that are dependent
    
    % Optionally, keep track of the dropped (dependent) rows:
    Adep = A(depRows, :);
    bdep = b(depRows);
    
    % Reduce A and b to only include the independent rows.
    A = A(indepRows, :);
    b = b(indepRows);
    
    % disp('PRESOLVE: Dropped dependent rows from A (rank-deficient system).');
end


%% 1) Convert problem to standard form:
% Define x' = x - lb, so that x' >= 0, and s = (ub - lb) - x' >= 0.
% Then, our equality constraints become:
%      [A    0] [x']   = b - A*lb    =: b_shifted
%      [I    I] [ s ]   = ub - lb
m = size(A,1);
n = size(A,2);
for i = 1:m
    if b(i) < 0
        A(i,:) = -A(i,:);
        b(i) = -b(i);
    end
end
b_shifted = b - A*lb;
A_aug = [A, zeros(m,n);
         eye(n), eye(n)];
b_aug = [b_shifted;
         (ub - lb)];
c_aug = [c; zeros(n,1)];  % cost only on x' variables

%% 2) Phase 1: Find a basic feasible solution using artificial variables
nrows = m + n;  % number of equations in augmented system
A_phase1 = [A_aug, eye(nrows)];
b_phase1 = b_aug;
c_phase1 = [zeros(size(A_aug,2),1); ones(nrows,1)];
[~, phase1Obj, basisPhase1, tabPhase1] = simplex_solve(A_phase1, b_phase1, c_phase1);
% (Optionally check: if phase1Obj > tol_phase1, then infeasible)
artificialCols = (2*n + 1 : 2*n + nrows);
[basisPhase1, tabPhase1] = pivotOutArtificials(tabPhase1, basisPhase1, artificialCols);

%% 3) Phase 2: Solve the real problem using the BFS from Phase 1
A_phase2 = A_phase1(:,1:(2*n));
c_phase2 = c_aug;
[X_opt, z_opt, basis, final_tableau, B_inv] = simplex_solve_revised(A_phase2, b_phase1, c_phase2, basisPhase1);

%% 4) Recover original variables: x = lb + x', where x' = X_opt(1:n)
xprime = X_opt(1:n);
x_opt = lb + xprime;
if ~isempty(offlineIdx)
    x_full = zeros(n_original, 1);
    x_full(onlineIdx) = x_opt;
    x_opt = x_full;
end

% if ~isempty(offlineIdx)
%     x_check = x_opt(onlineIdx);  % extract the solution for online variables
% else
%     x_check = x_opt;
% end
% 
% if exist('Adep','var') && ~isempty(Adep)
%     if norm(Adep * x_check - bdep, inf) > 1e-7  % pick tolerance
%         warning('Presolve removed rows that are not satisfied by the final solution, possible numerical issues.');
%     end
% end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Revised Simplex Solver 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [Xopt, zopt, basis, final_tab, B_inv] = simplex_solve_revised(A, b, c, initialBasis)
% DESCRIPTION:
%   Solves the LP:
%       minimize    c^T x
%       subject to  A*x = b,  x >= 0
%   using a revised simplex method. This implementation employs Bland’s
%   anti-cycling rule and updates the inverse of the current basis matrix
%   using a Sherman–Morrison type update, thereby improving computational efficiency.
%
% INPUTS:
%   A            - m-by-n constraint matrix.
%   b            - m-by-1 right-hand side vector.
%   c            - n-by-1 cost vector.
%   initialBasis - (Optional) Vector of indices representing the initial basic variables.
%
% OUTPUTS:
%   Xopt     - Optimal solution vector (n-by-1).
%   zopt     - Optimal objective value (scalar).
%   basis    - Final basis indices (vector of length m).
%   final_tab- Final simplex tableau (optional).
%   B_inv    - Inverse of the final basis matrix.
%
% WRITTEN BY:
%   Garrett D. Asper <garrettasper@vt.edu>
%
% HISTORY:
%   20250326 - Created and debugged.
%
% REFERENCES:
%   [1] Luenberger, D., "Introduction to Linear and Nonlinear Programming", Addison-Wesley.
%   [2] Bland's Rule for anti-cycling in the simplex method.

[m, n] = size(A);
if nargin < 4 || isempty(initialBasis)
    basis = (n - m + 1 : n);
else
    basis = initialBasis;
end
[tab, basis] = initial_tableau(A, b, c, basis);

% Initialize basis inverse from current basis:
B = A(:, basis);
B_inv = inv(B);

maxIter = 1000;
tol = 1e-12 * max(norm(c, inf), 1);  % use 1e-12 tolerance for optimality

for iter = 1:maxIter
    % Compute reduced costs directly: r_N = c_N - c_B' * B_inv * N.
    nonBasis = setdiff(1:n, sort(basis));
    if isempty(nonBasis)
        break;
    end
    N = A(:, nonBasis);
    cB = c(basis);
    cN = c(nonBasis);
    rN = cN.' - cB.' * (B_inv * N);
    
    % Build full reduced cost row for all variables
    r = zeros(1, n);
    r(nonBasis) = rN;
    
    % Bland's rule for entering variable: smallest index with r < -tol.
    enteringCandidates = find(r < -tol);
    if isempty(enteringCandidates)
        break;  % Optimal: all reduced costs are non-negative
    end
    colIn = enteringCandidates(1);
    
    % Compute direction vector: y = B_inv * d, where d = A(:, colIn)
    d = A(:, colIn);
    y = B_inv * d;
    
    % Ratio test to choose leaving variable
    ratios = inf(m,1);
    for i = 1:m
        if y(i) > tol  % use separate feasibility tol if desired
            ratios(i) = tab(i+1,end) / y(i);
        end
    end
    [minRatio, leavingIdx] = min(ratios);
    if isinf(minRatio)
        error('Problem is unbounded in that direction (simplex pivot fails).');
    end
    
    % Bland's rule for leaving: if ties, choose smallest index in basis.
    candidateIdx = find(ratios == minRatio);
    if numel(candidateIdx) > 1
        [~, minIdx] = min(basis(candidateIdx));
        leavingIdx = candidateIdx(minIdx);
    end
    
    % --- Revised Simplex Basis Inverse Update using Sherman-Morrison ---
    pivotVal = y(leavingIdx);
    if abs(pivotVal) < tol
        error('Pivot element is too small; basis is nearly singular.');
    end
    % Update the leaving row of B_inv:
    B_inv(leavingIdx, :) = B_inv(leavingIdx, :) / pivotVal;
    % For all other rows, subtract appropriate multiple of the leaving row:
    for i = 1:m
        if i ~= leavingIdx
            B_inv(i, :) = B_inv(i, :) - y(i) * B_inv(leavingIdx, :);
        end
    end
    
    % Update basic solution in tableau:
    % new basic variable index in the basis:
    basis(leavingIdx) = colIn;
    % Update B matrix for next iteration:
    B = A(:, basis);
    
    % Optionally, update the tableau as well.
    % Here, we simply recompute basic solution:
    xB = B_inv * b;
    tab(2:end, end) = xB;
end

final_tab = tab;
Xopt = zeros(n, 1);
Xopt(basis) = B_inv * b;
zopt = c.' * Xopt;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initial Tableau Creation
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [tab, basis] = initial_tableau(A, b, c, basis)
% DESCRIPTION:
%   Constructs the initial simplex tableau for an LP problem in standard form.
%   Given a constraint matrix A, right-hand side vector b, cost vector c, and an 
%   optional initial basis, the function partitions A into basis (B) and nonbasis (N)
%   components and computes the corresponding reduced costs.
%
% INPUTS:
%   A     - m-by-n constraint matrix.
%   b     - m-by-1 right-hand side vector.
%   c     - n-by-1 cost vector.
%   basis - (Optional) Vector of indices for the basic variables.
%
% OUTPUTS:
%   tab   - Initial simplex tableau (matrix) with the cost row and RHS.
%   basis - Updated vector of basic variable indices.
%
% WRITTEN BY:
%   Garrett D. Asper <garrettasper@vt.edu>
%
% HISTORY:
%   20250326 - Created and debugged.
%
% REFERENCES:
%   [1] Standard simplex method literature.

[m, n] = size(A);
if nargin < 4
    basis = (n - m + 1 : n);
end
B = A(:, basis);
Nind = setdiff(1:n, sort(basis));
xB = B \ b;
z0 = c(basis).' * xB;
% Compute reduced costs: r_N = c_N - c_B'*(B\N)
N = A(:, Nind);
rN = c(Nind).' - c(basis).' * (B \ N);
tab = zeros(m+1, n+1);
% Fill cost row (columns 1:n) and RHS (last column)
tab(1, Nind) = rN;
tab(1, end) = -z0;
% Fill the rows for basic variables:
BN = B \ N;
for i = 1:m
    tab(i+1, Nind) = BN(i,:);
    tab(i+1, end) = xB(i);
end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Pivot 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function tab = pivot_on(tab, prow, pcol)
% DESCRIPTION:
%   Performs a pivot operation on the given simplex tableau at a specified pivot
%   position (row and column). The function normalizes the pivot row and then updates
%   all other rows so that the column corresponding to the pivot becomes a unit vector.
%
% INPUTS:
%   tab  - Current simplex tableau (matrix).
%   prow - Pivot row index.
%   pcol - Pivot column index.
%
% OUTPUTS:
%   tab  - Updated simplex tableau after the pivot operation.
%
% WRITTEN BY:
%   Garrett D. Asper <garrettasper@vt.edu>
%
% HISTORY:
%   20250326 - Created and debugged.
%
% REFERENCES:
%   [1] Standard texts on the simplex algorithm.

pv = tab(prow, pcol);
tol_pivot = 1e-30 * max(norm(tab(prow, :), inf), 1);
if abs(pv) < tol_pivot
    error('Pivot element is too close to zero.');
end
tab(prow, :) = tab(prow, :) ./ pv;
for r = 1:size(tab, 1)
    if r ~= prow
        factor = tab(r, pcol);
        tab(r, :) = tab(r, :) - factor * tab(prow, :);
    end
end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Pivot Out Artificial Variables
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [basis, tab] = pivotOutArtificials(tab, basis, artificialCols)
% DESCRIPTION:
%   Systematically removes artificial variables from the current basis in the simplex tableau.
%   For each basic variable corresponding to an artificial column, the function searches for a 
%   suitable nonbasic pivot candidate to replace it while maintaining feasibility.
%
% INPUTS:
%   tab            - Current simplex tableau (matrix).
%   basis          - Current vector of basic variable indices.
%   artificialCols - Indices of columns corresponding to artificial variables.
%
% OUTPUTS:
%   basis - Updated basic variable indices with artificial variables removed.
%   tab   - Updated tableau after pivoting out the artificial variables.
%
% WRITTEN BY:
%   Garrett D. Asper <garrettasper@vt.edu>
%
% HISTORY:
%   20250326 - Created and debugged.
%
% REFERENCES:
%   [1] Techniques for removing artificial variables in two-phase simplex methods.
mPlus1 = size(tab,1);
for iB = 1:length(basis)
    colB = basis(iB);
    if ismember(colB, artificialCols)
        rowB = iB + 1;
        val = tab(rowB, end);
        if abs(val) > .99
            error('Artificial variable in basis has nonzero value => Infeasible system.');
        else
            nonBasic = setdiff(1:(size(tab,2)-1), sort(basis));
            [~, sortIdx] = sort(abs(tab(rowB, nonBasic)), 'descend');
            colCandidates = nonBasic(sortIdx);
            colNB = [];
            for i = 1:length(colCandidates)
                candidate = colCandidates(i);
                if abs(tab(rowB, candidate)) > 1e-30
                    colNB = candidate;
                    break;
                end
            end
            if ~isempty(colNB)
                tab = pivot_on(tab, rowB, colNB);
                basis(iB) = colNB;
            else
                warning('No suitable pivot found for artificial variable removal. Forcing removal.');
                basis(iB) = [];
            end
        end
    end
end
basis(basis < 0) = [];
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Simplex Solver
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [Xopt, zopt, basis, final_tab] = simplex_solve(A, b, c, initialBasis)
% DESCRIPTION:
%   Implements a basic (Phase-2) simplex algorithm to solve the LP:
%       minimize    c^T x
%       subject to  A*x = b,  x >= 0.
%   This function assumes a basic feasible solution is already available (typically
%   derived from Phase 1 using artificial variables) and proceeds by iteratively 
%   selecting entering and leaving variables until optimality is reached.
%
% INPUTS:
%   A            - m-by-n constraint matrix.
%   b            - m-by-1 right-hand side vector.
%   c            - n-by-1 cost vector.
%   initialBasis - (Optional) Vector of indices for the initial basic variables.
%
% OUTPUTS:
%   Xopt      - Final optimal solution vector (n-by-1).
%   zopt      - Final optimal objective value (scalar).
%   basis     - Final basic variable indices (vector of length m).
%   final_tab - Final simplex tableau (matrix).
%
% WRITTEN BY:
%   Garrett D. Asper <garrettasper@vt.edu>
%
% HISTORY:
%   20250326 - Created and debugged.
%
% REFERENCES:
%   [1] Standard simplex algorithm texts.

[m, n] = size(A);

% % If the user passes in an initial basis, use it; otherwise, default to last m columns
% if ~exist('initialBasis','var') || isempty(initialBasis)
%     basis = (n - m + 1 : n);
% else
%     basis = initialBasis;
% end

if nargin < 4 || isempty(initialBasis)
    basis = (n - m + 1 : n);
else
    basis = initialBasis;
end


% Build initial tableau: we partition A = [N | B], x = [xN; xB].
% The BFS is xB = b, xN = 0, cost row = cN - cB B^-1 N.
% We'll do a small routine to get that tableau.

[tab, basis] = initial_tableau(A, b, c, basis);

% --- Main simplex loop ---
maxIter = 1000;  % just a safeguard

for iter = 1:maxIter
    % Define a dynamic tolerance based on the cost vector magnitude
    tol = 1e-25 * max(norm(c, inf), 1);

    % 1) Identify entering variable using Bland's rule:
    % New pivot selection: choose the variable with the most negative reduced cost.
    [minValue, colIn] = min(tab(1, 1:end-1));
    if minValue >= -tol
        break;  % no negative reduced costs => optimal solution
    end
    % (Optionally, if you wish to add a lexicographic tie-breaker, you could further check for multiple columns with similar reduced cost values.)


    % 2) Identify leaving variable by the minimum ratio test:
    ratios = zeros(size(tab, 1) - 1, 1);
    for iRow = 2:size(tab, 1)
        if tab(iRow, colIn) > tol
            ratios(iRow-1) = tab(iRow, end) / tab(iRow, colIn);
        else
            ratios(iRow-1) = inf;
        end
    end
    [minRatio, rowOut_rel] = min(ratios);
    if isinf(minRatio)
        error('Problem is unbounded in that direction (simplex pivot fails).');
    end
    rowOut = rowOut_rel + 1;  % Adjust for cost row index

    % 3) Pivot on (rowOut, colIn)
    tab = pivot_on(tab, rowOut, colIn);

    % Update basis (rowOut-1 corresponds to the correct index in the basis vector)
    basis(rowOut - 1) = colIn;
end


final_tab = tab;

% Extract solution from final tableau:
% The basis columns have xB = tab(2:end, end), the rest 0.
Xopt = zeros(n,1);
for i = 2:size(tab,1)
    col_index = basis(i-1);
    Xopt(col_index) = tab(i,end);
end

% Final cost value = tab(1,end)
zopt = tab(1,end);

end  % end simplex_solve