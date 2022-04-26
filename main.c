#include <stdio.h>
#include "fonction.h"


int main()
{
    int ** M=NULL;
    char choice;
    M= create_matrix(8);
    initialize_matrix(8,M);
    menu_mask_input(M,8);
    //menu1(&choice);
    //if(((choice)!='Q')&& (choice!='q')) {
        /*M= create_matrix(16);
        initialize_matrix(16, M);
        print_matrix(M, 16);
        getch(); //Pour ne pas arrêter le programme automatiquement (Conio.h)}
         */

    return 0;

}