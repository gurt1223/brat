function [F,M, H, psi_H, qbar] = aeroModel_MTD(vb,omega,delta,~,~,params)
%aeroModel_eSPAARO_Simplified
%
% Copyright (c) 2024 Jeremy W. Hopwood. All rights reserved.
%
% This is a function implements a simplified version of the eSPAARO
% aerodynamic model identified by Ben Simmons in October of 2022. The time 
% serivative of angle of attack is approximated by pitch rate. The
% aerodynamic model parameters are hard-coded for simplicity.
%
% Inputs:
%
%   vb          A 3 x N array of air-relative body velocity [m/s]
%
%   omega       A 3 x N array of air-relative angular velocity [m/s]
%
%   delta       A 4 x N array of actuator values,
%                   da = aileron [rad]
%                   dL = left ruddervator [rad]
%                   dR = reft ruddervator [rad]
%                   Omega = propeller speed [rad/s]
%
%   params      A struct that is used to pass constants through to the
%               model. The following fields are required in this function:
%                   rho     air density [kg/m^3]
%  
% Outputs:
%
%   F           The 3 x N aero-propulsive force [N]
%
%   M           The 3 x N aerodynamic moment [N*m]
%

% Hard-coded constants
ft2m = 0.3048;
c = (22/12)*ft2m; % mean chord, m
b = 12*ft2m; % wing span, m
S = 22*ft2m^2; % wing planform area, m^2
D = (22/12)*ft2m; % propeller diameter, m

% Enviromental parameters
rho = params.rho;

% Explanatory variables
u = vb(1,:);
v = vb(2,:);
w = vb(3,:);
V = sqrt(u.^2 + v.^2 + w.^2);
alpha = atan2(w,u);
beta = asin(v./V);
p = omega(1,:);
q = omega(2,:);
r = omega(3,:);
delta_a = delta(1,:);
delta_r = delta(2,:);
delta_e = delta(3,:);
Omega = delta(4,:);

% Propeller speed in rev/s
n = Omega/(2*pi);

% Non-dimensional quantities
qbar = 0.5*rho*V.^2;
phat = p*b./(2*V);
qhat = q*c./(2*V);
rhat = r*b./(2*V);

% % Model parameters

C_x_alpha    = +0.299;
C_x_delta_e       = -0.089;
C_x_alpha2   = +0.802;
C_x_0        = -0.064;

C_y_beta     = -0.376;
C_y_p        = +0.628;
C_y_r        = +0.117;
C_y_delta_a  = +0.257;
C_y_delta_r  = +0.155;
C_y_beta3    = -0.325;
C_y_0        =  0.000;

C_z_alpha    = -5.572;
C_z_delta_e       = -0.217;
C_z_alpha2   = +3.538;
C_z_0        = -0.228;

C_L_beta     = -0.056;
C_L_p        = -0.538;
C_L_r        = +0.168;
C_L_delta_a  = -0.236;
C_L_delta_r  = +0.000;

C_M_alpha    = -1.118;
C_M_q        = -7.635;
C_M_delta_e  = -1.020;
C_M_alpha3   = -3.917;
C_M_0        = -0.090;

C_N_beta     = +0.126;
C_N_p        = +0.027;
C_N_r        = -0.169;
C_N_delta_a  = +0.059;
C_N_delta_r  = -0.065;
C_N_beta3    = +0.044;
C_N_0        =  0.000;

% Coefficients of force and moment
% Force coefficients:
C_x = C_x_alpha   * alpha     + ...
      C_x_delta_e * delta_e   + ...
      C_x_alpha2  * alpha.^2  + ...
      C_x_0;

C_y = C_y_beta    * beta       + ...
      C_y_p       * p_hat      + ...
      C_y_r       * r_hat      + ...
      C_y_delta_a * delta_a    + ...
      C_y_delta_r * delta_r    + ...
      C_y_beta3   * beta.^3    + ...
      C_y_0;

C_z = C_z_alpha   * alpha     + ...
      C_z_delta_e * delta_e   + ...
      C_z_alpha2  * alpha.^2  + ...
      C_z_0;

% Moment coefficients:
C_l = C_L_beta    * beta       + ...
      C_L_p       * p_hat      + ...
      C_L_r       * r_hat      + ...
      C_L_delta_a * delta_a    + ...
      C_L_delta_r * delta_r;

C_m = C_M_alpha   * alpha     + ...
      C_M_q       * q_hat     + ...
      C_M_delta_e * delta_e   + ...
      C_M_alpha3  * alpha.^3  + ...
      C_M_0;

C_n = C_N_beta    * beta       + ...
      C_N_p       * p_hat      + ...
      C_N_r       * r_hat      + ...
      C_N_delta_a * delta_a    + ...
      C_N_delta_r * delta_r    + ...
      C_N_beta3   * beta.^3    + ...
      C_N_0;

% Force and moment
F = qbar.*S*[C_x;C_y;C_z];
M = qbar.*S*[b*C_l;c*C_m;b*C_n];

H = double([delta_a delta_r 0       0       0;
            0       0       delta_e 0       0;
            0       0       0       delta_a delta_r]);

psi_H = double([C_l_beta*beta + C_l_p*phat + C_l_r*rhat;
         C_m_alpha*alpha + C_m_q*qhat + C_m_alpha3*alpha.^3 + C_m_0;
         C_n_beta*beta + C_n_p*phat + C_n_r*rhat + C_n_beta3*beta.^3]);

end