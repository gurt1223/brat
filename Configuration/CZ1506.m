% Defines the information about the RACER vehicle for the FCS

MS = load('.\utils\SysID\ExcitationSignals\CZ150_6');
MS2 = load('.\utils\SysID\ExcitationSignals\CZ150_6_2');

% Vehicle variables [metric units]

vehicle.ca.B_matrix_dumb = [ 16.32  -16.32   0.00   3.54  10.62 -10.62;
       0.00    0.00 -53.31   0.00 -15.99 -15.99;
      -7.08    7.08   0.00  38.94  -5.31   5.31 ];