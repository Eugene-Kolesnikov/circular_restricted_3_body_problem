function [vx vy] = computeV_rot(x0,y0)
    sin_alpha = -0.5;
    r0 = x0^2+y0^2;
    vx = sqrt(r0^2+2/r0-sqrt(2*r0) * sin_alpha);
    vy = 0;
end