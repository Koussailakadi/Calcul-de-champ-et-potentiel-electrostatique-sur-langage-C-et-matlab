#include "espace.h"


float **creerMatrice(int dimx,int dimy)
{
    int i;
    float **matrice=NULL;
    matrice=calloc(dimx,sizeof(int));
    for(i=0;i<dimx;i++)
    {
        matrice[i]=calloc(dimy,sizeof(int));
    }
    return matrice;
}
void **afficherMatrice(float **matrice, int dimx , int dimy)
{
    int i,j;
    if((matrice)==NULL)
    {
        printf("matrice est nulle\n");
        exit(1);
    }
    for (i=0;i<dimx;i++)
    {
        for(j=0;j<dimy;j++)
            printf("%.2f  ",matrice[i][j]);
            printf("\n");
    }
    printf("\n\n-----------------fin affichage --------------------\n");
}
void libirerMatrice(float **matrice,int dimx, int dimy)
{
    int i,j;
    for(i=0;i<dimx;i++)
    {
     free(matrice[i]);
    }

    free(*matrice);
    matrice=NULL;
}
float **lireFichier(FILE *fichier,int dimx,int dimy)
{
    int i,j;
    float **permitivite=NULL;
    permitivite=creerMatrice(dimx,dimy);
    fichier=fopen("fichier.txt","r");
    for (i=0;i<dimx;i++)
    {
        for(j=0;j<dimy;j++)
        {
            fscanf(fichier,"%f",&permitivite[i][j]);
        }
    }
    fclose(fichier);
    printf("le fichier est bien lu !\n");
    return permitivite;
}
//triangle plein -------------------------------------------
float **trianglePlein(int hauteur,int dimx,int dimy,cordonne p)
{
   int xcentre,ycentre; // coordonnées du centre
   float q;  // charge
   xcentre=p.x;
   ycentre=p.y;
   q=p.charge;
   float **mat=NULL;
   mat=creerMatrice(dimx,dimy);
   int i,j;
   for(i=1;i<=hauteur;i++)
   {
       for(j=1;j<=2*hauteur-1;j++)
       {
           if(j>=hauteur-(i-1)&&j<=hauteur+(i-1))
           {
             mat[dimx/2-1+i-hauteur/2+xcentre][dimy/2+j-hauteur+ycentre]=q;
           }
           else
           mat[i][j]=0;
       }
   }return mat;
}
//---------------------------------------------------------
//triangle creux:
float **triangleCreux(int hauteur,int dimx,int dimy,cordonne p)
{
   int xcentre,ycentre; // coordonnées du centre
   float q;  // charge
   xcentre=p.x;
   ycentre=p.y;
   q=p.charge;
   float **mat=NULL;
   mat=creerMatrice(dimx,dimy);
   int i,j;
   for(i=1;i<=hauteur;i++)
   {
       for(j=1;j<=2*hauteur-1;j++)
       {
           if(i<hauteur&&(j==hauteur-(i-1)||j==hauteur+(i-1)))
           mat[dimx/2-1+i-hauteur/2+xcentre][dimy/2+j-hauteur+ycentre]=q;
           if(i==hauteur&&(j>=hauteur-(i-1)&&j<=hauteur+(i-1)))
           mat[dimx/2-1+i-hauteur/2+xcentre][dimy/2+j-hauteur+ycentre]=q;
       }
   }return mat;
}
//ecrire un fichier
float **EcrireFichier(float **matrice,int dimx,int dimy)
{
    int i,j;
    FILE *f=NULL;
    f=fopen("Potentiel.txt","w");
    for (i=0;i<dimx;i++)
    {
        for(j=0;j<dimy;j++)
        {
            fprintf(f,"%.2f ",matrice[i][j]);
        }
            fprintf(f,"%c\n");
    }
    fclose(f);
    printf("le fichier est bien ecrit !\n");
    return 0;
}
