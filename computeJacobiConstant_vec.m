function C = computeJacobiConstant_vec(x,y,vx,vy,mu,Earth_pos,Moon_pos)
    % IC -- initial conditions [x0, v_x0, y0, v_y0]
    % mu = Moon_mass / (Earth_mass + Moon_mass)
    r2 = x.^2 + y.^2;
    r_1 = sqrt((x-Earth_pos(1)).^2 + y.^2);
    r_2 = sqrt((x-Moon_pos(1)).^2 + y.^2);
    v2 = vx.^2 + vy.^2;
    C = r2 +... % x^2 + y^2
        2 * (1 - mu) ./ r_1 +... % 2*(1-mu)/(distance from the Earth to the object)
        2 * mu ./ r_2 -... % 2*mu/(distance from the Moon to the object)
        v2; % v^2
end