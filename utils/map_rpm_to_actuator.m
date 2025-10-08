function actuator_cmd = map_rpm_to_actuator(rpm_min, rpm_max, rpm_cmd)
% Map RPM to Actuator Command Range
%
% DESCRIPTION: 
%   This function maps a given RPM command, typically within a specified 
%   minimum and maximum RPM range, to a corresponding actuator command 
%   value ranging from 0 to 1. RPM values below the minimum RPM are mapped 
%   to 0, and RPM values above the maximum RPM are mapped to 1. The function 
%   outputs the calculated actuator command values corresponding to the input 
%   RPM values.
%
% INPUTS: 
%   rpm_min       - Minimum RPM value for mapping (scalar)
%   rpm_max       - Maximum RPM value for mapping (scalar)
%   rpm_cmd       - Vector of RPM values to be mapped
%
% OUTPUTS:
%   actuator_cmd  - Vector of mapped actuator command values corresponding 
%                   to the input RPM values
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

    % Initialize units vector with the same size as rpm_cmd
    actuator_cmd = zeros(size(rpm_cmd));
    
    % Check and map each element in rpm_cmd
    for i = 1:length(rpm_cmd)
        if rpm_cmd(i) < rpm_min 
            actuator_cmd(i) = 0;
        elseif rpm_cmd(i) > rpm_max
            actuator_cmd(i) = 1;
        else
            % Map the input RPM to a value between 0 and 1
            actuator_cmd(i) = (rpm_cmd(i) - rpm_min) / (rpm_max - rpm_min);
        end
    end
end
