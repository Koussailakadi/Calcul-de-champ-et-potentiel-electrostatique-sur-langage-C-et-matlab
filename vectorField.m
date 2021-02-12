[X,Y] = meshgrid(-2:.8:2);
Z = X.*exp(-X.^2 - Y.^2)
[DX,DY] = gradient(Z,.2,.2);
figure
contour(X,Y,Z)
hold on
quiver(X,Y,DX,DY)
hold off