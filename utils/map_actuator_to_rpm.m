function rpm_cmd = map_actuator_to_rpm(rpm_min, rpm_max, actuator_cmd)
% Map Actuator Command to RPM Range
%
% DESCRIPTION: 
%   This function maps a given actuator command, typically ranging from 0 
%   to 1, to a corresponding RPM value within a specified minimum and maximum 
%   RPM range. Commands below 0 are mapped to the minimum RPM, and commands 
%   above 1 are mapped to the maximum RPM. The function outputs the calculated 
%   RPM values corresponding to the input actuator commands.
%
% INPUTS: 
%   rpm_min       - Minimum RPM value for mapping (scalar)
%   rpm_max       - Maximum RPM value for mapping (scalar)
%   actuator_cmd  - Vector of actuator commands (0 to 1)
%
% OUTPUTS:
%   rpm_cmd       - Vector of mapped RPM values corresponding to actuator commands
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

    % Initialize rpm_cmd vector with the same size as actuator_cmd
    rpm_cmd = zeros(size(actuator_cmd));
    
    % Check and map each element in actuator_cmd
    for i = 1:length(actuator_cmd)
        if actuator_cmd(i) < 0
            rpm_cmd(i) = rpm_min;
        elseif actuator_cmd(i) > 1
            rpm_cmd(i) = rpm_max;
        else
            % Map the actuator command (0 to 1) to the RPM range
            rpm_cmd(i) = actuator_cmd(i) * (rpm_max - rpm_min) + rpm_min;
        end
    end
end
