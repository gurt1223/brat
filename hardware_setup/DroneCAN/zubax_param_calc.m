clc;

%%%%%%%%%%%%%%%%%%%%%%%% USER DEFINED PARAMETERS %%%%%%%%%%%%%%%%%%%%%%%%%%
m_RPM_max = 10900; % maximum mechanical RPM from testing at 3.6 v/cell
m_RPM_min_proposed = 1000; % initial/proposed minimum RPM (this will change)
p = 14; % number of poles in the motor

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% CALCULATIONS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
max_act_output = 8191; % standard maximum actuator_output for CAN ESC

% Calculate initial min_act_output based on proposed minimum RPM
min_act_output_initial = (m_RPM_min_proposed * max_act_output) / m_RPM_max;

% Round min_act_output to nearest integer
min_act_output_rounded = round(min_act_output_initial);

% Calculate the actual minimum RPM based on the rounded min_act_output
actual_m_RPM_min = (min_act_output_rounded * m_RPM_max) / max_act_output;

% Calculate the eRPM for the zubax parameters
eRPM_max = vpa((1/60)*pi*p*m_RPM_max);
eRPM_min = vpa((1/60)*pi*p*actual_m_RPM_min);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% DISPLAY RESULTS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
disp(' ')
disp(' ****************************************************')
disp('Program this into QGC: (where # is ESC 1,2,3, etc.)')
fprintf('UAVCAN_EC_MIN#: %d\n', min_act_output_rounded);
fprintf('UAVCAN_EC_MAX#: %d\n', max_act_output);
disp(' ')
disp(' ****************************************************')
disp(['Program this into the Simulink diagram as the new minimum RPM ' ...
    'that is being sent: '])
fprintf('Actual Minimum RPM: %.10f\n', actual_m_RPM_min);
fprintf('Actual Maximum RPM: %.10f\n', m_RPM_max);
disp(' ')
disp(' ****************************************************')
disp('Program these parameters on the Zubax Myxa ESCs: ')
fprintf('m.max_eangvel: %.10f\n', eRPM_max);
fprintf('m.min_eangvel: %.10f\n', eRPM_min);