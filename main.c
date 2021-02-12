#include "espace.h"

float **Potentiel(float **matrice,int dimx,int dimy)
{
   float **V=NULL;
   V=matrice;
   int i,j;
   for(i=0;i<dimx;i++)
   {
       for(j=0;j<dimy;j++)
       {
           if(i==0||i==dimx-1||j==0||j==dimy-1)
           V[i][j]=0;
           else
           V[i][j]=(V[i-1][j]+V[i+1][j]+V[i][j-1]+V[i][j+1])/4;
       }
   }return V;
}


int main()
{
   point p={NULL,10,10};
   //creation de l'espace
   /*printf("dimx=%d   dimy=%d\n",p.dimx,p.dimy);
   p.espace=creerMatrice(p.dimx,p.dimy);
   afficherMatrice(p.espace,p.dimx,p.dimy);*/

   //1- lire un fichier qui contient la pérmitivité de l'espace qui doit avoir la meme taille que l'espace
   FILE *fichier=NULL;
   p.espace=lireFichier(fichier,p.dimx,p.dimy);
   afficherMatrice(p.espace,p.dimx,p.dimy);
   //2- fonction triangle plein test:
   cordonne centre={5,0,0};
   float **mat=NULL;
   mat=trianglePlein(5,31,31,centre);
   afficherMatrice(mat,31,31);
   //2- fonction triangle creux test:
   float **triangleVide=NULL;
   triangleVide=triangleCreux(2,9,9,centre);
   afficherMatrice(triangleVide,9,9);
   //potentiel scalaire:
   float **V=NULL;
   V=Potentiel(mat,31,31);
   afficherMatrice(mat,31,31);
   //creer fichier
   EcrireFichier(mat,31,31);



}
