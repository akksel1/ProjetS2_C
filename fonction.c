//
// Created by louka on 06/04/2022.
//

#include "fonction.h"
#include<conio.h>
#include<stdio.h>
#include <time.h>

//BOOL verif(int , int S[][]{

char** create_matrix(int size)
{
    char (**Z) = (char**) malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++)
    {
        Z[i] = malloc(size * sizeof (char));
    }
    return Z;
}

// Fonction d'affichage de couleurs trouvé sur OpenClassroom
void Color_Text(int Text_Color,int Back_color)
{
    HANDLE X=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(X,Back_color*16+Text_Color);
}

void print_matrix(char (**Z),int TL)
{
    // Affichage d'une matrice 4x4
    if(TL==4) {
        printf("     ");
        Color_Text(1, 8);
        printf("  A  B  C  D \n");
    }
    if(TL==8){
        printf("     ");
        Color_Text(1, 8);
        printf("  A  B  C  D  E  F  G  H \n");
    }
    if(TL==16){
        printf("     ");
        Color_Text(1, 8);
        printf("  A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P \n");
    }
    for (int i = 0; i < TL ; i++) {
        Color_Text(1, 8);
        if(i<9) {
            printf("  %d  ", i + 1);
            Color_Text(15, 0);
            printf("  ");
        }
        else{
            printf(" %d  ", i + 1);
            Color_Text(15, 0);
            printf("  ");
        }
        for (int j = 0; j < TL; j++) {
            printf("%c  ", Z[i][j]);
        }
        printf("\n");
    }

}

void print_mask(char (**Z),int TL)
{
    // Affichage d'une matrice 4x4
    if(TL==4) {
        printf("     ");
        Color_Text(1, 8);
        printf("  A  B  C  D \n");
    }
    if(TL==8){
        printf("     ");
        Color_Text(1, 8);
        printf("  A  B  C  D  E  F  G  H \n");
    }
    if(TL==16){
        printf("     ");
        Color_Text(1, 8);
        printf("  A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P \n");
    }
    for (int i = 0; i < TL ; i++) {
        Color_Text(1, 8);
        if(i<9) {
            printf("  %d  ", i + 1);
            Color_Text(15, 0);
            printf("  ");
        }
        else{
            printf(" %d  ", i + 1);
            Color_Text(15, 0);
            printf("  ");
        }
        for (int j = 0; j < TL; j++) {
            if(Z[i][j]=='0'){
                Color_Text(4,0);
            }
            printf("%c  ", Z[i][j]);
            Color_Text(15,0);


        }
        printf("\n");
    }

}


void initialize_matrix0(int TL,char**Z){
    for(int i=0;i<TL;i++)
    {
        for(int j=0;j<TL;j++)
        {
            Z[i][j]='0';
        }
    }
}

void initialize_matrix_personnaliser(int TL,char**Z)
{
    Z[0][0]='1';
    Z[0][1]='1';
    Z[0][2]='0';
    Z[0][3]='0';

    Z[1][0]='0';
    Z[1][1]='0';
    Z[1][2]='1';
    Z[1][3]='0';

    Z[2][0]='0';
    Z[2][1]='0';
    Z[2][2]='1';
    Z[2][3]='0';

    Z[3][0]='0';
    Z[3][1]='0';
    Z[3][2]='0';
    Z[3][3]='1';
}

void initialize_matrix1(int TL,char**Z){
    for(int i=0;i<TL;i++)
    {
        for(int j=0;j<TL;j++)
        {
            Z[i][j]='1';
        }
    }
}

BOOL counter_number_line(int TL,char**Z)
{
    char cpt;
    int un=0;
    int zero=0;
    for (int i=0;i<TL;i++)
    {
        for (int j=0;j<TL;j++)
        {
            cpt=Z[i][j];
            if (cpt=='1')
            {
                un=un+1;
            }
            if (cpt=='0')
            {
                zero=zero+1;
            }
        }
        printf("La ligne %d il y a %d nombre de 0 et %d nombre de 1 \n", i+1,zero,un);
        un=0;
        zero=0;
    }
    if (un==zero)
    {
        return TRUE;
    }
    return FALSE;

}

