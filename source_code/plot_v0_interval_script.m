function plot_v0_interval_script()
    r0 = 0.1:0.001:5;
    v0_1 = -2*sqrt(2.*r0) + 2 ./ r0 + r0 .^ 2;
    v0_2 = 2*sqrt(2.*r0) + 2 ./ r0 + r0 .^ 2;
    fig1 = figure(1); hold on; grid on; grid minor; %axis square;
    plot(r0,v0_1,'Color','b');
    plot(r0,v0_2,'Color','r');
    axis_ = axis();
    plot([axis_(1) axis_(2)],[0 0], 'Color', 'k');
    [M,I] = min(v0_1);
    r0(I)
end