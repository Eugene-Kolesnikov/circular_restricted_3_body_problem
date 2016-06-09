function checkEscapeVelocity()
    clear;
    Earth_mass = 5.9722;% * 10^24;
    Moon_mass = 0.0123 * Earth_mass;
    M = Earth_mass + Moon_mass;
    mu = Moon_mass / M;
    %mu=0;
    
    Earth_pos = [-mu;0];
    Moon_pos = [1-mu;0];

    stopRadius = 2;
    closeRadius = 0.01657;
    
    %dr = 0.03;
    %dt = pi/4;
    %da = pi/4;
    %r = 0.01:dr:0.11;
    %t = 0:dt:(2*pi-0.001);
    %a = 0:da:(2*pi-0.001);
    N = 3;
    r = linspace(0.017,0.2,N);
    t = linspace(0,2*pi,N);
    a = linspace(0,2*pi,N);
    
    [R,T,A] = meshgrid(r, t, a);
    isEscapeVelocity = zeros(size(A));
    
    for ri = 1:length(r)
        for ti = 1:length(t)
            for ai = 1:length(a)
                x = Earth_pos(1) + r(ri) * cos(t(ti)); 
                y = r(ri) * sin(t(ti));
                v = sqrt(r(ri)^2+2/r(ri)+2*sqrt(2*r(ri))*sin(a(ai)));
                b = acos(sqrt(2/r(ri))/v*cos(a(ai)));
                v = 0;%1 * v;
                dx = v * cos(t(ti)+a(ai)); dy = v * sin(t(ti)+a(ai));
                initialConditions = [x, dx, y, dy]; timeInterval = [0 30.0];
                trajectoryModel_result = sim('trajectoryModel','SimulationMode','normal');
                trajectoryModel_out = trajectoryModel_result.get('simout');
                distances = sqrt((Earth_pos(1)+trajectoryModel_out.signal2.signal1.Data).^2+...
                             trajectoryModel_out.signal2.signal2.Data.^2);
                M = max(distances);
                closest = min(distances);
                if M >= stopRadius
                    x = trajectoryModel_out.signal2.signal1.Data(end);
                    y = trajectoryModel_out.signal2.signal2.Data(end);
                    dx = trajectoryModel_out.signal1.x_dot.Data(end);
                    dy = trajectoryModel_out.signal1.y_dot.Data(end);
                    h = 1/2*(dx^2+dy^2)+1/2*(x^2+y^2)-1/sqrt(x^2+y^2)+(y*dx-x*dy);
                    if h >= 0
                        isEscapeVelocity(ri,ti,ai) = 1;
                    else
                        isEscapeVelocity(ri,ti,ai) = 0;
                    end
                else
                    if closest <= closeRadius
                        isEscapeVelocity(ri,ti,ai) = -1;
                    else
                        isEscapeVelocity(ri,ti,ai) = 0;
                    end
                end
            end
        end
    end
    
    iter_1 = find(isEscapeVelocity(:) == 1);
    iter_0 = find(isEscapeVelocity(:) == 0);
    iter_m1 = find(isEscapeVelocity(:) == -1);
    escapeVelocityColors = zeros(length(isEscapeVelocity(:)),3);
    for i=1:length(iter_1)
        escapeVelocityColors(iter_1(i),:) = [0 0 1];
    end
    for i=1:length(iter_0)
        escapeVelocityColors(iter_0(i),:) = [0 1 0];
    end
    for i=1:length(iter_m1)
        escapeVelocityColors(iter_m1(i),:) = [1 0 0];
    end
    fig1 = figure(1); hold on; grid on; grid minor;
    scatter3sph(R(:),T(:),A(:),'size',0.2,'trans',0.7,'color',escapeVelocityColors);
    xlabel('$r_0$','Interpreter','latex','FontSize',14);
    ylabel('$\theta$','Interpreter','latex','FontSize',14);
    zlabel('$\alpha$','Interpreter','latex','FontSize',14);
    %print(fig1, 'img/checkEscapeVelocity_3bp_2bp','-dpng','-r800','-noui');
end