BOOL counter_number_column(int TL ,char**Z)
{
    char cpt;
    int un=0;
    int zero=0;
    for (int j=0;j<TL;j++)
    {
        for (int i=0;i<TL;i++)
        {
            cpt=Z[i][j];
            if (cpt=='1')
            {
                un=un+1;
            }
            if (cpt=='0')
            {
                zero=zero+1;
            }
        }
        printf("La colonne %d il y a %d nombre de 0 et %d nombre de 1 \n", j+1,zero,un);
        un=0;
        zero=0;
    }
    if (un==zero)
    {
        return TRUE;
    }
    return FALSE;

}

BOOL compare_line(int TL ,char**Z)
{
    char *T = (char *) malloc(TL * sizeof(char *)); // créer un tableau a dimension


    // T stock la premiere ligne du tableau
    for (int i = 0; i < TL; i++)
    {
        for (int j = 0; j < TL; j++)
        {
            T[j] = Z[i][j];
        }

        // Verification ligne identique

        BOOL verif=TRUE;
        int x;
        for (int t= 0; t<TL;t++)
        {
            if (i==t)
            {
                continue;
            }
            x=0;
            verif=TRUE;
            while (verif==TRUE && x<TL)
            {
                if (T[x]!=Z[t][x])
                {
                    verif=FALSE;
                }
                x++;

            }

            if (verif==TRUE)
            {
                printf("la ligne %d est identique \n",t+1);
                return FALSE;
            }
            else
            {
                printf("la ligne %d n'est pas identique \n ",t+1);
                return TRUE;
            }


        }
    }
}

BOOL compare_column(int TL ,char**Z)
{
    char *T = (char *) malloc(TL * sizeof(char *)); // créer un tableau a dimension


    // T stock la premiere colonne du tableau
    for (int j = 0; j < TL; j++)
    {
        for (int i = 0; i< TL; i++)
        {
            T[i] = Z[i][j];
        }

        // Verification colonne identique

        BOOL verif=TRUE;
        int t;
        for (int x= 0; x<TL;x++)
        {
            if (j==x)
            {
                continue;
            }
            t=0;
            verif=TRUE;
            while (verif==TRUE && t<TL)
            {
                if (T[t]!=Z[t][x])
                {
                    verif=FALSE;
                }
                t++;

            }

            if (verif==TRUE)
            {
                printf("la colonne %d est identique \n",x+1);
                return FALSE;
            }
            else
            {
                printf("la colonne %d n'est pas identique \n ",x+1);
                return TRUE;
            }


        }
    }
}


BOOL compare_indice_suivant_ligne(int TL,char**Z)
{
    char p;
    for (int i=0;i<TL;i++)
    {
        for (int j=0;j<TL-2;j++)
        {
            p=conversion_column(j);
            if (Z[i][j]=='0' && Z[i][j+1]=='0' && Z[i][j+2]=='0')
            {
                printf(" Il y a 3 zero d'affiler dans la meme ligne : ");
                printf("case[%d] [%c] \n",i+1,p);
                return FALSE;
            }

            if (Z[i][j]=='1' && Z[i][j+1]=='1' && Z[i][j+2]=='1')
            {
                printf(" Il y a 3 un d'affiler dans la meme ligne : ");
                printf("case [%d] [%c] \n",i+1,p);
                return FALSE;
            }
        }
    }
    return TRUE;
}

BOOL compare_indice_suivant_colonne(int TL,char**Z)
{
    char p;
    for (int i=0;i<TL-2;i++)
    {
        for (int j=0;j<TL;j++)
        {
            p=conversion_column(j);
            if (Z[i][j]=='0' && Z[i+1][j]=='0' && Z[i+2][j]=='0')
            {
                printf(" Il y a 3 zero d'affiler dans la meme colonne : ");
                printf("indice [%d] [%c]  \n",i+1,p);
                return FALSE;
            }
            if (Z[i][j]=='1' && Z[i+1][j]=='1' && Z[i+2][j]=='1')
            {+
                printf(" Il y a 3 un d'affiler dans la meme colonne : \n");
                printf("case [%d] [%c] \n",i+1,p);
                return FALSE;
            }
        }
    }
    return TRUE;
}







BOOL compare_game_with_solution(int line, char column,char** G,char** S)
{
    int j;
    j=column_conversion(column);
    if (G[line][j]==S[line][j])
    {
        return TRUE;
    }
    return FALSE;
}

