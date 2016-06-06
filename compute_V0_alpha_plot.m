function compute_V0_alpha_plot(alpha)

    Earth_mass = 5.9722;% * 10^24;
    Moon_mass = 0.0123 * Earth_mass;
    M = Earth_mass + Moon_mass;
    mu = Moon_mass / M;

    Earth_pos = [-mu;0];
    Moon_pos = [1-mu;0];
    
    

    r0 = 0.1:0.001:4;
    color = ['b' 'r' 'g' 'k' 'm' 'c'];
    fig1 = figure(1); hold on; grid on; grid minor; %axis square;
    for i = 1:length(alpha)
        v2 = r0.^2 + 2./r0 + 2*sqrt(2*r0)*sin(alpha(i));
        plot(r0,v2,'Color',color(i));
    end
    legend({'$-\pi/2$', '$-\pi/4$', '$0$', '$\pi/4$', '$\pi/2$'},...
        'Interpreter','latex','Location','best','FontSize',14);
    
    print(fig1,'img/V0_alpha_plot','-dpng','-r1200','-noui');
end