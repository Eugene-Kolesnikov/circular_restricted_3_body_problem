close all; clear;

Earth_mass = 5.9722;% * 10^24;
Moon_mass = 0.0123 * Earth_mass;
M = Earth_mass + Moon_mass;
mu = Moon_mass / M;

Earth_pos = [-mu;0];
Moon_pos = [1-mu;0];

h = -1.5:0.002:1.5; % fragmentation
[h_x,h_y] = meshgrid(h,h);

% compute the potential field
U = computePotential(h_x,h_y,mu,Earth_pos,Moon_pos);
U(U < -5) = -5;

% equilibria points
% L1, L2, L3, L4, L5
Lx = [0.83629259089993, 1.15616816590553, -1.00511551160689, 0.487722529, 0.487722529]; 
Ly = [0, 0, 0, 0.86602540378444, -0.86602540378444]; 
LScaling = [5,5,5,5,5];

fig2 = figure(2);
subplot(2,2,[1 3]); hold on; grid on; grid minor;
mesh(h_x,h_y,U);
subplot(2,2,2); hold on; grid on; grid minor;
mesh(h_x,h_y,U);
subplot(2,2,4); hold on; grid on; grid minor;
contourf(h_x,h_y,U,120);
scatter(Lx,Ly,LScaling,...
    'LineWidth', 0.6, 'MarkerEdgeColor', 'r',...
    'MarkerFaceColor', 'r');
%print(fig2,'rochePotential','-dpng','-r1200','-noui');