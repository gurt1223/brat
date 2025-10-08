% Define the sampling frequency and the cutoff frequency
Fs = 200; % Sampling frequency (in Hz)
Fc = 30;   % Cutoff frequency (in Hz)

% Design a low-pass Butterworth filter
filterOrder = 5; % Order of the filter (adjustable)
lpFilt = designfilt('lowpassiir', 'FilterOrder', filterOrder, ...
                    'HalfPowerFrequency', Fc, 'SampleRate', Fs);

% Display filter information
fvtool(lpFilt); % Visualize the filter's frequency response

[b, a] = tf(lpFilt)

% Apply the filter to your data
% filteredData = filtfilt(lpFilt, data);
