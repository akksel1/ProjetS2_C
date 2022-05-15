//
// Created by louka on 06/04/2022.
//
#include "fonction.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>


/// -- FONCTION UTILITE --

// Fonction qui permet de créer une matrice dynamique
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

// Permet d'afficher la grille jeux
void print_matrix(char (**Z),int TL,int lig, int col,int choice)
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
            // PRINT EN VIOLET LQ C'EST BON
            if(lig==i && col==j && choice==1){
                Color_Text(5, 0);
                printf("%c  ", Z[i][j]);
                Color_Text(15, 0);
            }
            else{
                // PRINT EN ROUGE LQ C'EST PAS BON
                if(lig==i && col==j && choice==2) {
                    Color_Text(4, 0);
                    printf("%c  ", Z[i][j]);
                    Color_Text(15, 0);
                }
                else {
                    printf("%c  ", Z[i][j]);
                }
            }
        }
        printf("\n");
    }

}

// Permet d'afficher la grille mask
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

// Permet initialiser la matrice a 0
void initialize_matrix0(int TL,char**Z){
    for(int i=0;i<TL;i++)
    {
        for(int j=0;j<TL;j++)
        {
            Z[i][j]='0';
        }
    }
}

// Permet initialiser la matrice en dur
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

// Permet initialiser la matrice a 1
void initialize_matrix1(int TL,char**Z){
    for(int i=0;i<TL;i++)
    {
        for(int j=0;j<TL;j++)
        {
            Z[i][j]='1';
        }
    }
}

// Fonction saisie sécurisée dans le mode "jouer"
void saisie_securisee_jouer(int size, char** game_matrix,int *lig_ptr,char *col_char_ptr, char ** test) {
    int cpt, col, verif;
    int lig;
    char col_char;
    BOOL cache = FALSE;

    fflush(stdin);
    print_matrix(game_matrix, size,100,100,0);
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

// Fonction qui copie une matrice 4x4
void copy_matrix4(char** game_matrix,char solution[4][4],int dim){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            game_matrix[i][j]=solution[i][j];
        }
    }
}

// Copie une matrice b dans et colle dans une matrice a
void copy_matrix_dyn(char** a,char** b,int dim)
{
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            a[i][j]=b[i][j];
        }
    }
}


// Fonction qui copie une matrice 8x8
void copy_matrix8(char** game_matrix,char solution[8][8],int dim){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            game_matrix[i][j]=solution[i][j];
        }
    }
}

// Fonction qui copie une matrice 16x16
void copy_matrix16(char** game_matrix,char solution[16][16],int dim){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            game_matrix[i][j]=solution[i][j];
        }
    }
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

// Fonction qui génère un indice aléatoire (Attention cela peut ralentir le programme à cause de clock))
int Random_index(int size)
{
    int nb, random;
    srand(clock());
    random = rand();
    nb = random % size;
    return nb;

}

// Fonction qui convertie les colonnes (Input: 0 Output: A)
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

// Fonction qui convertie les colonnes (Input: 0 Output: A)
char conversion_column(int y)
{
    return y+65;
}

// Fonction qui regarde si une ligne est pleine
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

// Fonction qui regarde si une colonne est pleine
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


/// -- FONCTION MASQUE / JEU --

// Fonction qui effectue le saisie manuel du masque par l'utilisateur
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

