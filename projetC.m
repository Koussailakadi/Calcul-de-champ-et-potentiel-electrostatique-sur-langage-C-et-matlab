x= 0:0.25:7.5;
y= 0:0.25:7.5;
[xx,yy]=meshgrid(x,y)
type potentiel.txt
%F= fopen('Potentiel.txt','r');
B=readmatrix('Potentiel.txt')
l=length(B);
A=B(:,1:end-1)
%A=fscanf(F,'%f%c',[9 9])'
figure;
surf(xx,yy,A);%  potentiel scalaire
[DX,DY]=gradient(A,.2,.2)
figure
contour(xx,yy,A)
hold on
quiver(xx,yy,DX,DY) % champ vectoriel 
hold off




