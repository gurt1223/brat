uint64 timestamp    #time since system start (microseconds)

float32[2] arm #information about the vehicles arming state
float32[7] actuator_cmds #normalized actuator commands for PX4 
float32[7] actuator_fail_cmds #normalized actuator fail commands for PX4 
float32[10] ol_pti #data from the open-loop PTI injection subsystem