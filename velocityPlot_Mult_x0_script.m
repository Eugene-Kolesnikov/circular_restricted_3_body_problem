x0 = [0.01, 0.1, 0.2, 0.5, 0.7, 0.9, 1.1];
y0 = 0;
k = -10:0.01:10;

cVx1 = @(x0,k) -(y0-k.*x0)./(1+k.^2) + sqrt( ((y0-k.*x0)./(1+k.^2)).^2 - ((x0.^2+y0.^2).^(3/2)-2)./((1+k.^2).*sqrt((x0.^2+y0.^2))) );
cVx2 = @(x0,k) -(y0-k.*x0)./(1+k.^2) - sqrt( ((y0-k.*x0)./(1+k.^2)).^2 - ((x0.^2+y0.^2).^(3/2)-2)./((1+k.^2).*sqrt((x0.^2+y0.^2))) );

vx1 = cVx1(X,K);
vx2 = cVx2(X,K);

fig1 = figure(1); hold on; grid on; grid minor;
for i = 1:length(x0)
   vx1 = cVx1(x0(i),k);
   vx2 = cVx2(x0(i),k);
   plot(k,vx1,'Color','b'); 
   plot(k,vx2,'Color','r'); 
end
axis_ = axis();
plot([axis_(1) axis_(2)],[0 0],'Color','k');
plot([0 0],[axis_(3) axis_(4)],'Color','k');

xlabel('$\alpha$','Interpreter','latex','FontSize',14);
ylabel('$v_x$','Interpreter','latex','FontSize',14);

%print(fig1,'img/velocityPlots_Mult_Vx_Vy','-dpng','-r1200','-noui');