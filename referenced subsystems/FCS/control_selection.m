function control_selection(Sim, control_name, directory)
    % CONTROL_SELECTION: Selects and loads the control subsystem dynamically based on the provided control_name.
    %
    % INPUTS:
    %   control_name: The name of the control scheme (string).
    %   Sim: The simulation structure containing Sim.name and other necessary fields.
    %   directory: The base directory path for locating control subsystems.
    %
    % OUTPUTS:
    %   None (side effect: modifies the Simulink model's referenced control subsystem).
    %
    % WRITTEN BY:
    %   Garrett D. Asper
    %   Virginia Tech
    %   Email: garrettasper@vt.edu
    %
    % HISTORY:
    %   [Date] - Created and debugged, GDA

    baseControlPath = fullfile(directory, 'Subsystems', 'FCS');

    % Find the folder for the selected control scheme
    controlPath = fullfile(baseControlPath, control_name);
    
    if ~isfolder(controlPath)
        error('Control scheme folder does not exist: %s', control_name);
    end
    
    % List all control folders within the FCS directory
    controlFolders = dir(baseControlPath);
    controlFolders = controlFolders([controlFolders.isdir] & ~startsWith({controlFolders.name}, '.'));

    % Initialize control scheme names and paths
    controlList = cell(length(controlFolders), 1);
    controlPaths = cell(length(controlFolders), 1);
    
    % Loop through the folders to find the .slx files and setup scripts
    for i = 1:length(controlFolders)
        controlFolderName = controlFolders(i).name;   % Folder name is the control scheme name
        controlList{i} = controlFolderName;           % Store control scheme name
        controlPaths{i} = fullfile(baseControlPath, controlFolderName); % Store the full path to the control folder
    end
    
    % Check if the selected control scheme exists within the FCS folder
    if ismember(control_name, controlList)
        % Construct the path to the selected control
        controlIdx = find(strcmp(control_name, controlList));
        selectedControlPath = controlPaths{controlIdx};
        
        % Load the Simulink file and run any setup scripts (if necessary)
        load_system(fullfile(selectedControlPath, [control_name, '.slx']));
        %run(fullfile(selectedControlPath, 'setup_control.m'));  % Uncomment if setup script is added
        
        % Set the control reference in the simulation subsystem
        subsystem = '/FCS_Simulation/Control_Selection';     % Location of Control_Scheme block
        set_param([Sim.name, subsystem], 'ReferencedSubsystem', control_name);
    else
        error('Selected control scheme does not exist: %s', control_name);
    end
end
