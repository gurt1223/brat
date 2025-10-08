% Automatically generate "module.yaml" from an XLSX file with custom parameters
% GDA, 8/17/24

function generate_yaml()

clear; clc;

% Startup text for the user
disp([' ', newline, repmat('*', 1, 66), newline, ' '])
disp(['Beginning module.yaml file autocode ...', newline])

% Define paths
script_path = fileparts(mfilename('fullpath'));
% 1 - Racer, 2 - Dragon, 3 - CZ150 6, 4 - eSPAARO 5
% Define available vehicles
vehicle.cases = {'RACER', 'Dragon', 'CZ150_6','eSPAARO_5'};

% Display vehicle options and prompt user for selection
fprintf('Available Vehicles: \n');
for ii = 1:length(vehicle.cases)
    fprintf('   %i. %s\n', ii, vehicle.cases{ii});
end
vehicle_type = input('Select the vehicle: ');
if vehicle_type == 1 || vehicle_type == 2
    xlsx_filename = fullfile(script_path, 'Custom_PX4_Parameters.xlsx');
elseif vehicle_type == 3
    xlsx_filename = fullfile(script_path, 'Custom_PX4_Parameters_CZ1506.xlsx');
elseif vehicle_type == 4
    xlsx_filename = fullfile(script_path, 'Custom_PX4_Parameters_eSPAARO5.xlsx');
else
    error('Invalid vehicle selection.')
end

default_yaml_filename = fullfile(script_path, 'module_original.yaml');
output_yaml_filename = fullfile(script_path, 'module.yaml');

% Ensure the file is not locked by trying to open it for writing
fileID = -1;
while fileID == -1
    [fileID, errmsg] = fopen(xlsx_filename, 'a');
    if fileID == -1
        error('The custom parameter excel sheet is locked by another process. Please manually save and close the file, and run the script again.');
    end
    fclose(fileID); % close the file once the check is complete
end

% Load table with GCS parameters, ensuring text is read correctly
import_opts = detectImportOptions(xlsx_filename, 'PreserveVariableNames', true);
import_opts = setvartype(import_opts, 'Default_Values', 'char');
params_table = readtable(xlsx_filename, import_opts);

% Trim rows with empty parameter names
params_table = params_table(~cellfun('isempty', params_table.Parameter), :);

% Trim rows with all NaN values in critical numerical fields
params_table = params_table(~all(isnan(params_table{:, {'Min', 'Max', 'Decimal'}}), 2), :);

% Read the default YAML content
default_yaml_text = readlines(default_yaml_filename);

% Open output YAML file
output_file = fopen(output_yaml_filename, 'w');

% Write default YAML content to output
fprintf(output_file, '%s\n', default_yaml_text{:});

% Track previous group to handle group changes
previous_group = '';

% Process each parameter in the table
for row = 1:height(params_table)
    % Extract current row data
    param_name = params_table.Parameter{row};
    display_name = params_table.Short_Description{row};
    description = params_table.Long_Description{row};
    data_type = lower(params_table.Data_Type{row});
    value = params_table.Default_Values{row};
    min_val = params_table.Min(row);
    max_val = params_table.Max(row);
    decimal_places = params_table.Decimal(row);
    group_name = params_table.Group{row};

    % Handle vector values
    is_vector = startsWith(value, '[') && endsWith(value, ']');
    if is_vector
        vector_values = str2num(value(2:end-1)); %#ok<ST2NM>
        num_instances = numel(vector_values);
    end

    % Validate parameter name length
    if strlength(param_name) > 16
        error('PX4 Parameter Generation Anomaly: Parameter %s exceeds the maximum character length of 16', param_name);
    end

    % Error check for decimal places
    if decimal_places > 3 || decimal_places < 0
        error('PX4 Parameter Generation Anomaly: Decimal places must be a positive integer that is less than 3 for parameter: %s', param_name);
    end

    % Error check for short description length
    if strlength(display_name) > 40
        error('PX4 Parameter Generation Anomaly: Short description exceeds 40 characters for parameter: %s', param_name);
    end

    % Error check for long description length
    if strlength(description) > 200
        error('PX4 Parameter Generation Anomaly: Long description exceeds 200 characters for parameter: %s', param_name);
    end

    % Error check if min and max values
    if min_val >= max_val
        error('PX4 Parameter Generation Anomaly: Minimum value exceeds maximum value for parameter: %s', param_name);
    end

    % Map data types
    switch data_type
        case 'single'
            data_type = 'float';
        case 'integer'
            data_type = 'int32';
        case 'enum'
            % Do nothing; 'enum' is already correct
        otherwise
            error('PX4 Parameter Generation Anomaly: Unsupported data type: %s for parameter: %s', data_type, param_name);
    end

    % Handle group changes
    if ~strcmp(group_name, previous_group)
        if row > 1, fprintf(output_file, '\n'); end
        fprintf(output_file, '    - group: %s\n      definitions:\n', group_name);
        previous_group = group_name;
    end

    % Write parameter details to YAML
    param_template = '        %s:\n            description:\n                short: %s\n                long: |\n                    %s\n            type: %s\n';
    fprintf(output_file, param_template, param_name, display_name, description, data_type);

    % Handle specific cases for 'enum', vectors, and decimals
    if strcmp(data_type, 'enum')
        enum_values = strsplit(description, '&');
        fprintf(output_file, '            values:\n');
        for ev = 1:numel(enum_values)
            fprintf(output_file, '              %s\n', strtrim(enum_values{ev}));
        end
        fprintf(output_file, '            default: %s\n', value);
    else
        if decimal_places ~= 0
            fprintf(output_file, '            decimal: %d\n', decimal_places);
        end
        if is_vector
            vector_str = sprintf('%.3g,', vector_values);
            vector_str = ['[', vector_str(1:end-1), ']'];
            fprintf(output_file, '            num_instances: %d\n            instance_start: 1\n            default: %s\n', num_instances, vector_str);
        else
            fprintf(output_file, '            default: %s\n', value);
        end
        if ~isnan(min_val)
            fprintf(output_file, '            min: %g\n', min_val);
        end
        if ~isnan(max_val)
            fprintf(output_file, '            max: %g\n', max_val);
        end
    end
end

% Close file and print success message
fclose(output_file);
disp('Custom YAML parameter file successfully created on the path:')
disp(output_yaml_filename);

disp(' ');
disp('Place the newly generated module.yaml file on the path:');
disp('<PX4_Repository_Name>/src/modules/battery_status');
disp([' ', newline, repmat('*', 1, 66), newline, ' '])

end