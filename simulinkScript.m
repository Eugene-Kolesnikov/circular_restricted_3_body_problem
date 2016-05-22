close all; clear;

Earth_mass = 5.9722;% * 10^24;
Moon_mass = 0.0123 * Earth_mass;
M = Earth_mass + Moon_mass;
mu = Moon_mass / M;

Earth_pos = [-mu;0];
Moon_pos = [1-mu;0];

computeJacobi_C = @(IC) computeJacobiConstant(IC,mu,Earth_pos,Moon_pos);
computeJacobi_v2 = @(x,y,C) computeJacobiVelocity(x,y,mu,Earth_pos,Moon_pos,C);

x0 = 1.15616816590553; y0 = 0;
v = sqrt(computeJacobi_v2(x0,y0,3.13)/2);
initialConditions = [x0, v, y0, v]; timeInterval = [0 135];
%initialConditions = [0.3011, -0.8496, 0.0773,  1.5496]; timeInterval = [0 12];
%initialConditions = [0.3011, 0.995*-0.8496, 0.0773,  0.995*1.5496]; timeInterval = [0 32];
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

% equilibrium points
% L1, L2, L3, L4, L5
Lx = [0.83629259089993, 1.15616816590553, -1.00511551160689, 0.487722529, 0.487722529]; 
Ly = [0, 0, 0, 0.86602540378444, -0.86602540378444]; 
LScaling = [5,5,5,5,5];

trajectoryModel_result = sim('trajectoryModel','SimulationMode','normal');
trajectoryModel_out = trajectoryModel_result.get('simout');

% compute velocity field around the Earth for given Jacobi constant
R = 0.7;
h = -R:0.001:R; % fragmentation
[hh_x,hh_y] = meshgrid(h,h);
r0_f = sqrt((hh_x-Earth_pos(1)).^2+hh_y.^2);
R0_1 = 6671 / 384400; R0_2 = 7871 / 384400; % Graveyard orbit
indeces = (r0_f >= R0_1).*(r0_f <= R); 
indeces = logical(indeces);
v0_field = zeros(size(hh_x));
v0_field(indeces) = sqrt(computeJacobi_v2(hh_x(indeces),hh_y(indeces),C)/2);

%% Plotting section
fig1 = figure(1); hold on; grid on; grid minor; %axis square;
ax = gca; ax.Position = [0.3000, 0.1100, 0.6050, 0.8150];
contour(h_x, h_y, v2_field, 1, 'Color' ,'red'); % plot Hill's regions
contour(hh_x, hh_y, (r0_f >= R0_1)+(r0_f <= R0_2), 2, 'Color' ,'black'); % plot Graveyard orbit
%mesh(hh_x,hh_y,v0_field); colorbar; % plot a velocity field
scatter(plot_x,plot_y,dotScaling,...
    'LineWidth', 0.6, 'MarkerEdgeColor', 'b',...
    'MarkerFaceColor', [0 0.5 0.5]); % plot planets
scatter(Lx,Ly,LScaling,...
    'LineWidth', 0.6, 'MarkerEdgeColor', 'k');
plot(trajectoryModel_out.signal1.Data,trajectoryModel_out.signal2.Data, 'Color', 'blue');

l = length(trajectoryModel_out.signal1.Data);
[M,I] = max((trajectoryModel_out.signal1.Data-Earth_pos(1)).^2+...
            trajectoryModel_out.signal2.Data.^2);
M = sqrt(M(1)); % max radius
I = I(1);
if I <= l
    x = trajectoryModel_out.signal1.Data(I);
    y = trajectoryModel_out.signal2.Data(I);
else
    x = trajectoryModel_out.signal1.Data(I-l);
    y = trajectoryModel_out.signal2.Data(I-l);
end
p1 = [Earth_pos(1), 0];
p2 = [x, y];
dp = p2 - p1;
quiver(p1(1),p1(2),dp(1),dp(2),0,'Color','black');
axis_ = axis();
Oxy = 1.01*max( abs(axis_(1)), max( abs(axis_(2)), max(abs(axis_(3)),abs(axis_(4))) ) );
axis([-Oxy Oxy -Oxy Oxy]);

% plot initial velocity
p1 = [initialConditions(1), initialConditions(3)];
dp = [initialConditions(2), initialConditions(4)];
%quiver(p1(1),p1(2),dp(1),dp(2),0,'Color','black');
% plot initial position
%scatter(p1(1),p1(2), 'MarkerEdgeColor', 'r',...
%    'MarkerFaceColor', 'k');
% add v0 text
%text(p1(1)+dp(1)+sign(p1(1)+dp(1))*abs(p1(1)+dp(1))*0.15,...
%    p1(2)+dp(2)+sign(p1(2)+dp(2))*abs(p1(2)+dp(2))*0.05,'$v_0$','Interpreter','latex','FontSize',14);

title(['C = ' num2str(C)]);
xlabel('$x$','Interpreter','latex','FontSize',14);
ylabel('$y$','Interpreter','latex','FontSize',14);

% create a text box
ax1 = axes('Position',[0 0 1 1],'Visible','off');
axes(ax1); % sets ax1 to current axes
descr = {['x_0 = ' num2str(initialConditions(1))];
         ['y_0 = ' num2str(initialConditions(3))];
         ['v_{x0} = ' num2str(initialConditions(2))];
         ['v_{y0} = ' num2str(initialConditions(4))];
         ['Max radius = ' num2str(M)]};
text(.025,0.86,descr,'FontSize',12,...
    'BackgroundColor','white','Margin',8,'EdgeColor','black','FontSmoothing', 'on');
axes(ax);
fig1.Position = [509 194 933 824];

%print(fig1,'img/sim_r3bp','-dpng','-r1200','-noui');

%% plot velocity difference
%v_01 = [0.3011, -0.8496, 0.0773,  1.5496];
%v_02 = [0.3011, 0.995*-0.8496, 0.0773,  0.995*1.5496];
%fig2 = figure(2); hold on; grid on; grid minor;
%plot([v_01(1) v_01(1)+v_01(2)],[v_01(3) v_01(3)+v_01(4)],'Color','r');
%scatter(v_01(1)+v_01(2),v_01(3)+v_01(4),'MarkerEdgeColor', 'k',...
%    'MarkerFaceColor', 'r');
%plot([v_02(1) v_02(1)+v_02(2)],[v_02(3) v_02(3)+v_02(4)],'Color','b');
%scatter(v_02(1)+v_02(2),v_02(3)+v_02(4),'MarkerEdgeColor', 'k',...
%    'MarkerFaceColor', 'b');
%axis([-0.5543 -0.5383 1.6084 1.6377]);
%text(0.999*(v_01(1)+v_01(2)),(v_01(3)+v_01(4)),['$v_0 =$ ' num2str(sqrt(v_01(2)^2+v_01(4)^2))],'Interpreter','latex','FontSize',14);
%text(0.999*(v_02(1)+v_02(2)),(v_02(3)+v_02(4)),['$v_0 =$ ' num2str(sqrt(v_02(2)^2+v_02(4)^2))],'Interpreter','latex','FontSize',14);
%print(fig2,'img/sim_r3bp_v0_in-outside','-dpng','-r1200','-noui');
