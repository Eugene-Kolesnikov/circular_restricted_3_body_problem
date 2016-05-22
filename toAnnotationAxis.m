function [x2,y2] = toAnnotationAxis(axs,ax,x,y)
    x1 = (x - ax(1)) / (ax(2)-ax(1));
    y1 = (y - ax(3)) / (ax(4)-ax(3));
    x2 = axs(1) + x1 * axs(3);
    y2 = axs(2) + y1 * axs(4);
end