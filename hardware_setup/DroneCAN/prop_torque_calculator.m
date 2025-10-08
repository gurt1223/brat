clear;clc

diameter = 0.254; % diameter meters
rho = 1.2; % fluid density (kg/m^3)
%ang_vel_rad = 220; % angular velocity (rad/s)
ang_vel_rpm = 5000; % angular velocity (RPM)
ang_vel_rad = ang_vel_rpm*((2*pi)/60);

% Known torque (N*m)
torque = .057; % 

% Rearrange to solve for torque coefficient
torque_coeff = (torque / (rho*(diameter^5)*(1/(4*pi^2))*ang_vel_rad^2))

% diameter = 0.89; % diameter meters
% rho = 1.2; % fluid density (kg/m^3)
% %ang_vel_rad = 220; % angular velocity (rad/s)
% ang_vel_rpm = 2100.85; % angular velocity (RPM)
% ang_vel_rad = ang_vel_rpm*((2*pi)/60);
% 
% % Known torque (N*m)
% torque = 2.653502; % 
% 
% % Rearrange to solve for torque coefficient
% torque_coeff = (torque / (rho*(diameter^5)*(1/(4*pi^2))*ang_vel_rad^2))

% MOI Calc

D = 10
% where D is the prop diameter

% Second order function based on other APC data
MOI = vpa((2.09309392e-5)*D^2-(5.68674033e-4)*D+(4.20300000e-3))
