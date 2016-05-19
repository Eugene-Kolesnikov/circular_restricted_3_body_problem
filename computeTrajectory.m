close all; clear;

Earth_mass = 5.9722;% * 10^24;
Moon_mass = 0.0123 * Earth_mass;
M = Earth_mass + Moon_mass;
mu = Moon_mass / M;

Earth_pos = [-mu;0];
Moon_pos = [1-mu;0];

computeJacobi_C = @(IC) computeJacobiConstant(IC,mu,Earth_pos,Moon_pos);
computeJacobi_v2 = @(x,y,C) computeJacobiVelocity(x,y,mu,Earth_pos,Moon_pos,C);
diffEquation = @(t,p) r3bp_equation(t,p,mu,Earth_pos,Moon_pos);

% the computation of a trajectory of a satellite
%initialConditions = [-0.75, 0, 0, 0.2723]; timeInterval = [0 48]; % r3bp_1.png
%initialConditions = [0.95, 0, 0.0, 0.6465]; timeInterval = [0 48]; % r3bp_2.png
%initialConditions = [0.83, 0.062, 0.0, 0.1]; timeInterval = [0 48]; % r3bp_3.png
%initialConditions = [0.82, 0.062, 0.0, 0.05]; timeInterval = [0 197]; % r3bp_4.png
%initialConditions = [0.30910452642073, -0.72560796964234, 0.07738174525518,  1.55564233412773]; timeInterval = [0 12]; % r3bp_6.png
%initialConditions = [0.30910452642073, -0.72560796964234, 0.07738174525518,  1.55564233412773]; timeInterval = [0 52]; % r3bp_7.png
%initialConditions = [0.3091, -0.7366, 0.0773,  1.5566]; timeInterval = [0 212]; % r3bp_8.png
%initialConditions = [0.3091, 0.8216, 0.0773,  1.5606]; timeInterval = [0 70];% 
%initialConditions = [0.3011, -0.8496, 0.0773,  1.5496]; timeInterval = [0 12]; % r3bp_9.png
%initialConditions = [0.3011, -0.8496, 0.0773,  1.5496]; timeInterval = [0 122];
%initialConditions = [0.3011, -0.8786, 0.0773,  1.5547]; timeInterval = [0 12];
%initialConditions = [0.3011, -0.8886, 0.0773,  1.5547]; timeInterval = [0 12];
%initialConditions = [0.3011, -0.9116, 0.0773,  1.5547]; timeInterval = [0 52];
%initialConditions = [0.3011, -0.9256, 0.0893,  1.5317]; timeInterval = [0 152];
%initialConditions = [0.3011, -0.9256, 0.0893,  1.5317]; timeInterval = [0 66];
%initialConditions = [0.3011, -0.9256, 0.0893,  1.5317]; timeInterval = [0 500];

options = odeset('AbsTol',1e-6,'RelTol',1e-6,'MaxStep',1e-4);
[ts,ys] = ode45(@(t,p)diffEquation(t,p),timeInterval,initialConditions,options);

C = computeJacobi_C(initialConditions);

h = -1.5:0.001:1.5; % fragmentation
[h_x,h_y] = meshgrid(h,h);

% the computation of a v^2 field
v2_field = sign(computeJacobi_v2(h_x,h_y,C));

% necessary data for plotting
plot_points = [Earth_pos Moon_pos];
plot_x = plot_points(1,:); % x-coordinates
plot_y = plot_points(2,:); % y-coordinates
dotScaling = [30,10]; % planets' scaling factor

% equilibria points
% L1, L2, L3, L4, L5
Lx = [0.83629259089993, 1.15616816590553, -1.00511551160689, 0.487722529, 0.487722529]; 
Ly = [0, 0, 0, 0.86602540378444, -0.86602540378444]; 
LScaling = [5,5,5,5,5];

% the construction of a plot
fig1 = figure(1); hold on; grid on; grid minor; axis square;
contour(h_x, h_y, v2_field, 1, 'Color' ,'red'); % plot Hill's regions
scatter(plot_x,plot_y,dotScaling,...
    'LineWidth', 0.6, 'MarkerEdgeColor', 'b',...
    'MarkerFaceColor', [0 0.5 0.5]); % plot planets
scatter(Lx,Ly,LScaling,...
    'LineWidth', 0.6, 'MarkerEdgeColor', 'k');
plot(ys(:,1),ys(:,3),'Color','blue'); % trajectory
title(['C = ' num2str(C)]);
xlabel('$x$','Interpreter','latex','FontSize',14);
ylabel('$y$','Interpreter','latex','FontSize',14);

% create a text box
ax1 = axes('Position',[0 0 1 1],'Visible','off');
axes(ax1); % sets ax1 to current axes
descr = {['x_0 = ' num2str(initialConditions(1))];
         ['y_0 = ' num2str(initialConditions(3))];
         ['v_{x0} = ' num2str(initialConditions(2))];
         ['v_{y0} = ' num2str(initialConditions(4))]};
text(.025,0.8,descr,'FontSize',12);

% save the plot to a file
%print(fig1,'r3bp','-dpng','-r1200','-noui');
