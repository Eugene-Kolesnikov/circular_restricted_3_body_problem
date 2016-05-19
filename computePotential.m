function U = computePotential(x,y,mu,Earth_pos,Moon_pos)
    % mu = Moon_mass / (Earth_mass + Moon_mass)
    r2 = x.^2 + y.^2;
    r_1 = sqrt( (x - Earth_pos(1)).^2 + y.^2 );
    r_2 = sqrt( (x - Moon_pos(1)).^2 + y.^2 );
    U = -(r2 / 2 +...
        (1 - mu) ./ r_1 +... % 2*(1-mu)/(distance from the Earth to the object)
        mu ./ r_2); % 2*mu/(distance from the Moon to the object)
end