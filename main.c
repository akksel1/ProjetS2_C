#include <stdio.h>
#include "fonction.h"


int main()
{
    char ** M=NULL;
    char choice;
    M= create_matrix(4);
    initialize_matrix(4,M);
    print_matrix(M,4);
    compare_column(4,M);


    return 0;

}