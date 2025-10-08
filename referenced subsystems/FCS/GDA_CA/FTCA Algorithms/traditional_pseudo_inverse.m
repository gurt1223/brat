%% Traditional (Moore–Penrose) Pseudoinverse FTCA
% DESCRIPTION:
%   Computes the actuator commands using the classical Moore–Penrose pseudoinverse method.
%   This approach directly solves the linear equation:
%
%       CB*u = tau
%
%   yielding the least–squares solution without enforcing actuator saturation limits.
%
% INPUTS:
%   tau - Desired virtual control command [p x 1] [rad/s^2].
%   CB  - Control effectiveness matrix [p x m].
%
% OUTPUTS:
%   u   - Computed actuator command vector [m x 1] [rad].
%
% WRITTEN BY:
%   Garrett D. Asper <garrettasper@vt.edu>
%
% HISTORY:
%   20250211 - Created by GDA
%
% REFERENCES:
%

function u = traditional_pseudo_inverse(tau, CB)
    u = pinv(CB) * tau;
end
