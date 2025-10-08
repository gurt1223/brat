function y = map_switches(u,type)
% Map Input Signal to Switch Output Based on Switch Type
%
% DESCRIPTION: 
%   This function maps an input signal to a corresponding output value 
%   based on the specified switch type. The function supports three types 
%   of switches:
%   1. Two-level switch (type = 2): Maps the input to either 0 or 1.
%   2. Three-level switch (type = 3): Maps the input to 0, 1, or 2.
%   3. Knob (type = 100): Maps the input linearly from [-1, 1] to [0, 1].
%
% INPUTS: 
%   u     - Signal value to be mapped (scalar)
%   type  - Switch type (scalar): 
%           2 = Two-level switch
%           3 = Three-level switch
%           100 = Knob (linear mapping)
%
% OUTPUTS:
%   y     - Mapped output value corresponding to the input signal and switch type
% 
% WRITTEN BY:
%   Garrett D. Asper
%   Virginia Tech
%   Email: garrettasper@vt.edu
%
% HISTORY:
%   03 SEP 2024 - Created and debugged, GDA
%
% NOMENCLATURE:                                  UNITS:
%   Not Applicable                                  Not Applicable

if type == 2 % two level switch
    if u <= -.5
        y = 1;
    else
        y = 0;
    end

elseif type == 3 % three level switch
    if u <= -0.5
        y = 2;
    elseif u > -0.5 && u <= 0.5
        y = 1;
    else % when u > 0.5
        y = 0;
    end

elseif type == 100 % knob
    if u < -1
        y = 0; % Lower bound of the mapped range
    elseif u > 1
        y = 1; % Upper bound of the mapped range
    else
        y = (u + 1) / 2; % Linear mapping from [-1, 1] to [0, 1]
    end
else
    y = 0;
end

end
