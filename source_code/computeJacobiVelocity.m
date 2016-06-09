function v2 = computeJacobiVelocity(x,y,mu,Earth_pos,Moon_pos,C)
    % mu = Moon_mass / (Earth_mass + Moon_mass)
    r2 = x.^2 + y.^2;
    r_1 = sqrt( (x - Earth_pos(1)).^2 + y.^2 );
    r_2 = sqrt( (x - Moon_pos(1)).^2 + y.^2 );
    v2 = r2 - C +...
        2 * (1 - mu) ./ r_1 +... % 2*(1-mu)/(distance from the Earth to the object)
        2 * mu ./ r_2; % 2*mu/(distance from the Moon to the object)
end