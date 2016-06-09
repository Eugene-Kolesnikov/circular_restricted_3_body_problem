function compute_V0_alpha_plot()

    Earth_mass = 5.9722;% * 10^24;
    Moon_mass = 0.0123 * Earth_mass;
    M = Earth_mass + Moon_mass;
    mu = Moon_mass / M;

    Earth_pos = [-mu;0];
    Moon_pos = [1-mu;0];
    
    r0 = 0.1:0.001:4;
    a = 0:0.01:2*pi;
    [R,A] = meshgrid(r0,a);
    fig1 = figure(1); hold on; grid on; grid minor; axis square;
    v2 = R.^2 + 2./R + 2.*sqrt(2*R).*sin(A);
    mesh(R,A,v2); view([119 28]);
    colorbar;
    xlabel('$r_0$','Interpreter','latex','FontSize',14);
    ylabel('$\alpha$','Interpreter','latex','FontSize',14);
    zlabel('$v_0^2$','Interpreter','latex','FontSize',14);
    
    print(fig1,'img/V0_alpha_plot_mesh','-dpng','-r600','-noui');
end