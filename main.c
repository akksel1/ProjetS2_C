#include <stdio.h>
#include "fonction.h"


int main()
{
// initialisation de la matrice en séquence
    /*int M[4][4] = {};
    int i, j, lig = 4, col = 4;
    for (i = 0; i < lig; i++) {
        for (j = 0; j < col; j++) {
            printf("%d \t\t", M[i][j]); // séparer les valeursd 'une même ligne par 2 tabulations
        }
        printf("\n"); // Saut de ligne avant d'afficher la suivante
    }
*/

    int ** M=NULL;
    BOOL T;
    M = creer_matrice(TL1);
    initialize_matrix(TL1,M);
    print_matrix(M,TL1);
    T=compter_nombre_ligne(TL1,M);
    printf("%d",T);

    return 0;

}