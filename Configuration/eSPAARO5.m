% Defines the information about the RACER vehicle for the FCS

MS = load('.\utils\SysID\ExcitationSignals\eSPAARO_5_real');

% Vehicle variables [metric units]

% Mass properties 
vehicle.mass_kg = 2.17724;                        % Approximate weight [kg] 
vehicle.MOI_kgpm2 = [0.029262,0.031578,0.047887,0];  % MOI (I_xx,I_yy,I_zz,I_xz) [kg*m^2]

% Motor params 
vehicle.motor.max_rpm = 10900;                 % Maximum mechanical RPM 
vehicle.motor.min_rpm = 999.3773654010;        % Minimum mechanical RPM

% Propeller params
vehicle.prop.max_T = 8.1394799*4;             % Maximum thrust of the vehicle [N]
vehicle.prop.num = 4;                         % Number of props on the vehicle
vehicle.prop.diam_m = 0.254;                  % Propeller diameter [m]
vehicle.prop.location_m = [...                % Location from CG (x,y,z axis) [m]
    0.17678 0.17678 0;...
    -0.17678 -0.17678 0;...
    0.17678 -0.17678 0;...
    -0.17678 0.17678 0;];
% vehicle.prop.CT0 = 0.0490*[1;1;1;1];          % Thrust coefficient
% vehicle.prop.CQ0 = 0.0040*[1;1;1;1];          % Torque coefficient
vehicle.prop.CT0 = 0.08297*[1;1;1;1];          % Thrust coefficient
vehicle.prop.CQ0 = 0.004047*[1;1;1;1];          % Torque coefficient
vehicle.prop.dir = [-1;-1;1;1];               % Propeller directions (-1 - CCW | 1 - CW)\

vehicle.ad_param.k = 1e4; % Should be 0.001
vehicle.ad_param.l = 1;
vehicle.ad_param.gamma = 500*eye(13);
% vehicle.ad_param.Ixx = 0.014051;
% vehicle.ad_param.Iyy = 0.017283;
% vehicle.ad_param.Izz = 0.02654;
% vehicle.ad_param.I = diag([Ixx,Iyy,Izz]);

Nr = 4;
b1 = 7/12*0.3048; b2 = 7/12*0.3048; % m
x1 = b1;  y1 = b2;
x2 = -b1; y2 = -b2;
x3 = b1; y3 = -b2;
x4 = -b1;  y4 = b2;
sig1 = -1; sig2 = -1; 
sig3 = 1;  sig4 = 1;

% Mixing Matrix (page 8)
vehicle.ad_param.MM_m = [1/Nr 1/Nr 1/Nr  1/Nr;...
                          -y1 -y2 -y3 -y4;...
                           x1 x2 x3 x4;...
                          -sig1 -sig2 -sig3 -sig4];

b1 = b1/0.3048; b2 = b2/0.3048; % ft
x1 = b1;  y1 = b2;
x2 = -b1; y2 = -b2;
x3 = b1; y3 = -b2;
x4 = -b1;  y4 = b2;

% Mixing Matrix (page 8)
vehicle.ad_param.MM_ft = [1/Nr 1/Nr 1/Nr  1/Nr;...
                          -y1 -y2 -y3 -y4;...
                           x1 x2 x3 x4;...
                          -sig1 -sig2 -sig3 -sig4];
