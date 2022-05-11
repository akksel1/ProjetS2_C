#include <stdio.h>
#include "fonction.h"

int main()
{
    int ** M=NULL;
    M= create_matrix(4);
    initialize_matrix_personnaliser(4,M);
    print_matrix(M, 4);
    compare_indice_suivant_ligne(4,M);
    compare_indice_suivant_colonne(4,M);

}