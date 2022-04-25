//
// Created by louka on 06/04/2022.
//

#include "fonction.h"
#include<conio.h>
#include<stdio.h>



//BOOL verif(int , int S[][]{

int** create_matrix(int size)
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

BOOL compter_nombre_ligne(int TL,int**M)
{
    int cpt;
    int un=0;
    int zero=0;
    for (int i=0;i<TL;i++)
    {
        for (int j=0;j<TL;j++)
        {
            cpt=M[i][j];
            if (cpt==1)
            {
                un=un+1;
            }
            if (cpt==0);
            {
                zero=zero+1;
            }
        }
    }
    if (un==zero)
    {
        return TRUE;
    }
    return FALSE;

}



/// FONCTIONS MENU

void menu1(char* choice){       //MENU PRINCIPAL
    int cpt=0;
    printf("\n\t--  MENU PRINCIPAL --\n\n");
    printf("1 - Resoudre manuelement une grille\n");
    printf("2 - Resoudre automatiquement une grille\n");
    printf("Q - QUITTER\n");
    do {
        if(cpt==0){
            //On vide le buffer sinon print 2 fois
            fflush(stdin);
            printf("\nSaisir votre choix:\n");
            cpt++;
        }
        else{
            //On vide le buffer sinon print 2 fois
            fflush(stdin);
            printf("Saisie incorrect. Resaisir:\n");
        }
        scanf("%c",choice);
    }while(((*choice>'2') || (*choice<'1')) && (*choice!='q') && (*choice!='Q'));

    //
    if(*choice=='1'){
        menu1_1(choice);
    }
    /*if(*choice=='2'){
    }
     */
}


void menu1_1(char* choice){         //SOUS MENU 1_1
    int cpt=0;
    int ** M=NULL;

    printf("\t--  RESOUDRE MANUELEMENT GRILLE --\n");
    printf("1 - GRILLE 4x4\n");
    printf("2 - GRILLE 8x8\n");
    printf("3 - GRILLE 16x16\n");
    printf("R - RETOUR\n");
    do {
        if(cpt==0){
            //On vide le buffer sinon print 2 fois
            fflush(stdin);
            printf("\nSaisir votre choix:\n");
            cpt++;
        }
        else{
            //On vide le buffer sinon print 2 fois
            fflush(stdin);
            printf("Saisie incorrect. Resaisir:\n");
        }
        scanf("%c",choice);
    }while(((*choice>'3') || (*choice<'1')) && (*choice!='R') && (*choice!='r'));

    // GRILLE 4X4
    if(*choice=='1'){
        M=create_matrix(4);
        menu1_2(4,choice,M);

    }
    // GRILLE 8X8
    if(*choice=='2'){
        M=create_matrix(8);
        menu1_2(8,choice,M);
    }
    // GRILLE 16X16
    if(*choice=='3'){
        M=create_matrix(16);
        menu1_2(16,choice,M);
    }

    // RETOUR AU MENU1
    if((*choice=='r')||(*choice=='R')){
        menu1(choice);
    }
}

int menu1_2(int dim,char* choice,int** M){       //SOUS MENU 1_2
    int cpt=0;
    printf("\t--  RESOUDRE MANUELEMENT GRILLE %dx%d  --\n",dim,dim);
    printf("1 - SAISIR MANUELEMENT UN MASQUE\n");
    printf("2 - GENERER UN MASQUE\n");
    printf("3 - JOUER\n"); //avec un masque aléatoire
    printf("R - RETOUR\n");
    do {
        if(cpt==0){
            //On vide le buffer sinon print 2 fois
            fflush(stdin);
            printf("\nSaisir votre choix:\n");
            cpt++;
        }
        else{
            //On vide le buffer sinon print 2 fois
            fflush(stdin);
            printf("Saisie incorrect. Resaisir:\n");
        }
        scanf("%c",choice);
    }while(((*choice>'3') || (*choice<'1')) && (*choice!='R') && (*choice!='r'));

    // SAISIE MANUELLE MASQUE(print grille jeu et masque)
    /*if(*choice=='1'){

    }
    // GENERER UN MASQUE AUTO(print grille jeu et masque)
    if(*choice=='2'){

    }
    // JOUER AVEC UN MASQUE AUTO
    if(*choice=='3'){

    }*/

    // RETOUR AU MENU1_1
    if((*choice=='r')||(*choice=='R')){
        menu1_1(choice);
    }


}

// FIN FONCTIONS MENU
