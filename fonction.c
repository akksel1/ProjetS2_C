//
// Created by louka on 06/04/2022.
//

#include "fonction.h"


//BOOL verif(int , int S[][]{

int** creer_matrice(int size)
{
    int** M = (int**) malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
    {
        M[i] = malloc(size * sizeof (int));
    }
    return M;
}

void Color_Text(int Text_Color,int Back_color) // fonction d'affichage de couleurs trouvé sur OpenClassroom
{
    HANDLE P=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(P,Back_color*16+Text_Color);
}

void print_matrix(int** M,int TL)
{
    // Affichage d'une matrice 4x4
    if(TL==4) {
        Color_Text(1, 8);
        printf("  A  B  C  D\n");
    }
    if(TL==8){
        Color_Text(1, 8);
        printf("  A  B  C  D  E  F  G  H\n");
    }
    if(TL==16){
        Color_Text(1, 8);
        printf("       A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P\n");
    }
    for (int i = 0; i < TL ; i++) {
        Color_Text(1, 8);
        if(i<9) {
            printf("  %d  ", i + 1);
            Color_Text(15, 0);
            printf("  ");
        }
        else{
            printf("  %d ", i + 1);
            Color_Text(15, 0);
            printf("  ");
        }
        for (int j = 0; j < TL; j++) {
            printf("%d  ", M[i][j]);
        }
        printf("\n");
    }

}

void initialize_matrix(int TL,int**M){
    for(int i=0;i<TL;i++){
        for(int j=0;j<TL;j++){
            M[i][j]=0;
        }
    }
}

