function compute_V0_alpha_plot(alpha)

    Earth_mass = 5.9722;% * 10^24;
    Moon_mass = 0.0123 * Earth_mass;
    M = Earth_mass + Moon_mass;
    mu = Moon_mass / M;

    Earth_pos = [-mu;0];
    Moon_pos = [1-mu;0];

    computeJacobi_C = @(r,v) r.^2 +... % x^2 + y^2
        2 * (1 - mu) ./ r_1 +... % 2*(1-mu)/(distance from the Earth to the object)
        2 * mu / r_2 -... % 2*mu/(distance from the Moon to the object)
        v2; % v^2

    r0 = 0.1:0.001:4;
    color = ['b' 'r' 'g' 'k' 'm' 'c'];
    fig1 = figure(1); hold on; grid on; grid minor; %axis square;
    for i = 1:length(alpha)
        v2 = r0.^2 + 2./r0 + 2*sqrt(2*r0)*sin(alpha(i));
        plot(r0,v2,'Color',color(i));
        C = computeJacobi_C([r0(i) sqrt(v2) 0 0]);
    end
end