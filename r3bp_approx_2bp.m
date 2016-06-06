function r3bp_approx_2bp()
    Earth_mass = 5.9722;% * 10^24;
    Moon_mass = 0.0123 * Earth_mass;
    M = Earth_mass + Moon_mass;
    mu = Moon_mass / M;

    Earth_pos = [-mu;0];
    Moon_pos = [1-mu;0];
    
    x_error = @(x,y)...
        abs( (1-mu)./((x-Earth_pos(1)).^2+y.^2).^(3/2).*(Earth_pos(1)-x)+...
        mu./((x-Moon_pos(1)).^2+y.^2).^(3/2).*(Moon_pos(1)-x)+1./(x.^2+y.^2).^(3/2).*x );
    y_error = @(x,y)...
        abs( (1-mu)./((x-Earth_pos(1)).^2+y.^2).^(3/2).*y+...
        mu./((x-Moon_pos(1)).^2+y.^2).^(3/2).*y-1./(x.^2+y.^2).^(3/2).*y );
    
    [X,Y] = meshgrid(-2.2:0.002:2.2,-2.2:0.002:2.2);
    
    x_err = x_error(X,Y);
    y_err = y_error(X,Y);
    
    E = sqrt( x_err.^2 + y_err.^2 );
    E(E>0.3) = 0.3; E = E - 0.3;
    
    fig1 = figure('Position',[5 -21 1036 1104]);
    hold on; grid on; grid minor; view([-0.5 90]); axis square;
    contour(X,Y,E,'Color','red');
    mesh(X,Y,E);
    
    print(fig1,'img/r3bp_approx_2bp','-dpng','-r600','-noui');
end