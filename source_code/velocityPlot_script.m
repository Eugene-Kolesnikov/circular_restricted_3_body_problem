x0 = 0.0001;
y0 = 0.0003;

cVx1 = @(k) -(y0-k.*x0)./(1+k.^2) + sqrt( ((y0-k.*x0)./(1+k.^2)).^2 - ((x0.^2+y0.^2)^(3/2)-2)./((1+k.^2)*sqrt((x0.^2+y0.^2))) );
cVx2 = @(k) -(y0-k.*x0)./(1+k.^2) - sqrt( ((y0-k.*x0)./(1+k.^2)).^2 - ((x0.^2+y0.^2)^(3/2)-2)./((1+k.^2)*sqrt((x0.^2+y0.^2))) );

k = -10:0.001:10;

vx1 = cVx1(k);
vx2 = cVx2(k);
vy1 = k .* vx1;
vy2 = k .* vx2;

fig1 = figure(1); 
subplot(2,2,1); hold on; grid on; grid minor;
plot(k,vx1,'Color','b'); plot(k,vx2,'Color','r'); 
axis_ = axis();
plot([axis_(1) axis_(2)],[0 0],'Color','k');
plot([0 0],[axis_(3) axis_(4)],'Color','k');
legend({'$v_x^{(1)}$','$v_x^{(2)}$'},'Interpreter','latex','FontSize',14);
title(['$v_x(\alpha)$  \{$(x_0,y_0) = (' num2str(x0) ',' num2str(y0) ')$\}'],'Interpreter','latex','FontSize',14);
xlabel('$\alpha$','Interpreter','latex','FontSize',14);
ylabel('$v_x$','Interpreter','latex','FontSize',14);

subplot(2,2,3); hold on; grid on; grid minor;
plot(k,vy1,'Color','b'); plot(k,vy2,'Color','r');
axis_ = axis();
plot([axis_(1) axis_(2)],[0 0],'Color','k');
plot([0 0],[axis_(3) axis_(4)],'Color','k');
legend({'$v_y^{(1)}$','$v_y^{(2)}$'},'Interpreter','latex','FontSize',14);
title(['$v_y(\alpha)$  \{$(x_0,y_0) = (' num2str(x0) ',' num2str(y0) ')$\}'],'Interpreter','latex','FontSize',14);
xlabel('$\alpha$','Interpreter','latex','FontSize',14);
ylabel('$v_y$','Interpreter','latex','FontSize',14);

Earth_mass = 5.9722;% * 10^24;
Moon_mass = 0.0123 * Earth_mass;
M = Earth_mass + Moon_mass;
mu = 0;% Moon_mass / M;

Earth_pos = [-mu;0];
Moon_pos = [1-mu;0];

computeJacobi_C = @(IC) computeJacobiConstant(IC,mu,Earth_pos,Moon_pos);

C1 = zeros(size(vx1));
C2 = zeros(size(vx2));
for i = 1:length(k)
    C1(i) = computeJacobi_C([x0,vx1(i),y0,vy1(i)]);
    C2(i) = computeJacobi_C([x0,vx2(i),y0,vy2(i)]);
end

subplot(2,2,[2 4]); hold on; grid on; grid minor;
plot(k,C1,'Color','b'); plot(k,C2,'Color','r');
axis_ = axis();
plot([axis_(1) axis_(2)],[3 3],'Color','k');
axis_ = axis();
plot([axis_(1) axis_(2)],[0 0],'Color','k');
plot([0 0],[axis_(3) axis_(4)],'Color','k');
legend({'$C^{(1)}$','$C^{(2)}$'},'Interpreter','latex','FontSize',14);
title(['$C(\alpha)$  \{$(x_0,y_0) = (' num2str(x0) ',' num2str(y0) ')$\}'],'Interpreter','latex','FontSize',14);
xlabel('$\alpha$','Interpreter','latex','FontSize',14);
ylabel('$C$','Interpreter','latex','FontSize',14);

%print(fig1,'img/velocityPlots_Vx_Vy__1','-dpng','-r1200','-noui');