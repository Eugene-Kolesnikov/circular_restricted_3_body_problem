function dp = r3bp_equation(t,p,mu,Earth_pos,Moon_pos)
    % p -- point in a configuration space [x, vx, y, vy]
    r1 = norm([p(1) - Earth_pos(1), p(3)]);
    r2 = norm([p(1) - Moon_pos(1),  p(3)]);
    dp = zeros(size(p)); % since output must be a column vector
    dp(1) = p(2);
    dp(2) = 2 * p(4) + p(1) +...
        (1 - mu) / r1^3 * (Earth_pos(1) - p(1)) +...
        mu / r2^3 * (Moon_pos(1) - p(1));
    dp(3) = p(4);
    dp(4) = -2 * p(2) + p(3) -...
        (1 - mu) / r1^3 * p(3) -...
        mu / r2^3 * p(3);
end