BOOL saisie_securisee(int size, char (**Z),int* lig_ptr,char* col_char_ptr){
    int cpt,col,verif;
    int lig=-1;        //INITIALISATION
    char col_char='A';

    printf("Saisir 0/0 pour arreter\n\n");
    fflush(stdin);
    print_matrix(Z, size);
    printf("Saisir:");
    /*
    SAISIE SECURISEE
        Verif --> vérifier si l'user saisi le bon type (char à la place d'un int par ex.
    */
    verif = scanf("%d/%c", &lig, &col_char);



    if (size == 4) {
        cpt = 0;
        while (((lig > size) || (lig < 1)) || (col_char > 'D' || col_char < 'A') || verif == 0) {
            if(lig == 0 && col_char == '0'){
                break;
            }
            if (cpt % 2 == 1) {
                Color_Text(4, 0);
                printf("\n----\nRAPPEL: Ligne (1 - ... - 4)\nET\nColonne (A - ... - D)\n----\n");
                Color_Text(15, 0);
            }
            printf("Indice incorrect. Resaisir:");
            fflush(stdin);
            verif = scanf("%d/%c", &lig, &col_char);
            cpt++;
        }
    }
    if (size == 8) {
        cpt = 0;
        while (((lig > size) || (lig < 1)) || (col_char > 'H' || col_char < 'A') || verif == 0) {
            if(lig == 0 && col_char == '0'){
                break;
            }
            if (cpt % 2 == 1) {
                Color_Text(4, 0);
                printf("\n----\nRAPPEL: Ligne (1 - ... - 8)\nET\nColonne (A - ... - H)\n----\n");
                Color_Text(15, 0);
            }
            printf("Indice incorrect. Resaisir:");
            fflush(stdin);
            verif = scanf("%d/%c", &lig, &col_char);
            cpt++;
        }
    }
    if (size == 16) {
        cpt = 0;
        while (((lig > size) || (lig < 1)) || (col_char > 'P' || col_char < 'A') || verif == 0) {
            if(lig == 0 && col_char == '0'){
                break;
            }

            if (cpt % 2 == 1) {
                Color_Text(4, 0);
                printf("\n----\nRAPPEL: Ligne (1 - ... - 16)\nET\nColonne (A - ... - P)\n----\n");
                Color_Text(15, 0);
            }
            printf("Indice incorrect. Resaisir:");
            fflush(stdin);
            verif = scanf("%d/%c", &lig, &col_char);
            cpt++;
        }
    }
    if(lig == 0 && col_char == '0'){
        return TRUE; // L'utilisateur arrête la saisie
    }
    (*lig_ptr)=lig;
    (*col_char_ptr)=col_char;
    return FALSE;

}

void Mask_input(char (**Z),int size){
    int col;
    char col_char;
    int lig;
    BOOL res = FALSE;

    //On donne à la fonction une grille jeu
    printf("\nSur le masque: \n * 1 -> valeurs visibles\n * 0 -> valeurs cachees\n\n");
    printf("Saisir <LIGNE>/<COLONNE> pour cacher des valeurs\n");

    //Saisie indice
    while(res == FALSE) {

        res = saisie_securisee(size, Z, &lig, &col_char);

        //Conversion des colonnes en entier ( Ex: A <-> 1)
        if ((lig != 0) && (col_char != '0')) {
            col = column_conversion(col_char);
            Z[lig - 1][col] = '0';
        }
    }

}

