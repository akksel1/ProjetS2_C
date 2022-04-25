#include <stdio.h>
#include "fonction.h"


int main()
{
    int ** Z=NULL;
    Z=create_matrix(TL1);
    initialize_matrix(TL1,Z);
    print_matrix(Z,TL1);
    counter_number_line(TL1,Z);
    counter_number_column(TL1,Z);
    return 0;
}