%% MAP_LIMITS_TO_RAD
% DESCRIPTION: 
%   Converts fault-limited unitless ranges [u_min_lim,u_max_lim] into
%   physical radians using nominal actuator ranges [u_min_rad,u_max_rad].
%   The mapping assumes that [-1,1] -> [u_min_rad,u_max_rad].
%
% INPUTS: 
%   u_min_lim - nx1 vector of fault-limited minima (unitless, in [-1,1])
%   u_max_lim - nx1 vector of fault-limited maxima (unitless, in [-1,1])
%   u_min_rad - nx1 vector of per-surface physical minima [rad]
%   u_max_rad - nx1 vector of per-surface physical maxima [rad]
%
% OUTPUTS:
%   u_min_rad_lim - nx1 vector of fault-limited minima [rad]
%   u_max_rad_lim - nx1 vector of fault-limited maxima [rad]
%
% WRITTEN BY:
%   Garrett D. Asper
%   Virginia Tech
%   Email: garrettasper@vt.edu
%
% HISTORY:
%   2025-09-08 - Created, GDA
%
% NOMENCLATURE:                                  UNITS:
%   Not Applicable                                  Not Applicable.
function [u_min_rad_lim, u_max_rad_lim] = map_limits_to_rad( ...
    u_min_lim, u_max_lim, u_min_rad, u_max_rad)

% Ensure column vectors
u_min_lim = u_min_lim(:);
u_max_lim = u_max_lim(:);
u_min_rad = u_min_rad(:);
u_max_rad = u_max_rad(:);

% Map function: unitless [-1,1] -> [u_min_rad,u_max_rad]
map = @(x,umin,umax) ((x+1)/2) .* (umax-umin) + umin;

% Apply elementwise
u_min_rad_lim = map(u_min_lim, u_min_rad, u_max_rad);
u_max_rad_lim = map(u_max_lim, u_min_rad, u_max_rad);

end