int Random_index(int size){
    int nb, random;
    srand(clock());
    random = rand();
    nb = random % size;
    return nb;

}
// On importe une matrice masque initialisé à 1, une taille, une matrice test qui nous permet de stocker les indices déjà cachés par le programme ET une difficulté
void generate_mask(char** masque, int size, char** test, int difficulte_choice){
    float nb_case; // NB de case caché
    float cpt; // Nb d'opération
    int lig_random;
    int col_random;
    int random;

    /*
     * Difficulté 1 = 25% caché
     * Difficulté 2 = 50% caché
     * Difficulté 3 = 75% caché
     */

    if(difficulte_choice=='1'){
        cpt=0;
        nb_case=(0.25)*(size*size);
        lig_random = Random_index(size);
        col_random = Random_index(size);
        while(cpt < nb_case){
            lig_random += clock();
            lig_random = lig_random %size;
            col_random += clock();
            col_random = col_random %size;
            if(test[lig_random][col_random] == '0'){
                test[lig_random][col_random] = '1';
                // On masque dans masque
                masque[lig_random][col_random] = '0';
                cpt++;
            }
            else{
                continue;
            }


        }
    }

    if(difficulte_choice=='2'){
        cpt=0;
        nb_case = (0.5) * (size*size);
        lig_random = Random_index(size);
        col_random = Random_index(size);
        while(cpt < nb_case){

            lig_random += clock();
            lig_random = lig_random %size;
            col_random += clock();
            col_random = col_random %size;
            if(test[lig_random][col_random] == '0'){
                test[lig_random][col_random] = '1';
                // On masque dans masque
                masque[lig_random][col_random] = '0';
                cpt++;
            }
            else{
                continue;
            }
        }
    }
    if(difficulte_choice=='3'){
        cpt=0;
        nb_case = (0.75) * (size*size);
        lig_random = Random_index(size);
        col_random = Random_index(size);
        while(cpt < nb_case){
            lig_random += clock();
            lig_random = lig_random %size;
            col_random += clock();
            col_random = col_random %size;
            if(test[lig_random][col_random] == '0'){
                test[lig_random][col_random] = '1';
                // On masque dans masque
                masque[lig_random][col_random] = '0';
                cpt++;
            }
            else{
                continue;
            }
        }
    }
}






void Game_gridd(char **masque, char **game_matrix,int dim){
    //INITIALISATION DE LA GRILLE SOLUTION EN DUR
    if(dim==4) {
        char solution[4][4] = {
                {'1', '0', '0', '1'},
                {'1', '0', '1', '0'},
                {'0', '1', '1', '0'},
                {'0', '1', '0', '1'}
        };
        copy_matrix4(game_matrix,solution,dim);
    }
    if(dim==8) {
        char solution2[8][8] = {
                {'1', '0', '0', '1','1', '0', '0', '1'},
                {'1', '0', '1', '0','1', '0', '1', '0'},
                {'0', '1', '1', '0','0', '1', '1', '0'},
                {'0', '1', '0', '1','0', '1', '0', '1'},
                {'1', '0', '0', '1','1', '0', '0', '1'},
                {'1', '0', '1', '0','1', '0', '1', '0'},
                {'0', '1', '1', '0','0', '1', '1', '0'},
                {'0', '1', '0', '1','0', '1', '0', '1'}
        };
        copy_matrix8(game_matrix,solution2,dim);
    }
    if(dim==16) {
        char solution1[16][16] = {
                {'1', '0', '0', '1','1', '0', '0', '1','1', '0', '0', '1','1', '0', '0', '1'},
                {'1', '0', '1', '0','1', '0', '1', '0','1', '0', '1', '0','1', '0', '1', '0'},
                {'0', '1', '1', '0','0', '1', '1', '0','0', '1', '1', '0','0', '1', '1', '0'},
                {'0', '1', '0', '1','0', '1', '0', '1','0', '1', '0', '1','0', '1', '0', '1'},
                {'1', '0', '0', '1','1', '0', '0', '1','1', '0', '0', '1','1', '0', '0', '1'},
                {'1', '0', '1', '0','1', '0', '1', '0','1', '0', '1', '0','1', '0', '1', '0'},
                {'0', '1', '1', '0','0', '1', '1', '0','0', '1', '1', '0','0', '1', '1', '0'},
                {'0', '1', '0', '1','0', '1', '0', '1','0', '1', '0', '1','0', '1', '0', '1'},
                {'1', '0', '0', '1','1', '0', '0', '1','1', '0', '0', '1','1', '0', '0', '1'},
                {'1', '0', '1', '0','1', '0', '1', '0','1', '0', '1', '0','1', '0', '1', '0'},
                {'0', '1', '1', '0','0', '1', '1', '0','0', '1', '1', '0','0', '1', '1', '0'},
                {'0', '1', '0', '1','0', '1', '0', '1','0', '1', '0', '1','0', '1', '0', '1'},
                {'1', '0', '0', '1','1', '0', '0', '1','1', '0', '0', '1','1', '0', '0', '1'},
                {'1', '0', '1', '0','1', '0', '1', '0','1', '0', '1', '0','1', '0', '1', '0'},
                {'0', '1', '1', '0','0', '1', '1', '0','0', '1', '1', '0','0', '1', '1', '0'},
                {'0', '1', '0', '1','0', '1', '0', '1','0', '1', '0', '1','0', '1', '0', '1'}
        };
        copy_matrix16(game_matrix,solution1,dim);
    }
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            if(masque[i][j]=='0'){
                Color_Text(5,0);
                game_matrix[i][j]='_';
                Color_Text(15,0);
            }
        }

    }

}

