clear; clc; 

cd(fileparts(mfilename('fullpath')));

Nr = 4; % Number of rotors
nu = 4; % Number of control inputs

load('Initial RACER Model\RACER_20241111.mat')

A = quad.A;
B = quad.B;

% LQR control law to "stabilize" hover (won't work well in high wind)
%Q = diag(1./[ones(1,3) 30*pi/180*ones(1,2) pi ones(1,3) 30*pi/180*ones(1,3) 50*ones(1,Nr)].^2);
%R = 0.01*eye(nu);

% States: [x, y, z, phi, theta, psi, u, v, w, p, q, r, omega_1, omega_2,
% omega_3, omega_4]
Q = diag(1./[.25*ones(1,3) 30*pi/180*ones(1,2) pi .25 .15 .25 30*pi/180*ones(1,3) 50*ones(1,Nr)].^2);
%R = 0.001*eye(nu);
R = .0001*eye(nu);
K = lqr(A,B,Q,R);

disp('The control gain (K) is as follows:')
disp(K)

save('lqr_k_modified.mat','K')