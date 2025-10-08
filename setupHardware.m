%% NSL Vehicle Hardware Setup Script
% DESCRIPTION: 
%   This script initializes and loads the hardware deployment environment 
%   for supported NSL vehicles. The script allows users to select the desired 
%   vehicle and setup case, adding the necessary paths, and then loads the 
%   appropriate Simulink model for simulation or hardware deployment.
%
% INPUTS: 
%   User inputs are required for selecting the vehicle and setup case.
%
% OUTPUTS:
%   The script loads the corresponding Simulink model and configures it based 
%   on the selected setup case. No direct outputs are returned.
% 
% WRITTEN BY:
%   Garrett D. Asper & Patrick E. Corrigan
%   Virginia Tech
%   Email: garrettasper@vt.edu & patrickcorrigan@vt.edu
%
% HISTORY:
%   N/A
%
% NOMENCLATURE:                                  UNITS:
%   Not Applicable                                  Not Applicable

clear; clc;

cd(fileparts(mfilename('fullpath')));

% Command window text
disp([' ', newline, repmat('*', 1, 66), newline, ' '])
disp(['Welcome to the hardware deployment environment', newline, ...
    'developed by the Nonlinear Systems Lab.', newline])
disp([repmat('-', 1, 66), newline])
disp(['First, select the desired vehicle.', newline, ' '])

% Define available vehicles
vehicle.cases = {'RACER', 'Dragon', 'CZ150_6','eSPAARO_5'};

% Display vehicle options and prompt user for selection
fprintf('Available Vehicles: \n');
for ii = 1:length(vehicle.cases)
    fprintf('   %i. %s\n', ii, vehicle.cases{ii});
end
vehicle.type = input('Select Vehicle: ');
disp([newline, repmat('-', 1, 66), newline])

% Setup cases
disp(['Next, select the desired setup case.', newline, ' '])

Setup.cases = {
    'Custom FCS with Logging'
    'Custom FCS without Logging'
};

% Display setup cases and prompt user for selection
fprintf('Available Setup Cases: \n');
for ii = 1:length(Setup.cases)
    fprintf('   %i. %s\n', ii, Setup.cases{ii});
end
Setup.type = input('Select Setup Case: ');
disp(' ')

disp([newline, repmat('-', 1, 66), newline])

% Select if enabling custom control allocation
disp(['Finally, enable or disable custom control allocation.', newline, ' '])

disp(['Available Control Allocation Selections:', ...
    newline, '   0. Disable Custom Control Allocation (Default to Stock PX4 Mixing)', ...
    newline, '   1. Enable Custom Control Allocation'])
enable_alloc = input('Select Answer: ');
disp([newline, repmat('-', 1, 66), newline])

if enable_alloc ~= 0 && enable_alloc ~= 1
    error('Invalid control allocation selection. Either select Enabled/Disabled')
end

% Add current folder and subfolders to path
currentDir = pwd(); % Get the current folder
addpath(genpath(currentDir)); % Add the current folder and subfolders to path

% Load vehicle-specific configurations
switch vehicle.type
    case 1  % RACER
        RACER
        Setup.vehicleName = 'RACER';
        % Diagram names
        Setup.FCS_Flight = 'FCS_flight';
        FW_type = 0;
    case 2  % Dragon
        error('The dragon is not yet supported.')
        Dragon
        Setup.vehicleName = 'Dragon';
        FW_type = 0;
    case 3
        CZ1506
        Setup.vehicleName = 'CZ1506';
        % Diagram names
        Setup.FCS_Flight = 'FCS_flight_Fixed_Wing';
        FW_type = 1; % for CZ150 6
    
    case 4
        eSPAARO5
        Setpu.vehicleName = 'eSPAARO5';

        % Diagram names
        Setup.FCS_Flight = 'FCS_flight_Fixed_Wing';
        FW_type = 2; % for eSPAARO 5

    otherwise
        error('Invalid vehicle selection.');
end

% Execute based on setup type
switch Setup.type

    case {1, 2}  
        config_FCS 

        % Open selected system
        open([Setup.FCS_Flight, '.slx']);

        % Configure logging and GCS settings
        subsystem = '/FCS Out/Write ULOG Data';
        if Setup.type == 1
            set_param([Setup.FCS_Flight, subsystem], 'ReferencedSubsystem', 'Write_ULOG_Data');
        else
            set_param([Setup.FCS_Flight, subsystem], 'ReferencedSubsystem', 'Write_ULOG_Disabled');
        end

        disp("The Simulink model for hardware deployment has loaded successfully.");

    otherwise
        error('Invalid setup type selected.');
end

disp([' ', newline, repmat('*', 1, 66), newline, ' '])