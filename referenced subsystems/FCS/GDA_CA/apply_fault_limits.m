%% APPLY_FAULT_LIMITS
% DESCRIPTION: 
%   Limits ONE selected surface's allowable command range [u_min, u_max] in
%   unitless [-1,1] by centering a symmetric window of half-width 'fault_intensity'
%   around 'fault_command' when a fault is engaged. Examples with default
%   [-1,1] bounds:
%     fault_command = 0,  fault_intensity = 0.8 -> [-0.8,  0.8]
%     fault_command = -1, fault_intensity = 0.8 -> [-1.0, -0.2] (saturates at -1)
%     fault_intensity = 0                        -> [fault_command, fault_command]
%
% INPUTS: 
%   u_min           - 6x1 vector min per-surface (unitless, typically -1)
%   u_max           - 6x1 vector max per-surface (unitless, typically  1)
%   fault_surface   - scalar index of the surface to fault (1..6, clamped)
%   fault_intensity - scalar in [0,1]; half-width of allowed window
%   fault_engage    - 0=apply fault, nonzero=passthrough
%   fault_command   - scalar in [-1,1]; center of allowed window
%
% OUTPUTS:
%   u_min_lim       - 6x1 vector of (possibly) fault-limited minima (unitless)
%   u_max_lim       - 6x1 vector of (possibly) fault-limited maxima (unitless)
%
% WRITTEN BY:
%   Garrett D. Asper
%   Virginia Tech
%   Email: garrettasper@vt.edu
%
% HISTORY:
%   2025-08-27 - Created, GDA
%   2025-09-08 - Updated for unitless [-1,1] with off-nominal center, GDA
%
% NOMENCLATURE:                                  UNITS:
%   Not Applicable                                  Not Applicable.
function [u_min_lim, u_max_lim] = apply_fault_limits( ...
    u_min, u_max, fault_surface, fault_intensity, fault_engage, fault_command)

% Ensure column vectors
u_min = u_min(:);
u_max = u_max(:);

% Passthrough default
u_min_lim = u_min;
u_max_lim = u_max;

% If not engaging the fault, just return
if fault_engage ~= 1
    return;
end

% Clamp/round inputs
nSurf         = numel(u_min);
fault_surface = min(max(round(fault_surface),1), nSurf);
fi            = max(0, min(1, fault_intensity));
fc            = max(-1, min( 1, fault_command));

% Apply centered window with half-width = fi, then saturate to [u_min, u_max]
i = fault_surface;
proposed_min = fc - fi;
proposed_max = fc + fi;

new_min = max(u_min(i), proposed_min);
new_max = min(u_max(i), proposed_max);

% If clamping inverts the window, collapse to a stuck value near fc
if new_min > new_max
    % Start from fc, clamp to physical bounds, then to intended window
    stuck = min(max(fc, u_min(i)), u_max(i));
    stuck = min(max(stuck, proposed_min), proposed_max);
    new_min = stuck;
    new_max = stuck;
end

u_min_lim(i) = new_min;
u_max_lim(i) = new_max;
end
