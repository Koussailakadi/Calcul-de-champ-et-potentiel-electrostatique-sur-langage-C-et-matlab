#include "espace.h"


int main()
{
   point p={NULL,5,5};
   //creation de l'espace
   printf("dimx=%d   dimy=%d\n",p.dimx,p.dimy);
   p.espace=creerMatrice(p.dimx,p.dimy);
   afficherMatrice(p.espace,p.dimx,p.dimy);
   //1- lire un fichier qui contient la pérmitivité de l'espace qui doit avoir la meme taille que l'espace
   FILE *fichier=NULL;
   p.espace=lireFichier(fichier,p.dimx,p.dimy);
   afficherMatrice(p.espace,p.dimx,p.dimy);
   //2-  définir un type de distribution de charge



}
