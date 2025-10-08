%% Weighted Pseudoinverse (WPI) FTCA
% DESCRIPTION:
%   Implements the Weighted Pseudoinverse (WPI) control allocation method. The algorithm
%   computes actuator commands as:
%
%       u = W^(-1) * CB' * pinv(CB*W^(-1)*CB') * tau
%
%   where W is a diagonal weighting matrix that can be used to emphasize or de‐emphasize 
%   certain actuators. Note that this function does not enforce actuator saturation limits.
%
% INPUTS:
%   tau           - Desired virtual control command [p x 1] [rad/s^2].
%   CB            - Control effectiveness matrix [p x m].
%   weight_matrix - Diagonal weighting matrix [m x m] (unitless).
%
% OUTPUTS:
%   u             - Computed actuator command vector [m x 1] [rad].
%
% WRITTEN BY:
%   Garrett D. Asper <garrettasper@vt.edu>
%
% HISTORY:
%   20250211 - Created and debugged by GDA
%
% REFERENCES:
%

function u = WPI(tau, CB, weight_matrix)
    
    % Compute the inverse of the weighting matrix
    W_inv = inv(weight_matrix);
    
    % Compute the weighted pseudoinverse solution
    CB_wpi = CB * W_inv;
    u = W_inv*CB'*pinv(CB_wpi*CB')*tau;

end
