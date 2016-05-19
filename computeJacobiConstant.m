function C = computeJacobiConstant(IC,mu,Earth_pos,Moon_pos)
    % IC -- initial conditions [x0, v_x0, y0, v_y0]
    % mu = Moon_mass / (Earth_mass + Moon_mass)
    r2 = norm([IC(1), IC(3)])^2;
    r_1 = norm([IC(1) - Earth_pos(1), IC(3)]);
    r_2 = norm([IC(1) - Moon_pos(1),  IC(3)]);
    v2 = norm([IC(2), IC(4)])^2;
    C = r2 +... % x^2 + y^2
        2 * (1 - mu) / r_1 +... % 2*(1-mu)/(distance from the Earth to the object)
        2 * mu / r_2 -... % 2*mu/(distance from the Moon to the object)
        v2; % v^2
end