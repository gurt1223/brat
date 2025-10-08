function mode_string = process_mode(rc_switch, val0, val1, val2, val3)
% Process Ctrl Mode based on the rc_switch input
% rc_switch: the input switch value (0, 1, or 2)
% val0: the output value if rc_switch is 0
% val1: the output value if rc_switch is 1
% val2: the output value if rc_switch is 2

switch rc_switch
    case 0
        mode_string = val0;
    case 1
        mode_string = val1;
    case 2
        mode_string = val2;
    otherwise
        mode_string = val3;
end

end
