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
    float lecture=0;
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
