function combineMatFiles(destinationFile)

% Combine Multiple MAT Files into Timetables and Save to Destination File
%
% DESCRIPTION: 
%   This function loads a predefined list of .mat files, converts their 
%   data into timetables, processes specific files for additional operations 
%   like renaming and splitting variables, and saves the processed data back 
%   into .mat files. The function then copies the last processed file into a 
%   user-specified destination file and optionally deletes the original .mat files.
%
% INPUTS: 
%   destinationFile  - Name of the file to save the last processed .mat file as
%
% OUTPUTS:
%   The function does not return any outputs. However, it generates new 
%   .mat files based on the processed timetables and creates a copy of the 
%   last processed file with the specified destination file name.
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


% List of .mat files to load and convert to timetables
matFiles = {'sensor_combined.mat', 'esc_status.mat', ...
    'vehicle_local_position.mat', 'vehicle_attitude.mat',...
    'vehicle_angular_velocity.mat', ...
    'input_rc.mat','fcs_signals.mat'}; % 'fcs_data.mat'

% Loop through each .mat file
for i = 1:length(matFiles)
    % Load the .mat file
    loadedData = load(matFiles{i});

    % For each file, create a new timetable
    combinedTimetable = timetable();

    % Convert each field to a timetable and save it separately
    fields = fieldnames(loadedData);
    for j = 1:numel(fields)
        % Check if the field itself is a timeseries object
        if isa(loadedData.(fields{j}), 'timeseries')
            % Convert the timeseries to timetable
            tempTimetable = timeseries2timetable(loadedData.(fields{j}));
            combinedTimetable = [combinedTimetable, tempTimetable]; % Concatenate horizontally
        % If the field is not a timeseries, check if it has subfields that are timeseries
        elseif isstruct(loadedData.(fields{j}))
            subfields = fieldnames(loadedData.(fields{j}));
            for k = 1:numel(subfields)
                if isa(loadedData.(fields{j}).(subfields{k}), 'timeseries')
                    % Convert the subfield timeseries to timetable
                    tempTimetable = timeseries2timetable(loadedData.(fields{j}).(subfields{k}));
                    combinedTimetable = [combinedTimetable, tempTimetable]; % Concatenate horizontally
                end
            end
        end
    end

    % Check if we are working with the esc_status file
    if strcmp(matFiles{i}, 'esc_status.mat')
        % Assume the RPM data is in a single variable named 'RPM'
        if any(strcmp('RPM', combinedTimetable.Properties.VariableNames))
            RPMData = combinedTimetable.RPM; % Extract the RPM data
            % Split the RPM data into individual variables
            for rpmIndex = 0:3
                fieldName = ['esc[', num2str(rpmIndex), '].esc_rpm']; % This will create a character vector
                combinedTimetable.(fieldName) = RPMData(:, rpmIndex+1);
            end
            % Remove the original RPM variable
            combinedTimetable.RPM = [];
        else
            error('The RPM data is not present in the expected format.');
        end
    end

    % Check if we are working with sensor_combined and if so rename the
    % time column
    if strcmp(matFiles{i}, 'sensor_combined.mat')
        % Rename 'Time' column to 'timestamp'
        combinedTimetable.Properties.DimensionNames{1} = 'timestamp';
    end

    % Check if we created a non-empty timetable
    if ~isempty(combinedTimetable)
        % Prepare a structure with the desired name
        S.(strrep(matFiles{i}, '.mat', '')) = combinedTimetable;

        % Save the combined timetable to a .mat file with the same base name as the original file
        save(strrep(matFiles{i}, '.mat', ''), '-struct', 'S');
    end
end

% Copy the last file in the list to a new file
sourceFile = matFiles{end}; % Define the source file name
copyfile(sourceFile, destinationFile); % Copy the file

% Optionally delete the original .mat files after conversion
for i = 1:length(matFiles)
    delete(matFiles{i});
end

% Clear the workspace variables
clear combinedTimetable fields i j k loadedData matFiles S sourceFile subfields tempTimetable destinationFile

end