void copy_matrix4(char** game_matrix,char solution[4][4],int dim){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            game_matrix[i][j]=solution[i][j];
        }
    }
}

void copy_matrix8(char** game_matrix,char solution[8][8],int dim){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            game_matrix[i][j]=solution[i][j];
        }
    }
}

void copy_matrix16(char** game_matrix,char solution[16][16],int dim){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            game_matrix[i][j]=solution[i][j];
        }
    }
}
//Utilisé dans Mask_input
int column_conversion(char y)
{
    if(y=='A'){
        return 0;
    }
    if(y=='B'){
        return 1;
    }
    if(y=='C'){
        return 2;
    }
    if(y=='D'){
        return 3;
    }
    if(y=='E'){
        return 4;
    }
    if(y=='F'){
        return 5;
    }
    if(y=='G'){
        return 6;
    }
    if(y=='H'){
        return 7;
    }
    if(y=='I'){
        return 8;
    }
    if(y=='J'){
        return 9;
    }
    if(y=='K'){
        return 10;
    }
    if(y=='L'){
        return 11;
    }
    if(y=='M'){
        return 12;
    }
    if(y=='N'){
        return 13;
    }
    if(y=='O'){
        return 14;
    }
    if(y=='P'){
        return 15;
    }
}

char conversion_column(int y)
{
    return y+65;
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
    int ** Z=NULL;

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
        menu1_2(4);

    }
    // GRILLE 8X8
    if(*choice=='2'){
        menu1_2(8);
    }
    // GRILLE 16X16
    if(*choice=='3'){
        menu1_2(16);
    }

    // RETOUR AU MENU1
    if((*choice=='r')||(*choice=='R')){
        menu1(choice);
    }
}

