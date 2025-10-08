% Bounded Simplex Testbed 
clear;clc;close all;

cd(fileparts(mfilename('fullpath')));
Sim.directory = pwd(); % Current folder
addpath(genpath(Sim.directory));

A = [1 0 1 -1 2;
     0 1 2  2 1];

b = [5; 9];
c = [2; 1; 3; -2; 10];
lb = [0; 0; 0; 0; 0];
ub = [7;10; 1; 5; 3];



x_opt= luenberger_bounded_simplex(A, b, c, lb, ub);

disp('Optimal x:'), disp(x_opt.')
%disp('Optimal cost:'), disp(fval)
