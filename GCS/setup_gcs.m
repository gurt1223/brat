%% Custom Ground Control Station Setup Script
%
% DESCRIPTION: 
%   This script sets up the environment for a custom ground control station 
%   by adding the current folder and its subfolders to the MATLAB path, 
%   initializing conversion factors, and setting the sample time for the 
%   ground control station. The script also includes a placeholder for 
%   interpreting a DebugArray, which is currently commented out.
%
% INPUTS: 
%   No direct inputs are required. The script runs with predefined parameters.
%
% OUTPUTS:
%   The script initializes the environment and opens the 'GCS' Simulink model.
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

% Ensure the base workspace is the folder where the setup script is
cd(fileparts(mfilename('fullpath')));

% Add current folder and subfolders to path
currentDir = pwd(); % Get the current folder
addpath(genpath(currentDir)); % Add the current folder and subfolders to path

% Populate the virtual bus to interpret the DebugArray
% debug_array_vector_to_bus (commented out for now until I determine a path
% forward)

% Set the sample time of the ground control station
gcs.samp_time = 1/100;      % Sample time
gcs.unit.m2ft = 3.28084;    % Conversion factor for meters to feet
gcs.unit.rad2deg = 180/pi;  % Conversion factor for radians to degrees

open('GCS_Fixed_Wing')