void menu1_2(int dim){       //SOUS MENU 1_2
    int cpt=0;
    char *choice;
    char **game_matrix;
    char(**masque);
    char(**test);

    int difficulte;
    int *lig_ptr;
    char *col_char_ptr;
    char **solution;
    BOOL egal_lig, egal_col, comp_lig, comp_col, trois_indice_lig, trois_indice_col,correct,trois_indice,egal,comp;

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

    if(*choice=='1'){
        char (**masque);
        masque=create_matrix(dim);
        initialize_matrix1(dim,masque);
        menu_1_2_1(dim,masque);

    }

    // GENERER UN MASQUE AUTO(print grille jeu et masque)
    if(*choice=='2'){
        masque = create_matrix(dim);
        initialize_matrix1(dim,masque);
        test = create_matrix(dim);
        initialize_matrix0(dim,test);
        difficulte=menu_difficulte();
        generate_mask(masque,dim,test,difficulte);
        printf("\n -- MASQUE GENERE --\n");
        print_mask(masque,dim);
        printf("\n");
        game_matrix=create_matrix(dim);
        Game_gridd(masque,game_matrix,dim);
        Color_Text(5,0);
        printf("   -- GRILLE JEU --\n");
        Color_Text(15,0);
        print_matrix(game_matrix,dim);
        printf("\n");



    }

    // JOUER AVEC UN MASQUE AUTO
    if(*choice=='3'){
        printf("ffff");
        masque = create_matrix(dim);
        initialize_matrix1(dim,masque);
        test = create_matrix(dim);
        initialize_matrix0(dim,test);
        difficulte=menu_difficulte();
        generate_mask(masque,dim,test,difficulte);
        game_matrix=create_matrix(dim);
        Game_gridd(masque,game_matrix,dim,1);
        Color_Text(5,0);
        printf("   -- GRILLE JEU --\n");
        Color_Text(15,0);
        print_matrix(game_matrix,dim);
        solution = create_matrix(dim);
        Game_gridd(masque,solution,dim,2); // On crée la matrice Solution
        printf("\n");
        do {
            saisie_securisee(dim,game_matrix, lig_ptr,col_char_ptr);


            egal_lig=counter_number_line(dim,game_matrix);
            egal_col=counter_number_column(dim,game_matrix);


            if(egal_lig == FALSE || egal_col == FALSE)
            {
                // - 1 vie
                egal = FALSE;
            }


            comp_lig=compare_line(dim,game_matrix);
            comp_col=compare_column(dim,game_matrix);

            if(comp_lig == FALSE || comp_col == FALSE)
            {
                // - 1 vie
                comp = FALSE;
            }


            trois_indice_lig=compare_indice_suivant_ligne(dim,game_matrix);
            trois_indice_col=compare_indice_suivant_colonne(dim,game_matrix);

            if(trois_indice_lig == FALSE ||  trois_indice_col== FALSE)
            {
                // - 1 vie
                trois_indice = FALSE;
            }


            correct=compare_game_with_solution((*lig_ptr),(*col_char_ptr),game_matrix,solution);
            if(correct == FALSE){
                printf("Coup valide mais incorrect...\n");
                printf("Re-essayer\n");
            }



        }while((correct==FALSE)||(trois_indice == FALSE)&&(comp == FALSE) &&(egal==FALSE));



    }

    // RETOUR AU MENU1_1
    if((*choice=='r')||(*choice=='R')){
        menu1_1(choice);
    }


}
//FINI
void menu_mask_input(char (**Z),int size){
    char choice;
    print_matrix(Z,size);
    printf("\n  -- SAISIE MASQUE --\n\n");
    printf("1 - Cacher des valeurs\n");
    printf("R - Retour\n");
    fflush(stdin);
    printf("Saisir :");
    scanf("%c",&choice);
    while(choice!='1' && choice!='r' && choice!='R'){
        fflush(stdin);
        printf("Saisie incorrect. Resaisir :");
        scanf("%c",&choice);
    }
    if(choice=='1'){
        Mask_input(Z,size);
    }
    else{
        menu1_2(size);
    }
}
//FINI
void menu_1_2_1(int dim,char** masque){
    char choice;
    printf("\n  -- SAISIE MASQUE --\n\n");
    printf("1 - Saisir/Modifier le masque\n");
    printf("2 - Afficher le masque & la grille jeu\n");
    printf("3 - Reinitialiser le masque & la grille jeu\n");
    printf("R - Retour\n");
    fflush(stdin);
    printf("Saisir :");
    scanf("%c",&choice);
    while((choice<'1'||choice>'3') && choice!='r' && choice!='R'){
        fflush(stdin);
        printf("Saisie incorrect. Resaisir :");
        scanf("%c", &choice);
    }



    if(choice == '1'){
        menu_mask_input(masque,dim);
        menu_1_2_1(dim,masque);
    }
    if(choice == '2'){
        Color_Text(5,0);
        printf("\n   -- MASQUE --\n");
        Color_Text(15,0);
        print_matrix(masque,dim);
        printf("\n");
        char **game_matrix;
        game_matrix=create_matrix(dim);
        Game_gridd(masque,game_matrix,dim);
        Color_Text(5,0);
        printf("   -- GRILLE JEU --\n");
        Color_Text(15,0);
        print_matrix(game_matrix,dim);
        menu_1_2_1(dim,masque);

    }
    if(choice == '3'){
        initialize_matrix1(dim,masque);
        menu_1_2_1(dim,masque);
    }
    if(choice == 'R' || choice == 'r'){
        menu1_2(dim);
    }
}

char menu_difficulte(){
    char difficulty_choice;
    printf("\n -- DIFFICULTE --\n\n");
    printf("1 - DEBUTANT\n");
    printf("2 - MOYEN\n");
    printf("3 - EXPERT (veuillez prevoir 5min)\n");
    printf("Saisir :\n");
    fflush(stdin);
    scanf("%c",&difficulty_choice);
    while(difficulty_choice<'1' || difficulty_choice>'3'){
        printf("Saisie incorrect. Resaisir:\n");
        scanf("%c",&difficulty_choice);
    }
    return difficulty_choice;
}
// FIN FONCTIONS MENU

