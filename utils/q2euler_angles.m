function rpy = q2euler_angles(q)
% Convert Quaternion to Euler Angles
%
% DESCRIPTION: 
%   This function converts a given quaternion into corresponding Euler 
%   angles (roll, pitch, yaw) in radians. The function takes a quaternion 
%   as input and calculates the roll, pitch, and yaw angles based on the 
%   quaternion components using standard trigonometric formulas.
%
% INPUTS: 
%   q    - 4-element vector representing the quaternion [q0, q1, q2, q3]
%
% OUTPUTS:
%   rpy  - 3-element vector containing the Euler angles [roll, pitch, yaw] in radians
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
%   roll        - roll angle                          (rad)
%   pitch       - pitch angle                         (rad)
%   yaw         - yaw angle                           (rad)

q0 = q(1); % Quaternion input 0
q1 = q(2); % Quaternion input 1
q2 = q(3); % Quaternion input 2
q3 = q(4); % Quaternion input 3

roll  = atan2(2*q2*q3+2*q0*q1,q3^2-q2^2-q1^2+q0^2);
pitch = -asin(2*q1*q3-2*q0*q2);
yaw   = atan2(2*q1*q2+2*q0*q3,q1^2+q0^2-q3^2-q2^2); 

rpy= zeros(3,1);
rpy(1) = roll;
rpy(2) = pitch;
rpy(3) = yaw;
