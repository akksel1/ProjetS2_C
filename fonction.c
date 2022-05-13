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

BOOL counter_number_line(int TL,char**Z,int lig,int col,char** test)
{
    char cpt;
    int un=0;
    int zero=0;

    for(int j=0;j<TL;j++){
        cpt=Z[lig][j];
        if (cpt=='1')
        {
            un=un+1;
        }
        if (cpt=='0')
        {
            zero=zero+1;
        }
    }
    if((zero!=un) && (ligne_remplie(lig,Z,TL)==TRUE))
    {
        printf("\nLA LIGNE %d NE CONTIENT PAS LE MEME NOMBRE DE 0 QUE DE 1\n",lig+1);
        reset_lig(Z,test,lig,TL);
        return FALSE;
    }
    if(zero==un && ligne_remplie(lig,Z,TL)==TRUE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}

BOOL counter_number_column(int TL ,char**Z,int lig,int col,char** test)
{
    /*
     * MATRICE TEST => COPIE DU MASQUE
    */

    char cpt;
    int un=0;
    int zero=0;

    for(int i=0;i<TL;i++){
        cpt=Z[i][col];
        if (cpt=='1')
        {
            un=un+1;
        }
        if (cpt=='0')
        {
            zero=zero+1;
        }
    }
    if((zero!=un) && (colonne_remplie(col,Z,TL)==TRUE))
    {
        printf("LA COLONNE %c NE CONTIENT PAS LE MEME NOMBRE DE 0 QUE DE 1\n", conversion_column(col));
        reset_col(Z,test,col,TL);
        return FALSE;
    }
    if(zero==un && colonne_remplie(col,Z,TL)==TRUE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

BOOL compare_line(int TL ,char**Z,int lig,int col,char** test)
{
    char *T = (char *) malloc(TL * sizeof(char *)); // créer un tableau a dimension


    // T stock la ligne du tableau

        for (int j = 0; j < TL; j++)
        {
            T[j] = Z[lig][j];
        }


        // Verification ligne identique

        BOOL verif=TRUE;
        int x;
        for (int t= 0; t<TL;t++)
        {
            if (lig==t)
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


            // SI LIGNE REMPLIE
            if((verif==TRUE) && (ligne_remplie(lig,Z,TL)==TRUE))
            {
                printf("LA LIGNE %d EST IDENTIQUE \n",t+1);
                reset_col(Z,test,col,TL);
                return FALSE;
            }
            if(verif==FALSE && ligne_remplie(lig,Z,TL)==TRUE)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }

}

BOOL compare_column(int TL ,char**Z,int lig,int col,char** test)
{
    char *T = (char *) malloc(TL * sizeof(char *)); // créer un tableau a dimension



    BOOL colonne_remplie(int,char**,int);
    BOOL ligne_remplie(int,char**,int);


    // T stock la premiere colonne du tableau
        for (int i = 0; i< TL; i++)
        {
            T[i] = Z[i][col];
        }

        // Verification colonne identique

        BOOL verif=TRUE;
        int t;
        for (int x= 0; x<TL;x++)
        {
            if (col==x)
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



            // SI LIGNE REMPLIE
            if((verif==TRUE) && (colonne_remplie(col,Z,TL)==TRUE))
            {
                printf("LA COLONNE %d EST IDENTIQUE \n",x+1);
                reset_col(Z,test,col,TL);
                return FALSE;
            }
            if(verif==FALSE && (colonne_remplie(col,Z,TL)==TRUE))
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }


        }

}

BOOL compare_indice_suivant_ligne(int TL,char**Z)
{
    char p;
    for (int i=0;i<TL;i++)
    {
        for (int j=2;j<TL-2;j++)
        {
            p=conversion_column(j);
            if (Z[i][j]=='0' && Z[i][j+1]=='0' && Z[i][j+2]=='0')
            {
                //printf(" Il y a 3 zero d'affiler dans la meme ligne : ");
                //printf("case[%d] [%c] \n",i+1,p);
                return FALSE;
            }

            if (Z[i][j]=='0' && Z[i][j-1]=='0' && Z[i][j-2]=='0')
            {
                //printf(" Il y a 3 zero d'affiler dans la meme ligne : ");
                //printf("case[%d] [%c] \n",i+1,p);
                return FALSE;
            }

            if (Z[i][j]=='1' && Z[i][j+1]=='1' && Z[i][j+2]=='1')
            {
                //printf(" Il y a 3 un d'affiler dans la meme ligne : ");
                //printf("case [%d] [%c] \n",i+1,p);
                return FALSE;
            }

            if (Z[i][j]=='1' && Z[i][j-1]=='1' && Z[i][j-2]=='1')
            {
                //printf(" Il y a 3 un d'affiler dans la meme ligne : ");
                //printf("case [%d] [%c] \n",i+1,p);
                return FALSE;
            }
        }
    }
    return TRUE;
}

BOOL compare_indice_suivant_colonne(int TL,char**Z)
{
    char p;
    for (int i=2;i<TL-2;i++)
    {
        for (int j=0;j<TL;j++)
        {
            p=conversion_column(j);
            if (Z[i][j]=='0' && Z[i+1][j]=='0' && Z[i+2][j]=='0')
            {
                //printf(" Il y a 3 zero d'affiler dans la meme colonne : ");
                //printf("indice [%d] [%c]  \n",i+1,p);
                return FALSE;
            }

            if (Z[i][j]=='0' && Z[i-1][j]=='0' && Z[i-2][j]=='0')
            {
                //printf(" Il y a 3 zero d'affiler dans la meme colonne : ");
                //printf("indice [%d] [%c]  \n",i+1,p);
                return FALSE;
            }

            if (Z[i][j]=='1' && Z[i+1][j]=='1' && Z[i+2][j]=='1')
            {
                //printf(" Il y a 3 un d'affiler dans la meme colonne : \n");
                //printf("case [%d] [%c] \n",i+1,p);
                return FALSE;
            }

            if (Z[i][j]=='1' && Z[i-1][j]=='1' && Z[i-2][j]=='1')
            {
                //printf(" Il y a 3 un d'affiler dans la meme colonne : \n");
                //printf("case [%d] [%c] \n",i+1,p);
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

BOOL saisie_securisee(int size, char (**Z),int *lig_ptr,char *col_char_ptr){
    int cpt,col,verif;
    int lig;
    char col_char;

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

void saisie_securisee_jouer(int size, char** game_matrix,int *lig_ptr,char *col_char_ptr, char ** test) {
    int cpt, col, verif;
    int lig;
    char col_char;
    BOOL cache = FALSE;

    fflush(stdin);
    print_matrix(game_matrix, size);
    printf("Saisir l'indice:");
    /*
    SAISIE SECURISEE
        Verif --> vérifier si l'user saisi le bon type (char à la place d'un int par ex.
    */
    verif = scanf("%d/%c", &lig, &col_char);


    /*
        * On vérifie d'abord que l'indice existe dans le matrice
        * Enfin on vérifie si l'indice est bien caché
    */

    if (size == 4) {
        cpt = 0;
        cache = FALSE;
        while (cache == FALSE) {
            while (((lig > size) || (lig < 1)) || (col_char > 'D' || col_char < 'A') || verif == 0) {
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
            if (test[lig - 1][column_conversion(col_char)] == '0') {
                cache = TRUE;
            } else {
                cache = FALSE;
                Color_Text(4, 0);
                printf("LES INDICES NON CACHES NE SONT PAS MODIFIABLES\n");
                Color_Text(15, 0);
                printf("Resaisir:");
                verif = scanf("%d/%c", &lig, &col_char);
            }

        }
    }
    if (size == 8) {
        cpt = 0;
        cache = FALSE;
        while (cache == FALSE) {
            while (((lig > size) || (lig < 1)) || (col_char > 'H' || col_char < 'A') || verif == 0) {
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
            if (test[lig - 1][column_conversion(col_char)] == '0') {
                cache = TRUE;
            } else {
                cache = FALSE;
                Color_Text(4, 0);
                printf("LES INDICES NON CACHES NE SONT PAS MODIFIABLES\n");
                Color_Text(15, 0);
                printf("Resaisir:");
                verif = scanf("%d/%c", &lig, &col_char);
            }
        }
    }
    if (size == 16) {
        cpt = 0;
        cache = FALSE;
        while (cache == FALSE) {
            while (((lig > size) || (lig < 1)) || (col_char > 'P' || col_char < 'A') || verif == 0) {
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
            if (test[lig - 1][column_conversion(col_char)] == '0') {
                cache = TRUE;
            } else {
                cache = FALSE;
                Color_Text(4, 0);
                printf("LES INDICES NON CACHES NE SONT PAS MODIFIABLES\n");
                Color_Text(15, 0);
                printf("Resaisir:");
                verif = scanf("%d/%c", &lig, &col_char);
            }
        }



    }
    (*lig_ptr) = lig;
    (*col_char_ptr) = col_char;

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
void generate_mask(char(**masque), int size, char** test, char difficulte_choice){
    float nb_case; // NB de case caché
    float cpt; // Nb d'opération
    int cpt2;
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
        cpt2=0;
        nb_case=(0.25)*(size*size);
        lig_random = Random_index(size);
        col_random = Random_index(size);
        while(cpt < nb_case){
            if(cpt2%2==0) {
                lig_random += clock();
                lig_random = lig_random % size;
                col_random += time(NULL);
                col_random = col_random % size;
            }
            if(cpt2%2==1){
                lig_random += clock();
                lig_random = lig_random % size;
                col_random += time(NULL);
                col_random = col_random % size;
            }
            if(test[lig_random][col_random] == '0'){
                test[lig_random][col_random] = '1';
                // On masque dans masque
                masque[lig_random][col_random] = '0';
                cpt++;
                cpt2++;
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

BOOL ligne_complete(char** Z,int dim, int lig)
{
    BOOL complet = TRUE;
    int j=0;
    while(complet==TRUE && j<dim)
    {
        if(Z[lig][j]=='_')
        {
            complet=FALSE;
        }
        j++;
    }
    return complet;
}

BOOL colonne_complete(char** Z,int dim, int col)
{
    BOOL complet = TRUE;
    int i=0;
    while(complet==TRUE && i<dim)
    {
        if(Z[i][col]=='_')
        {
            complet=FALSE;
        }
        i++;
    }
    return complet;
}

void Game_gridd(char **masque, char **game_matrix,int dim,int choice){
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
    if(choice==1) {
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                if (masque[i][j] == '0') {
                    game_matrix[i][j] = '_';
                }
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

// Fonction qui permet de voir si une ligne de la grille jeu est remplie entièrement afin de lancer les vérifications
BOOL ligne_remplie(int lig,char** game_matrix,int dim)
{
    int cpt=0;

    for(int j=0; j<dim; j++)
    {
        if(game_matrix[lig][j]=='_')
        {
            cpt++;
        }
    }

    if(cpt==0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

// Fonction qui permet de voir si une colonne de la grille jeu est remplie entièrement afin de lancer les vérifications
BOOL colonne_remplie(int col,char** game_matrix,int dim)
{
    int cpt=0;

    for(int i=0; i<dim; i++)
    {
        if(game_matrix[i][col]=='_')
        {
            cpt++;
        }
    }

    if(cpt==0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

// Fonction qui permet de remettre à 0 une ligne de la grille jeu
void reset_lig(char** Z,char** test,int lig,int dim)
{
    for(int j=0;j<dim;j++)
    {
        if(test[lig][j]=='0')
        {
            Z[lig][j]='_';
        }
    }
}

// Fonction qui permet de remettre à 0 une colonne de la grille jeu
void reset_col(char** Z,char** test,int col,int dim)
{
    for(int i=0;i<dim;i++)
    {
        if(test[i][col]=='0')
        {
            Z[i][col]='_';
        }
    }
}

// Fonction qui permet de regarder si une grille jeu est pleine
BOOL matrice_pleine(char** Z,int TL)
{
    for(int i=0; i<TL ; i++)
    {
        for(int j=0; j<TL ; j++)
        {
            if(Z[i][j]=='_')
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}


/// -- FONCTIONS MENU --


void menu1(){//MENU PRINCIPAL
    char choice;
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
        scanf("%c",&choice);
    }while( ((choice>'2') || (choice<'1') ) && (choice!='q') && (choice!='Q'));

    //
    if(choice=='1'){
        menu1_1();
    }
    /*if(*choice=='2'){
    }
     */
}

void menu1_1(){ //SOUS MENU 1_1
    char choice;
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
        scanf("%c",&choice);
    }while( ((choice>'3') || (choice<'1') ) && (choice!='r') && (choice!='R'));

    // GRILLE 4X4
    if(choice=='1'){
        menu1_2(4);

    }
    // GRILLE 8X8
    if(choice=='2'){
        menu1_2(8);
    }
    // GRILLE 16X16
    if(choice=='3'){
        menu1_2(16);
    }

    // RETOUR AU MENU1
    if((choice=='r')||(choice=='R')){
        menu1();
    }
}

void menu1_2(int dim){       //SOUS MENU 1_2
    int cpt=0;
    char choice,val;
    char **game_matrix;
    char **masque;
    char(**test);
    char (**hidden_index_matrix);
    char difficulte;
    int lig_ptr;
    char col_char_ptr;
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
        scanf("%c",&choice);
    }while(((choice>'3') || (choice<'1') ) && (choice!='r') && (choice!='R'));

    // SAISIE MANUELLE MASQUE(print grille jeu et masque)
    if(choice=='1'){
        masque=create_matrix(dim);
        initialize_matrix1(dim,masque);
        menu_1_2_1(dim,masque);

    }

    // GENERER UN MASQUE AUTO(print grille jeu et masque)
    if(choice=='2'){
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
        Game_gridd(masque,game_matrix,dim,1);
        Color_Text(5,0);
        printf("   -- GRILLE JEU --\n");
        Color_Text(15,0);
        print_matrix(game_matrix,dim);
        printf("\n");
        menu1_2(dim);

    }

    // JOUER AVEC UN MASQUE AUTO
    if(choice=='3'){
        difficulte=menu_difficulte();

        test = create_matrix(dim);
        initialize_matrix0(dim,test);

        masque = create_matrix(dim);
        initialize_matrix1(dim,masque);
        generate_mask(masque,dim,test,difficulte);


        game_matrix=create_matrix(dim);
        Game_gridd(masque,game_matrix,dim,1);

        solution = create_matrix(dim);
        Game_gridd(masque,solution,dim,2); // On crée la matrice Solution

        hidden_index_matrix=masque; // Matrice où indices cachés sont représenté par un '0' <=> masque

        Color_Text(5,0);
        printf("   -- GRILLE JEU --\n");
        Color_Text(15,0);
        printf("\n");

        do{
            cpt = 0;
            saisie_securisee_jouer(dim, game_matrix, &lig_ptr, &col_char_ptr,hidden_index_matrix);
            printf("Saisir 1 ou 0:");
            fflush(stdin);
            scanf("%c", &val);
            while (val < '0' || val > '1') {
                fflush(stdin);
                printf("Erreur. Resaisir:");
                scanf("%c", &val);
            }
            // Affectation à la grille jeu
            game_matrix[lig_ptr-1][column_conversion(col_char_ptr)] = val;

            /*
            //VERIFICATIONS
            egal_lig=counter_number_line(dim,game_matrix,lig_ptr-1,column_conversion(col_char_ptr),hidden_index_matrix);
            egal_col=counter_number_column(dim,game_matrix,lig_ptr-1,column_conversion(col_char_ptr),hidden_index_matrix);


            if(egal_lig == FALSE || egal_col == FALSE)
            {
                // - 1 vie
                egal = FALSE;
            }
            if(egal_lig == TRUE && egal_col == TRUE)
            {
                // - 1 vie
                egal = TRUE;
            }
             */



           comp_lig=compare_line(dim,game_matrix,lig_ptr-1,column_conversion(col_char_ptr),hidden_index_matrix);
           comp_col=compare_column(dim ,game_matrix,lig_ptr-1,column_conversion(col_char_ptr),hidden_index_matrix);


            if(comp_lig == FALSE || comp_col == FALSE)
            {

                // - 1 vie
                comp = FALSE;
            }
            if(comp_lig == TRUE || comp_col == TRUE)
            {
                // - 1 vie
                comp = TRUE;
            }

            /*

           trois_indice_lig=compare_indice_suivant_ligne(dim,game_matrix);
           trois_indice_col=compare_indice_suivant_colonne(dim,game_matrix);

           if(trois_indice_lig == FALSE ||  trois_indice_col== FALSE)
           {
               // - 1 vie
               printf("Il y a plusieurs %d d'affilés",val);
               trois_indice = FALSE;
               game_matrix[lig_ptr-1][column_conversion(col_char_ptr)] = '_';
           }


           correct=compare_game_with_solution(lig_ptr,col_char_ptr,game_matrix,solution);
           if(correct == FALSE){
               printf("Coup valide mais incorrect...\n");
               printf("Re-essayer\n");
           }
            */

        }while((comp==FALSE)|| (egal==FALSE) || (matrice_pleine(game_matrix,dim) == FALSE));
        printf("\nBravo\n");
        menu1_2(dim);



    }

    // RETOUR AU MENU1_1
    if((choice=='r')||(choice=='R')){
        menu1_1();
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
        Game_gridd(masque,game_matrix,dim,1);
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
    printf("Saisir :");
    fflush(stdin);
    scanf("%c",&difficulty_choice);
    while(difficulty_choice<'1' || difficulty_choice>'3'){
        printf("Saisie incorrect. Resaisir:");
        scanf("%c",&difficulty_choice);
    }
    return difficulty_choice;
}
// FIN FONCTIONS MENU