//FONCTION GENERER MASQUE
void generate_mask(char(**masque), int size, char** test, char difficulte_choice){
    // On importe une matrice masque initialisé à 1, une taille, une matrice test qui nous permet de stocker les indices déjà cachés par le programme ET une difficulté
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
        nb_case =  (0.75) * (size*size);
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
    if(difficulte_choice=='4'){
        cpt=0;
        nb_case =  1 * (size*size);
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

// Fonction qui associe la grille solution au masque pour obtenir la GRILLE JEU
void Game_gridd(char **masque, char **game_matrix,int dim,int choice,char** solution_1,int partie){
    /*
     * CHOICE 1 => On applique le masque pour créer la grille jeu
     * CHOICE 2 => On n'applique pas le masque pour créer la grille solution
     * PARTIE != 2 => Solution en dur
     */

    //INITIALISATION DE LA GRILLE SOLUTION EN DUR
    if(dim==4) {
        if(partie!=2){
            char solution[4][4] = {
                    {'1', '0', '0', '1'},
                    {'1', '0', '1', '0'},
                    {'0', '1', '1', '0'},
                    {'0', '1', '0', '1'}
            };
            copy_matrix4(game_matrix,solution,dim);
        }
        else{
            copy_matrix_dyn(game_matrix,solution_1,dim);
        }

    }


    if(dim==8) {
        if(partie!=2){
            char solution2[8][8] = {
                    {'1', '1', '0', '1','0', '1', '0', '0'},
                    {'1', '0', '1', '0','1', '0', '0', '1'},
                    {'0', '1', '0', '1','0', '0', '1', '1'},
                    {'0', '1', '1', '0','0', '1', '1', '0'},
                    {'1', '0', '1', '0','1', '1', '0', '0'},
                    {'1', '0', '0', '1','1', '0', '0', '1'},
                    {'0', '1', '0', '1','0', '1', '1', '0'},
                    {'0', '0', '1', '0','1', '0', '1', '1'}
            };
            copy_matrix8(game_matrix,solution2,dim);
        }
        else{
            copy_matrix_dyn(game_matrix,solution_1,dim);
        }

    }
    if(dim==16) {
        // /!\ CETTE GRILLE SOLUTION N'EST (potentiellement) NON VALIDE ! Veuillez changer celle-ci pour jouer avec ! Bon jeu ;) /!
         if(partie!=2){
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
         else{
             copy_matrix_dyn(game_matrix,solution_1,dim);
         }

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

// Fonction qui permet de résoudre une grille jeu manuelement
void Solve_game_gridd(int dim,char** game_matrix,char** solution,char** test, char** masque,char difficulte)
{
    char col;
    char**hidden_index_matrix;
    int vie=3,lig,val;
    BOOL egal_lig, egal_col, comp_lig, comp_col, trois_indice_lig, trois_indice_col,correct,trois_indice,egal,comp;


    hidden_index_matrix=masque; // Matrice où indices cachés sont représenté par un '0' <=> masque

    Color_Text(5,0);
    printf("   -- GRILLE JEU --\n");
    Color_Text(15,0);
    printf("\n");


    do{
        printf("Saisir LIGNE/COLONNE\n");
        if(vie==3)
        {
            printf("%41cVIE\n",' ');
            Color_Text(2,0);
            printf("%40c%c %c %c\n",' ',3,3,3);
            Color_Text(15,0);
        }
        if(vie==2)
        {
            printf("%40cVIE\n",' ');
            Color_Text(14,0);
            printf("%40c%c %c\n",' ',3,3);
            Color_Text(15,0);
        }
        if(vie==1)
        {
            printf("%39cVIE\n",' ');
            Color_Text(4,0);
            printf("%40c%c\n",' ',3);
            Color_Text(15,0);
        }

        saisie_securisee_jouer(dim, game_matrix, &lig, &col,hidden_index_matrix);
        printf("Saisir 1 ou 0:");
        fflush(stdin);
        scanf("%c", &val);
        while (val < '0' || val > '1') {
            fflush(stdin);
            printf("Erreur. Resaisir:");
            scanf("%c", &val);
        }
        // Affectation à la grille jeu
        game_matrix[lig-1][column_conversion(col)] = val;

        correct=compare_game_with_solution(lig-1, column_conversion(col),game_matrix,solution);

        if(correct == FALSE) //Pas égal a la grille solution mais teste de la validite du coup
        {

            egal_lig=counter_number_line(dim,game_matrix,lig-1,column_conversion(col),hidden_index_matrix,1);
            egal_col=counter_number_column(dim,game_matrix,lig-1,column_conversion(col),hidden_index_matrix,1);
            if((egal_lig == TRUE) && (egal_col == TRUE))
            {
                egal = TRUE; // NB 0 == NB 1 donc ok
            }

            if((egal_lig == FALSE) || (egal_col == FALSE))
            {
                egal = FALSE;
                vie=vie-1;
            }


            trois_indice_lig=compare_indice_suivant_lig(dim,game_matrix,hidden_index_matrix,lig-1, column_conversion(col),1);
            trois_indice_col=compare_indice_suivant_col(dim,game_matrix,hidden_index_matrix,lig-1, column_conversion(col),1);
            // FALSE => il n'y a pas trois fois de 1 ou de 0 de suite
            if(trois_indice_lig == FALSE && trois_indice_col == FALSE)
            {
                // - 1 vie
                trois_indice = FALSE;
            }

            if(trois_indice_lig == TRUE || trois_indice_col == TRUE)
            {
                // - 1 vie
                trois_indice = TRUE;
                vie--;
            }

            if((egal==TRUE) && (trois_indice == FALSE)) // 2 règles sont respectées
            {
                if(ligne_remplie(lig-1,game_matrix,dim) == FALSE)
                {
                    printf("Coup valide mais incorrect...\n");
                    game_matrix[lig-1][column_conversion(col)]='_';
                }
                else
                {
                    comp_lig=compare_line(dim,game_matrix,lig-1,column_conversion(col),hidden_index_matrix,1);
                    comp_col=compare_column(dim ,game_matrix,lig-1,column_conversion(col),hidden_index_matrix,1);

                    // TRUE => Tout est bon
                    if(comp_col == TRUE && comp_lig == TRUE)
                    {
                        // - 1 vie
                        comp = TRUE;
                    }
                    if(comp_col == FALSE || comp_lig == FALSE)
                    {
                        // - 1 vie
                        comp = FALSE;
                    }

                    if(comp==TRUE)
                    {
                        printf("Coup valide mais incorrect...\n");
                        game_matrix[lig-1][column_conversion(col)]='_';
                    }
                }
            }

        }
        else// Respecte peut être les règles mais respecte la matrice solution
        {
            egal_lig=counter_number_line(dim,game_matrix,lig-1,column_conversion(col),hidden_index_matrix,1);
            egal_col=counter_number_column(dim,game_matrix,lig-1,column_conversion(col),hidden_index_matrix,1);

            if ((egal_col==FALSE) || (egal_lig==FALSE))
            {
                vie=vie-1;
            }


            trois_indice_lig=compare_indice_suivant_lig(dim,game_matrix,hidden_index_matrix,lig-1, column_conversion(col),1);
            trois_indice_col=compare_indice_suivant_col(dim,game_matrix,hidden_index_matrix,lig-1, column_conversion(col),1);

            if ((trois_indice_col==TRUE) || (trois_indice_lig==TRUE))
            {
                vie=vie-1;
            }

            comp_lig=compare_line(dim,game_matrix,lig-1,column_conversion(col),hidden_index_matrix,1);
            comp_col=compare_column(dim ,game_matrix,lig-1,column_conversion(col),hidden_index_matrix,1);

            if ((comp_lig==FALSE) || (comp_col==FALSE))
            {
                vie=vie-1;
            }


        }

    }while((matrice_pleine(game_matrix,dim) == FALSE) && (vie>0));


    if(vie>0){
        printf("\nBRAVO VOUS AVEZ REUSSI !\n\n");
    }
    else{
        printf("\nPERDU\n");
    }
}



/// -- FONCTION REGLE TAKUZU --

// Permet de comparer le nombre de 0 et de 1 sur la meme ligne
BOOL counter_number_line(int TL,char**Z,int lig,int col,char** test,int partie)
{
    char cpt;
    int un=0;
    int zero=0;
    int taillesur2;

    taillesur2 = (TL/2)+1;


    for(int j=0;j<TL;j++)
    {
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

    if (zero >= taillesur2 || un >= taillesur2)
    {
        if (partie==1)
        {

            printf("\n -1 PT : LA LIGNE %d NE CONTIENT PAS LE MEME NOMBRE DE 0 QUE DE 1\n",lig+1);
            Color_Text(1,0);
            printf("INDICE : ATTENTION IL N Y PAS LE MEME NOMBRE DE 1 ET DE 0 SUR LA LIGNE %d\n\n",lig+1);
            Color_Text(15,0);
            reset_lig(Z,test,lig,TL);
        }
        return FALSE; // Ne respecte pas la regle
    }
    return TRUE;
}

// Permet de comparer le nombre de 0 et de 1 sur la meme colonne
BOOL counter_number_column(int TL ,char**Z,int lig,int col,char** test, int partie)
{
    char cpt;
    int un=0;
    int zero=0;
    int taillesur2;

    taillesur2 = (TL/2)+1;


    for(int i=0;i<TL;i++)
    {
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


    if (zero >= taillesur2 || un >= taillesur2)
    {
        if (partie==1)
        {
            printf("\n-1 PT :LA COLONNE %c NE CONTIENT PAS LE MEME NOMBRE DE 0 QUE DE 1\n", conversion_column(col));
            Color_Text(1,0);
            printf("INDICE : ATTENTION IL N Y PAS LE MEME NOMBRE DE 1 ET DE 0 SUR LA COLONNE %c\n\n",conversion_column(col));
            Color_Text(15,0);
            reset_col(Z,test,col,TL);
        }
        return FALSE; // Ne respecte pas la regle
    }
    return TRUE; // respecte la regle
}

// Fonction qui vérifie que 2 colonnes ne soient pas identiques
BOOL compare_line(int TL ,char**Z,int lig,int col,char** test,int partie)
{
    char *T = (char *) malloc(TL * sizeof(char *)); // créer un tableau a dimension
    int x;
    int t;
    BOOL verif=FALSE;


    // T stock la ligne du tableau
    if(ligne_remplie(lig,Z,TL)) {
        for (int j=0; j < TL; j++)
        {
            T[j] = Z[lig][j];
        }

        // Verification ligne identique
        t=0;
        while (verif == FALSE && t < TL)
        {
            if (lig != t)
            {
                x = 0;
                verif = TRUE;
                while ((verif == TRUE) && (x < TL))
                {
                    if (T[x] != Z[t][x])
                    {
                        verif = FALSE;
                    }
                    x++;
                }

            }
            t++;
        }

        // SI LIGNE REMPLIE
        if (verif == TRUE) {
            if (partie==1)
            {
                printf("\n-1 PT : LA LIGNE %d EST IDENTIQUE \n", t + 1);
                Color_Text(1,0);
                printf("INDICE : ATTENTION LA LIGNE %d EST IDENTIQUE A UNE AUTRE\n\n",t + 1);
                Color_Text(15,0);
                reset_lig(Z, test, lig, TL);
            }
            return FALSE;
        }
        if (verif == FALSE) {
            return TRUE;
        }
    }
    return TRUE;
}

// Fonction qui vérifie que 2 colonnes ne soient pas identiques
BOOL compare_column(int TL ,char**Z,int lig,int col,char** test,int partie)
{
    char *T = (char *) malloc(TL * sizeof(char *)); // créer un tableau a dimension
    int t;
    int x;
    BOOL verif=FALSE;


    // Verification colonne identique

    if(colonne_remplie(col,Z,TL)) {
        for (int i=0; i< TL; i++)
        {
            T[i] = Z[i][col];
        }

        // Verification ligne identique
        x=0;
        while (verif == FALSE && x < TL)
        {
            if (col != x)
            {
                t = 0;
                verif = TRUE;
                while ((verif == TRUE) && (t < TL))
                {
                    if (T[t] != Z[t][x])
                    {
                        verif = FALSE;
                    }
                    t++;
                }

            }
            x++;
        }

        // SI COLONNE REMPLIE
        if (verif == TRUE)
        {
            if (partie==1)
            {

                printf("\n-1 PT :LA COLONNE %d EST IDENTIQUE \n", t + 1);
                Color_Text(1,0);
                printf("INDICE : ATTENTION LA COLONNE %d EST IDENTIQUE A UNE AUTRE\n\n",t + 1);
                Color_Text(15,0);

                reset_col(Z, test, col, TL);
            }
            return FALSE;
        }
        if (verif == FALSE)
        {
            return TRUE;
        }
    }
    return TRUE;

}

// Fonction qui vérifie la règle "3 indices de suite" sur les lignes
BOOL compare_indice_suivant_lig(int TL,char**Z,char** test,int lig,int col, int partie)
{
    BOOL verif1=FALSE,verif2=FALSE,verif3=FALSE;
    int cpt=0;
    /*
     * TRUE => Identique
     * FALSE => Pas identique
     */


        if ((col < TL - 2)&&(Z[lig][col]!='_')) {
            // 2 INDICES A DROITE
            if ((Z[lig][col] == Z[lig][col + 1]) && (Z[lig][col + 1] == Z[lig][col + 2]))
            {
                verif1 = TRUE;
                if(partie==1) {
                    printf("\n-1 PT : LA LIGNE %d CONTIENT TROIS %c DE SUITE !\n", lig + 1, Z[lig][col]);
                    Color_Text(1,0);
                    printf("INDICE : ATTENTION IL Y A 3x %c DE SUITE\n\n",Z[lig][col]);
                    Color_Text(15,0);

                    // RESET
                    Z[lig][col] = '_';
                    if (test[lig][col + 1] == '0') {
                        Z[lig][col + 1] = '_';
                    }
                    if (test[lig][col + 2] == '0') {
                        Z[lig][col + 2] = '_';
                    }
                }
            }
        }

        if ((col > 1) && (Z[lig][col]!='_')) {
            // 2 INDICES A GAUCHE
            if ((Z[lig][col] == Z[lig][col - 1]) && (Z[lig][col - 1] == Z[lig][col - 2])) {
                verif2 = TRUE;
                if (partie == 1) {

                    printf("\n-1 PT : LA LIGNE %d CONTIENT TROIS %c DE SUITE !\n", lig + 1, Z[lig][col]);
                    Color_Text(1,0);
                    printf("INDICE : ATTENTION  IL Y A 3x %c DE SUITE\n\n",Z[lig][col]);
                    Color_Text(15,0);

                    // RESET
                    Z[lig][col] = '_';
                    if (test[lig][col - 1] == '0') {
                        Z[lig][col - 1] = '_';
                    }
                    if (test[lig][col - 2] == '0') {
                        Z[lig][col - 2] = '_';
                    }
                    cpt++;
                }
            }

        }

        if ((col > 0) && (col < TL - 1) && (Z[lig][col]!='_')) {
            // 1 INDICE A DROITE ET UN INDICE A GAUCHE
            if ((Z[lig][col] == Z[lig][col - 1]) && (Z[lig][col] == Z[lig][col + 1])) {
                verif3 = TRUE;

                if (partie == 1) {
                    printf("\n-1 PT : LA LIGNE %d CONTIENT TROIS %c DE SUITE !\n", lig + 1, Z[lig][col]);
                    Color_Text(1,0);
                    printf("INDICE : ATTENTION IL Y A 3x %c DE SUITE\n\n",Z[lig][col]);
                    Color_Text(15,0);

                    // RESET
                    Z[lig][col] = '_';
                    if (test[lig][col - 1] == '0') {
                        Z[lig][col - 1] = '_';
                    }
                    if (test[lig][col + 1] == '0') {
                        Z[lig][col + 1] = '_';
                    }
                    cpt++;
                }
            }
        }

    if((verif1==TRUE) || (verif2==TRUE) ||(verif3==TRUE))
    {
        return TRUE;
    }
    return FALSE;
}

// Fonction qui vérifie la règle "3 indices de suite" sur les colonnes
BOOL compare_indice_suivant_col(int TL,char**Z,char** test,int lig,int col,int partie)
{
    BOOL verif1=FALSE,verif2=FALSE,verif3=FALSE;
    int cpt=0;
    /*
     * TRUE => Identique
     * FALSE => Pas identique
     */

        if (lig < TL - 2 && (Z[lig][col]!='_'))
        {
            // 2 EN DESSOUS
            if ((Z[lig][col] == Z[lig + 1][col]) && (Z[lig + 1][col] == Z[lig + 2][col]))
            {
                verif1 = TRUE;
                if(partie==1)
                {
                    printf("\n-1 PT : LA COLONNE %c CONTIENT TROIS %c DE SUITE !\n", conversion_column(col), Z[lig][col]);
                    Color_Text(1,0);
                    printf("INDICE : ATTENTION IL Y A 3x %c DE SUITE\n\n",Z[lig][col]);
                    Color_Text(15,0);
                    // RESET
                    Z[lig][col] = '_';
                    if (test[lig + 1][col] == '0') {
                        Z[lig + 1][col] = '_';
                    }
                    if (test[lig + 2][col] == '0') {
                        Z[lig + 2][col] = '_';
                    }
                    cpt++;
                }

            }


        }

        if ((lig > 1)&&(Z[lig][col]!='_')) {
            // 2 INDICES EN HAUT
            if ((Z[lig][col] == Z[lig - 1][col]) && (Z[lig - 1][col] == Z[lig - 2][col])) {
                verif2 = TRUE;
                if (partie == 1) {
                    printf("\n-1 PT : LA COLONNE %c CONTIENT TROIS %c DE SUITE !\n", conversion_column(col), Z[lig][col]);
                    Color_Text(1,0);
                    printf("INDICE : ATTENTION IL Y A 3x %c DE SUITE\n\n",Z[lig][col]);
                    Color_Text(15,0);
                    // RESET
                    Z[lig][col] = '_';
                    if (test[lig - 1][col] == '0') {
                        Z[lig - 1][col] = '_';
                    }
                    if (test[lig - 2][col] == '0') {
                        Z[lig - 2][col] = '_';
                    }
                    cpt++;
                }
            }
        }

        if ((lig > 0) && (lig < TL - 1) &&(Z[lig][col]!='_')) {
            // 1 INDICE A DROITE ET UN INDICE A GAUCHE
            if ((Z[lig][col] == Z[lig - 1][col]) && (Z[lig][col] == Z[lig + 1][col])) {
                verif3 = TRUE;
                if (partie == 1) {
                    printf("\n-1 PT : LA COLONNE %c CONTIENT TROIS %c DE SUITE !\n", conversion_column(col),Z[lig][col]);
                    Color_Text(1, 0);
                    printf("INDICE: ATTENTION IL Y A 3x %c DE SUITE\n\n", Z[lig][col]);
                    Color_Text(15, 0);
                    // RESET
                    Z[lig][col] = '_';
                    print_matrix(test, TL, lig, col,1);
                    if (test[lig - 1][col] == '0') {
                        Z[lig - 1][col] = '_';
                    }
                    if (test[lig + 1][col] == '0') {
                        Z[lig + 1][col] = '_';
                    }
                }
            }
        }


    if((verif1==TRUE) || (verif2==TRUE) ||(verif3==TRUE))
    {
        return TRUE;
    }
    return FALSE;
}

// Fonction qui compare la grille jeu avec la grille solution
BOOL compare_game_with_solution(int line,int j,char** G,char** S)
{
    if (G[line][j]==S[line][j])
    {
        return TRUE;
    }
    return FALSE;
}

// Fonction saisie sécurisée dans le mode "saisie masque"
BOOL saisie_securisee(int size, char (**Z),int *lig_ptr,char *col_char_ptr){
    int cpt,col,verif;
    int lig;
    char col_char;

    printf("Saisir 0/0 pour arreter\n\n");
    fflush(stdin);
    print_matrix(Z, size,100,100,0);
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



/// -- FONCTIONS MENU --

// MENU POUR NAVIGUER ENTRE LA PARTIE I II ET III
void menu1(){//MENU PRINCIPAL
    char choice;
    int cpt=0;
    printf("\n\t--  MENU PRINCIPAL --\n\n");
    printf("1 - PARTIE I\n");
    printf("2 - PARTIE II\n");
    printf("3 - PARTIE III\n");
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
    }while( ((choice>'3') || (choice<'1') ) && (choice!='q') && (choice!='Q'));

    ///PARTIE I
    if(choice=='1'){
        menu_dimension1();
    }

    ///PARTIE II
    if(choice=='2')
    {
        menu_dimension2();
    }

    ///PARTIE III
    if(choice=='3'){
        menu_dimension3();
    }

}

// MENU POUR CHOISIR LA DIMENSION DANS LA PARTIE I
void menu_dimension1(){ //SOUS MENU 1_1
    char choice;
    int cpt=0;
    int ** Z=NULL;

    printf("\n\n\t--  DIMENSION DE LA GRILLE --\n");
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
        menu1_1(4);

    }
    // GRILLE 8X8
    if(choice=='2'){
        menu1_1(8);
    }
    // GRILLE 16X16
    if(choice=='3'){
        menu1_1(16);
    }

    // RETOUR AU MENU1
    if((choice=='r')||(choice=='R')){
        menu1();
    }
}

// MENU POUR CHOISIR LA DIMENSION DANS LA PARTIE II
void menu_dimension2(){ //SOUS MENU 1_1
    char choice;
    int cpt=0;
    int ** Z=NULL;

    printf("\n\n\t--  DIMENSION DE LA GRILLE --\n");
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
        partie_2(4);

    }
    // GRILLE 8X8
    if(choice=='2'){
        partie_2(8);
    }
    // GRILLE 16X16
    if(choice=='3'){
        partie_2(16);
    }

    // RETOUR AU MENU1
    if((choice=='r')||(choice=='R')){
        menu1();
    }
}

// MENU POUR CHOISIR LA DIMENSION DANS LA PARTIE III
void menu_dimension3(){ //SOUS MENU 1_1
    char choice;
    int cpt=0;
    int ** Z=NULL;

    printf("\n\n\t--  DIMENSION DE LA GRILLE --\n");
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
        menu3(4);

    }
    // GRILLE 8X8
    if(choice=='2'){
        menu3(8);
    }
    // GRILLE 16X16
    if(choice=='3'){
        menu3(16);
    }

    // RETOUR AU MENU1
    if((choice=='r')||(choice=='R')){
        menu1();
    }
}

// MENU PARTIE I
void menu1_1(int dim){
    int cpt=0,vie=3;
    char choice,val;
    char **game_matrix;
    char **masque;
    char(**test),**temp;
    char (**hidden_index_matrix);
    char difficulte;
    int lig_ptr;
    char col_char_ptr;
    char **solution;


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
        Game_gridd(masque,game_matrix,dim,1,temp,0);
        Color_Text(5,0);
        printf("   -- GRILLE JEU --\n");
        Color_Text(15,0);
        print_matrix(game_matrix,dim,100,100,0);
        printf("\n");
        free(test);
        free(game_matrix);
        free(masque);
        menu1_1(dim);

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
        Game_gridd(masque,game_matrix,dim,1,temp,0);

        solution = create_matrix(dim);
        Game_gridd(masque,solution,dim,2,temp,0); // On crée la matrice Solution

        Solve_game_gridd(dim,game_matrix,solution,test,masque,difficulte);
        free(test);
        free(game_matrix);
        free(masque);
        free(solution);
        menu1_1(dim);
    }

    // RETOUR AU MENU1_1
    if((choice=='r')||(choice=='R')){
        menu_dimension1();
    }


}

// MENU SAISIE DU MASQUE
void menu_mask_input(char (**Z),int size){
    char choice;
    print_matrix(Z,size,100,100,0);
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
        menu1_1(size);
    }
}

// MENU MASQUE
void menu_1_2_1(int dim,char** masque){
    char choice;
    char** solution;

    printf("\n  -- MASQUE & GRILLE JEU --\n\n");
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
        print_matrix(masque,dim,100,100,0);
        printf("\n");
        char **game_matrix;
        game_matrix=create_matrix(dim);
        Game_gridd(masque,game_matrix,dim,1,solution,0);
        Color_Text(5,0);
        printf("   -- GRILLE JEU --\n");
        Color_Text(15,0);
        print_matrix(game_matrix,dim,100,100,0);
        menu_1_2_1(dim,masque);

    }
    if(choice == '3'){
        initialize_matrix1(dim,masque);
        menu_1_2_1(dim,masque);
    }
    if(choice == 'R' || choice == 'r'){
        menu1_1(dim);
    }
}

// MENU POUR CHOISIR LA DIFFICULTE (1 / 2 / 3)
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

// MENU PARTIE III
void menu3(int dim)
{
    int choice;
    char difficulte;
    char** masque,**game_matrix,**solution,**test;

    printf("\n\n\n  -- MENU PARTIE III --\n\n");
    printf("1 - GENERER UNE GRILLE SOLUTION\n"); // GENERER
    printf("2 - JOUER MANUELEMENT AVEC GRILLE SOLUTION GENEREE\n"); // IL PEUT JOUER AVEC UNE GRILLE SOLUTION ALEATOIRE CHOISIR LE MASQUE
    printf("3 - LAISSER SPARTACUS JOUER AVEC LA GRILLE SOLUTION GENEREE\n"); // SPARTACUS JOUE AVEC UNE GRILLE SOLUTION GENERER
    printf("4 - RETOUR\n"); // SPARTACUS JOUE AVEC UNE GRILLE SOLUTION GENERER

    printf("Saisir :\n");
    fflush(stdin);
    scanf("%c",&choice);
    while((choice<'1') || (choice>'3') && (choice!='r') && (choice!='R'))
    {
        printf("Erreur. Resaisir:");
        scanf("%c",&choice);
    }
    if(choice == '1')
    {
        solution=partie_3(dim,1);
        menu3(dim);
    }
    if(choice == '2')
    {
        printf("\n\n\n\nVEUILLEZ PATIENTER");
        solution=partie_3(dim,0);

        printf("\n\n\n\n");
        difficulte=menu_difficulte();

        test = create_matrix(dim);
        initialize_matrix0(dim,test);

        masque = create_matrix(dim);
        initialize_matrix1(dim,masque);
        generate_mask(masque,dim,test,difficulte);
        print_matrix(masque,dim,100,100,100);

        game_matrix=create_matrix(dim);
        Game_gridd(masque,game_matrix,dim,1,solution,2);

        print_matrix(game_matrix,dim,100,100,100);

        Solve_game_gridd(dim,game_matrix,solution,test,masque,difficulte);
        Sleep(500);
        printf("La solution etait:\n");
        Sleep(500);
        print_matrix(solution,dim,100,100,100);
        menu3(dim);
    }
    if(choice == '3')
    {
        menu3(dim);
    }
    if((choice == 'R') || (choice=='r'))
    {
        menu_dimension3();
    }
}





/// -- FONCTIONS PARTIES --

// Spartacus qui résout automatiquement une grille de Takuzu
void partie_2(int dim) {
    char choice,val;
    char **game_matrix;
    char **masque;
    char(**test),**temp;
    char (**hidden_index_matrix);
    char difficulte;
    int lig=0,col=0,val_int,choice_int=0;
    char col_char_ptr;
    char **solution;
    BOOL egal_lig, egal_col, comp_lig, comp_col, trois_indice_lig, trois_indice_col,correct,trois_indice,egal,comp,testbool;

    difficulte=menu_difficulte();

    test = create_matrix(dim);
    initialize_matrix0(dim,test);

    masque = create_matrix(dim);
    initialize_matrix1(dim,masque);
    generate_mask(masque,dim,test,difficulte);


    game_matrix=create_matrix(dim);
    Game_gridd(masque,game_matrix,dim,1,temp,0);

    solution = create_matrix(dim);
    Game_gridd(masque,solution,dim,2,temp,0); // On crée la matrice Solution

    hidden_index_matrix=masque; // Matrice où indices cachés sont représenté par un '0' <=> masque

    Color_Text(5,0);
    printf("   -- GRILLE JEU --\n");
    Color_Text(15,0);
    printf("\n");


    do{
        print_matrix(game_matrix,dim,lig,col,choice_int);
        Sleep(1500);
        for(int a=0;a<dim;a++)
        {
            for(int b=0;b<dim;b++)
            {
                if(game_matrix[a][b]=='_')
                {
                    col=b;
                    break;
                }
            }
            if(game_matrix[a][col]=='_')
            {
                lig=a;
                break;
            }
        }
        choice_int=1;

        // Val aléatoire comprise entre 0 et 1
        val_int = Random_index(2);
        if(dim==4){
            Color_Text(1,0);
            printf("%20cSPARTACUS CHOISI: %d\n",' ',val_int);
            Color_Text(15,0);
        }
        if(dim==8){
            Color_Text(1,0);
            printf("%35cSPARTACUS CHOISI: %d\n",' ',val_int);
            Color_Text(15,0);
        }
        if(dim==16){
            Color_Text(1,0);
            printf("%58cSPARTACUS CHOISI: %d\n",' ',val_int);
            Color_Text(15,0);
        }

        Sleep(1500);
        // Conversion val int en char
        if (val_int == 0) {
            val = '0';
        }
        if (val_int == 1) {
            val = '1';
        }


        // Affectation à la grille jeu
        game_matrix[lig][col] = val;

        correct=compare_game_with_solution(lig, col,game_matrix,solution);

        if(correct == FALSE) //Pas égal a la grille solution mais teste de la validite du coup
        {
            egal_lig=counter_number_line(dim,game_matrix,lig,col,hidden_index_matrix,2);
            egal_col=counter_number_column(dim,game_matrix,lig,col,hidden_index_matrix,2);
            if((egal_lig == TRUE) && (egal_col == TRUE))
            {
                egal = TRUE; // NB 0 == NB 1 donc ok
            }

            if((egal_lig == FALSE) || (egal_col == FALSE))
            {
                // - 1 vie
                choice_int=2;
                egal = FALSE;
            }


            trois_indice_lig=compare_indice_suivant_lig(dim,game_matrix,hidden_index_matrix,lig, col,2);
            trois_indice_col=compare_indice_suivant_col(dim,game_matrix,hidden_index_matrix,lig, col,2);
            // FALSE => il n'y a pas trois fois de 1 ou de 0 de suite
            if(trois_indice_lig == FALSE && trois_indice_col == FALSE)
            {
                trois_indice = FALSE;
            }

            if(trois_indice_lig == TRUE || trois_indice_col == TRUE)
            {
                // - 1 vie
                choice_int=2;
                trois_indice = TRUE;
            }

            if((egal==TRUE) && (trois_indice == FALSE)) // 2 règles sont respectées
            {
                if(ligne_remplie(lig,game_matrix,dim) == FALSE)
                {
                    game_matrix[lig][col]='_';
                }
                else
                {
                    comp_lig=compare_line(dim,game_matrix,lig,col,hidden_index_matrix,2);
                    comp_col=compare_column(dim ,game_matrix,lig,col,hidden_index_matrix,2);

                    // TRUE => Tout est bon
                    if(comp_col == TRUE && comp_lig == TRUE)
                    {
                        comp = TRUE;
                    }
                    if(comp_col == FALSE || comp_lig == FALSE)
                    {
                        // - 1 vie
                        choice_int=2;
                        comp = FALSE;
                    }

                    if(comp==FALSE)
                    {
                        if(val=='0'){
                            val='1';
                        }
                        else{
                            val='0';
                        }
                        game_matrix[lig][col]=val;
                        choice_int=2;
                    }
                }
            }
            else
            {
                if(val=='0'){
                    val='1';
                }
                else{
                    val='0';
                }
                game_matrix[lig][col]=val;
                choice_int=2;
            }

        }
        else// Respecte peut être les règles et respecte la matrice solution
        {
            egal_lig=counter_number_line(dim,game_matrix,lig,col,hidden_index_matrix,2);
            egal_col=counter_number_column(dim,game_matrix,lig,col,hidden_index_matrix,2);

            if ((egal_col==FALSE) || (egal_lig==FALSE))
            {
                egal=FALSE;
                choice_int=2;
            }
            else{
                egal=TRUE;
            }


            trois_indice_lig=compare_indice_suivant_lig(dim,game_matrix,hidden_index_matrix,lig, col,2);
            trois_indice_col=compare_indice_suivant_col(dim,game_matrix,hidden_index_matrix,lig, col,2);

            if ((trois_indice_col==TRUE) || (trois_indice_lig==TRUE))
            {
                trois_indice=TRUE;
            }
            else{
                trois_indice=FALSE;
            }

            comp_lig=compare_line(dim,game_matrix,lig,col,hidden_index_matrix,2);
            comp_col=compare_column(dim ,game_matrix,lig,col,hidden_index_matrix,2);

            if ((comp_lig==FALSE) || (comp_col==FALSE))
            {
                comp=FALSE;
            }
            else{
                comp=TRUE;
            }

            if((comp == FALSE)||(egal == FALSE)||(trois_indice==TRUE))
            {
                if(val=='0'){
                    val='1';
                }
                else{
                    val='0';
                }
                game_matrix[lig][col]=val;
                choice_int=2;
            }
        }

    }while((matrice_pleine(game_matrix,dim) == FALSE));
    print_matrix(game_matrix,dim,lig,col,choice_int);
    printf("BRAVO SPARTACUS\n");
    Sleep(2500);
    printf("\n\n\n");
    menu_dimension2();
}

// Génération d'une grille solution aléatoire
char** partie_3(int dim,int choice){
    char **game_matrix;
    char **masque;
    int lig_ptr, TL, val_int;
    char col_char_ptr, val;
    char **solution;
    char (**hidden_index_matrix) = masque;
    char **test,**temp;
    BOOL egal_lig, egal_col, comp_lig, comp_col, trois_indice_lig, trois_indice_col, correct, trois_indice, egal, comp;
    BOOL verif = TRUE;

    TL = dim;

    if(dim==16){
        game_matrix= create_matrix(16);
        char game_matrix1[16][16] = {

                {'1', '0', '1', '0','0', '1', '0', '1','_', '_', '_', '_','_', '_', '_', '_'},
                {'0', '1', '1', '0','1', '0', '0', '1','_', '_', '_', '_','_', '_', '_', '_'},
                {'1', '0', '0', '1','1', '0', '1', '0','_', '_', '_', '_','_', '_', '_', '_'},
                {'0', '1', '0', '1','0', '1', '1', '0','_', '_', '_', '_','_', '_', '_', '_'},
                {'1', '0', '1', '0','0', '1', '0', '1','_', '_', '_', '_','_', '_', '_', '_'},
                {'0', '1', '1', '0','1', '0', '1', '0','_', '_', '_', '_','_', '_', '_', '_'},
                {'1', '0', '0', '1','1', '0', '1', '0','_', '_', '_', '_','_', '_', '_', '_'},
                {'0', '1', '0', '1','0', '1', '0', '1','_', '_', '_', '_','_', '_', '_', '_'},
                {'1', '0', '1', '0','0', '1', '0', '1','_', '_', '_', '_','_', '_', '_', '_'},
                {'0', '1', '1', '0','1', '0', '1', '0','_', '_', '_', '_','_', '_', '_', '_'},
                {'1', '0', '0', '1','1', '0', '0', '1','_', '_', '_', '_','_', '_', '_', '_'},
                {'0', '1', '0', '1','0', '1', '0', '1','_', '_', '_', '_','_', '_', '_', '_'},
                {'1', '0', '1', '0','0', '1', '1', '0','_', '_', '_', '_','_', '_', '_', '_'},
                {'0', '1', '1', '0','1', '0', '1', '0','_', '_', '_', '_','_', '_', '_', '_'},
                {'1', '0', '0', '1','1', '0', '0', '1','_', '_', '_', '_','_', '_', '_', '_'},
                {'0', '1', '0', '1','0', '1', '1', '0','_', '_', '_', '_','_', '_', '_', '_'}

        };
        copy_matrix16(game_matrix,game_matrix1,16);

        hidden_index_matrix = create_matrix(dim);
        initialize_matrix1(dim,hidden_index_matrix);

        for(int i=0;i<TL;i++)
        {
            for(int j=0; j<TL; j++)
            {
                if(game_matrix[i][j]=='_'){
                    hidden_index_matrix[i][j]='0';
                }
            }
        }
        if(choice==1){
            print_matrix(game_matrix, dim, 100, 100,0);
        }



        do {
            for (int i = 0; i < TL; i++) {
                for (int j = 0; j < TL; j++) {
                    if (matrice_pleine(game_matrix, TL) == FALSE) // verifier que la matrice n'est pas plein
                    {
                        if (ligne_remplie(i, game_matrix, TL) == FALSE && colonne_remplie(j, game_matrix, TL) ==
                                                                          FALSE)// verifier que la colonne et la ligne de l'indice ne sont pas deja remplis
                        {

                            /*
                             * Fonction qui permet de verifier si l'indice est caché
                             * 0 => caché
                            */

                            if (game_matrix[i][j] == '_') {
                                // Val aléatoire comprise entre 0 et 1
                                val_int = Random_index(2);

                                // Conversion val int en char
                                if (val_int == 0) {
                                    val = '0';
                                }
                                if (val_int == 1) {
                                    val = '1';
                                }


                                // Saisir l'indice random dans la matrice
                                game_matrix[i][j] = val;
                                // les Fonctions regles


                                // Permet de vérifier s'il y a le meme nombre de 0  et de 1
                                //  False -> Ne respecte pas la regle
                                //  True ->Respecte la regle
                                egal_lig = counter_number_line(dim, game_matrix, i, j, hidden_index_matrix, 2);
                                egal_col = counter_number_column(dim, game_matrix, i, j, hidden_index_matrix, 2);

                                // Verifier s'il n'y pas trois 0 d'affilé de 1 en ligne et colonne
                                //  False -> Respecte la regle
                                //  True -> Ne respecte pas la regle
                                trois_indice_lig = compare_indice_suivant_lig(dim, game_matrix, hidden_index_matrix, i, j,
                                                                              2);
                                trois_indice_col = compare_indice_suivant_col(dim, game_matrix, hidden_index_matrix, i, j,
                                                                              2);

                                // Verifier s'il n'y pas 2 ligne ou 2 colonne identique
                                //  False -> Ne respecte pas la regle
                                //  True -> Respecte la regle
                                comp_lig = compare_line(dim, game_matrix, i, j, hidden_index_matrix, 2);
                                comp_col = compare_column(dim, game_matrix, i, j, hidden_index_matrix, 2);

                                if ((egal_lig == TRUE) && (egal_col == TRUE) && (comp_lig == TRUE) && (comp_col == TRUE) &&
                                    (trois_indice_lig == FALSE) && (trois_indice_col == FALSE) ) {
                                    if(choice==1){
                                        printf(" COUP SUIVANT... \n");
                                        print_matrix(game_matrix, TL, i, j,1);
                                        if(dim==4){
                                            Sleep(500);
                                        }
                                        printf("\n");
                                    }
                                } else {
                                    // Si les fonctions regles return FALSE alors retourné l'inverse de 1 -> 0
                                    if (val == '1') {
                                        val = '0';
                                    } else {
                                        val = '1';
                                    }
                                    game_matrix[i][j] = val;
                                    if(choice==1){
                                        printf(" COUP SUIVANT... \n");
                                        if(dim==4){
                                            Sleep(500);
                                        }
                                        print_matrix(game_matrix, TL, i, j,1);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
            }
            // DOUBLE VERIFICATION
            for(int a=0;a<TL;a++)
            {
                for(int b=0;b<TL;b++)
                {
                    if(hidden_index_matrix[a][b]=='0')
                    {
                        egal_lig = counter_number_line(dim, game_matrix, a, b, hidden_index_matrix, 2);
                        egal_col = counter_number_column(dim, game_matrix, a, b, hidden_index_matrix, 2);
                        if(egal_lig == FALSE || egal_col == FALSE )
                        {
                            verif = FALSE;
                            reset_col(game_matrix,hidden_index_matrix,b,dim);
                            reset_lig(game_matrix,hidden_index_matrix,a,dim);
                            //game_matrix[a][b]='_';
                            continue;
                        }

                        trois_indice_lig = compare_indice_suivant_lig(dim, game_matrix, hidden_index_matrix, a, b,2);
                        trois_indice_col = compare_indice_suivant_col(dim, game_matrix, hidden_index_matrix, a, b,2);
                        if(trois_indice_col == TRUE || trois_indice_lig == TRUE)
                        {
                            verif = FALSE;
                            reset_col(game_matrix,hidden_index_matrix,b,dim);
                            reset_lig(game_matrix,hidden_index_matrix,a,dim);
                            //game_matrix[a][b]='_';
                            continue;
                        }

                        comp_lig = compare_line(dim, game_matrix, a, b, hidden_index_matrix, 2);
                        comp_col = compare_column(dim, game_matrix, a, b, hidden_index_matrix, 2);
                        if(comp_lig == FALSE || comp_col == FALSE)
                        {
                            verif = FALSE;
                            reset_col(game_matrix,hidden_index_matrix,b,dim);
                            reset_lig(game_matrix,hidden_index_matrix,a,dim);
                            //game_matrix[a][b]='_';
                            continue;
                        }

                    }
                }

            }
        }while(matrice_pleine(game_matrix,dim)==FALSE);
    }
    else {
        test = create_matrix(dim);
        initialize_matrix0(dim, test);

        masque = create_matrix(dim);
        initialize_matrix1(dim, masque);
        generate_mask(masque, dim, test, '4');


        game_matrix = create_matrix(dim);
        Game_gridd(masque, game_matrix, dim, 1,temp,0);

        solution = create_matrix(dim);
        Game_gridd(masque, solution, dim, 2,temp,0); // On crée la matrice Solution

        hidden_index_matrix = masque; // Matrice où indices cachés sont représenté par un '0' <=>
        do {
            for (int i = 0; i < TL; i++) {
                for (int j = 0; j < TL; j++) {
                    if (matrice_pleine(game_matrix, TL) == FALSE) // verifier que la matrice n'est pas plein
                    {
                        if (ligne_remplie(i, game_matrix, TL) == FALSE && colonne_remplie(j, game_matrix, TL) ==
                                                                          FALSE)// verifier que la colonne et la ligne de l'indice ne sont pas deja remplis
                        {

                            /*
                             * Fonction qui permet de verifier si l'indice est caché
                             * 0 => caché
                            */

                            if (game_matrix[i][j] == '_') {
                                // Val aléatoire comprise entre 0 et 1
                                val_int = Random_index(2);

                                // Conversion val int en char
                                if (val_int == 0) {
                                    val = '0';
                                }
                                if (val_int == 1) {
                                    val = '1';
                                }


                                // Saisir l'indice random dans la matrice
                                game_matrix[i][j] = val;
                                // les Fonctions regles


                                // Permet de vérifier s'il y a le meme nombre de 0  et de 1
                                //  False -> Ne respecte pas la regle
                                //  True ->Respecte la regle
                                egal_lig = counter_number_line(dim, game_matrix, i, j, hidden_index_matrix, 2);
                                egal_col = counter_number_column(dim, game_matrix, i, j, hidden_index_matrix, 2);

                                // Verifier s'il n'y pas trois 0 d'affilé de 1 en ligne et colonne
                                //  False -> Respecte la regle
                                //  True -> Ne respecte pas la regle
                                trois_indice_lig = compare_indice_suivant_lig(dim, game_matrix, hidden_index_matrix, i, j,
                                                                              2);
                                trois_indice_col = compare_indice_suivant_col(dim, game_matrix, hidden_index_matrix, i, j,
                                                                              2);

                                // Verifier s'il n'y pas 2 ligne ou 2 colonne identique
                                //  False -> Ne respecte pas la regle
                                //  True -> Respecte la regle
                                comp_lig = compare_line(dim, game_matrix, i, j, hidden_index_matrix, 2);
                                comp_col = compare_column(dim, game_matrix, i, j, hidden_index_matrix, 2);

                                if ((egal_lig == TRUE) && (egal_col == TRUE) && (comp_lig == TRUE) && (comp_col == TRUE) &&
                                    (trois_indice_lig == FALSE) && (trois_indice_col == FALSE)) {
                                    if(choice==1){
                                        printf(" COUP SUIVANT... \n");
                                        print_matrix(game_matrix, TL, i, j,1);
                                        if(dim==4){
                                            Sleep(500);
                                        }
                                        printf("\n");
                                    }
                                } else {
                                    // Si les fonctions regles return FALSE alors retourné l'inverse de 1 -> 0
                                    if (val == '1') {
                                        val = '0';
                                    } else {
                                        val = '1';
                                    }
                                    game_matrix[i][j] = val;
                                    if(choice==1){
                                        printf(" COUP SUIVANT... \n");
                                        if(dim==4){
                                            Sleep(500);
                                        }
                                        print_matrix(game_matrix, TL, i, j,1);
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
            }
            // DOUBLE VERIFICATION
            for(int a=0;a<TL;a++)
            {
                for(int b=0;b<TL;b++)
                {
                    if(hidden_index_matrix[a][b]=='0')
                    {
                        egal_lig = counter_number_line(dim, game_matrix, a, b, hidden_index_matrix, 2);
                        egal_col = counter_number_column(dim, game_matrix, a, b, hidden_index_matrix, 2);
                        if(egal_lig == FALSE || egal_col == FALSE )
                        {
                            verif = FALSE;
                            reset_col(game_matrix,hidden_index_matrix,b,dim);
                            reset_lig(game_matrix,hidden_index_matrix,a,dim);
                            //game_matrix[a][b]='_';
                            continue;
                        }

                        trois_indice_lig = compare_indice_suivant_lig(dim, game_matrix, hidden_index_matrix, a, b,2);
                        trois_indice_col = compare_indice_suivant_col(dim, game_matrix, hidden_index_matrix, a, b,2);
                        if(trois_indice_col == TRUE || trois_indice_lig == TRUE)
                        {
                            verif = FALSE;
                            reset_col(game_matrix,hidden_index_matrix,b,dim);
                            reset_lig(game_matrix,hidden_index_matrix,a,dim);
                            //game_matrix[a][b]='_';
                            continue;
                        }

                        comp_lig = compare_line(dim, game_matrix, a, b, hidden_index_matrix, 2);
                        comp_col = compare_column(dim, game_matrix, a, b, hidden_index_matrix, 2);
                        if(comp_lig == FALSE || comp_col == FALSE)
                        {
                            verif = FALSE;
                            reset_col(game_matrix,hidden_index_matrix,b,dim);
                            reset_lig(game_matrix,hidden_index_matrix,a,dim);
                            //game_matrix[a][b]='_';
                            continue;
                        }

                    }
                }

            }
        }while(matrice_pleine(game_matrix,dim)==FALSE);

    }
    free(masque);
    return game_matrix;

}



