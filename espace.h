#ifndef _espace_h_
#define _espace_h_
//inclusion de bebliotheques
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
float **espace;
int dimx,dimy;
}point;
typedef struct {
float charge;
float x,y;
}cordonne;

//inclusion de prototypes de fonction
float **creerMatrice(int dimx,int dimy);
void **afficherMatrice(float **matrice, int dimx , int dimy);
void libirerMatrice(float **matrice,int dimx, int dimy);
float **lireFichier(FILE *fichier,int dimx,int dimy);
float **trianglePlein(int hauteur,int dimx,int dimy,cordonne p);
float **triangleCreux(int hauteur,int dimx,int dimy,cordonne p);
float **Potentiel(float **matrice,int dimx,int dimy);
float **EcrireFichier(float **matrice,int dimx,int dimy);

#endif // _espace_h_
