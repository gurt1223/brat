%% Baseline Robust Aircraft Testing (brat) Hardware Setup Script
% DESCRIPTION: 
%   This script initializes and loads the hardware deployment environment 
%   for a generic vehicle with a PX4 autopilot. The script allows users to 
%   set up the Simulink environment that includes pre-built PX4 I/O, 
%   facilitating a clear starting point for custom algorithm hardware-in-
%   the-loop (hitl) bench testing and flight testing. The main Simulink 
%   diagram in this brat repository will be referred to as the Flight 
%   Control System (FCS) throughout the repository.
%
% INPUTS: 
%   User inputs are required for selecting the setup case.
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
disp(['Welcome to the baseline robust aircraft testing (brat) environment.', newline])
disp([repmat('-', 1, 66), newline])

% Setup cases
disp(['Select the desired setup case.', newline, ' '])

Setup.cases = {
    'Connected IO (PX4 Logging Disabled)'
    'Build, Deploy, & Start (PX4 Logging Enabled)'
};

% Display setup cases and prompt user for selection
fprintf('Available Setup Cases: \n');
for ii = 1:length(Setup.cases)
    fprintf('   %i. %s\n', ii, Setup.cases{ii});
end
Setup.type = input('Select Setup Case: ');
disp(' ')

disp([newline, repmat('-', 1, 66), newline])

% Add current folder and subfolders to path
currentDir = pwd(); % Get the current folder
addpath(genpath(currentDir)); % Add the current folder and subfolders to path

% Check user inputs for errors
if Setup.type ~= 1 && Setup.type ~= 2
    error('Invalid setup case.')
end

% Execute based on setup type
switch Setup.type
    case {1, 2}  
        % Name of the main FCS diagram
        Setup.FCS_Hardware = 'FCS_Hardware';

        % Set global sample time for the Simulink logic 
        FCS_var.samp_time = 1/200;

        % Open selected system
        open([Setup.FCS_Hardware,'.slx']);

        % Configure logging and GCS settings
        subsystem = '/FCS Out/Write ULOG Data';
        if Setup.type == 2
            set_param([Setup.FCS_Hardware, subsystem], 'ReferencedSubsystem', 'Write_ULOG_Data');
        else
            set_param([Setup.FCS_Hardware, subsystem], 'ReferencedSubsystem', 'Write_ULOG_Disabled');
        end

        disp("The Simulink model for algorithm deployment on hardware has loaded successfully.");

    otherwise
        error('Invalid setup type selected.');
end

disp([' ', newline, repmat('*', 1, 66), newline, ' '])