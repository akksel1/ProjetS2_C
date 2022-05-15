//
// Created by louka on 06/04/2022.
//

#ifndef PROJETS2_C_FONCTION_H
#define PROJETS2_C_FONCTION_H
#define BOOL int
#define TL1 4

#define TRUE 1
#define FALSE 0
#define TP 32
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>


/// -- FONCTION UTILITE --
void Color_Text(int,int);
void print_matrix(char**,int,int,int,int);
void initialize_matrix0(int,char**);
void initialize_matrix1(int,char**);
char** create_matrix(int);
BOOL saisie_securisee(int,char**,int*,char*);
void saisie_securisee_jouer(int,char**,int*,char*,char**);
int Random_index(int);
void initialize_matrix_personnaliser(int,char**);
int column_conversion(char);
char conversion_column(int);
void print_mask(char**, int);
BOOL colonne_remplie(int,char**,int);
BOOL ligne_remplie(int,char**,int);
void reset_lig(char**,char**,int,int);
void reset_col(char**,char**,int,int);
BOOL matrice_pleine(char**,int);
void copy_matrix4(char**,char[4][4],int);
void copy_matrix8(char**,char[8][8],int);
void copy_matrix16(char**,char[16][16],int);
void copy_matrix_dyn(char**,char**,int);


/// -- FONCTION MASQUE / JEU --
void Mask_input(char**,int);
void generate_mask(char** , int , char** , char);
void Game_gridd(char**, char**,int,int,char**,int);
void Solve_game_gridd(int,char**,char**,char**,char**,char);


/// -- FONCTION REGLE TAKUZU --
BOOL counter_number_line(int,char**,int,int,char**,int);
BOOL counter_number_column(int,char**,int,int,char**,int);
BOOL compare_column(int ,char**,int ,int ,char**,int);
BOOL compare_line(int ,char**,int ,int ,char**,int);
BOOL compare_indice_suivant_lig(int,char**,char**,int,int,int);
BOOL compare_indice_suivant_col(int,char**,char**,int,int,int);
BOOL compare_game_with_solution(int,int,char**,char**);



/// -- FONCTIONS MENU --
void menu1();
void menu_dimension1();
void menu_dimension2();
void menu_dimension3();
void menu_mask_input(char**,int);
void menu1_1(int);
void menu_1_2_1(int,char**);
char menu_difficulte();
void menu3(int);


/// -- FONCTIONS PARTIES --
void partie_2(int);
char** partie_3(int,int);

#endif //PROJETS2_C_FONCTION_H
