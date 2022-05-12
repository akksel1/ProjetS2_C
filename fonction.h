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
void Color_Text(int,int);
void print_matrix(char**,int);
void initialize_matrix0(int,char**);
void initialize_matrix1(int,char**);
char** create_matrix(int);
BOOL counter_number_line(int,char**,int,int,char**);
BOOL counter_number_column(int,char**,int,int,char**);
BOOL compare_line(int,char**);
BOOL compare_column(int,char**);
BOOL compare_indice_suivant_ligne(int,char**);
BOOL compare_indice_suivant_colonne(int,char**);
BOOL compare_game_with_solution(int, char,char**,char**);
void Mask_input(char**,int);
void menu_mask_input(char**,int);
int column_conversion(char);
void Game_gridd(char**, char**,int,int);
void copy_matrix4(char**,char[4][4],int);
void copy_matrix8(char**,char[8][8],int);
void copy_matrix16(char**,char[16][16],int);
void menu1();
void menu1_1();
void menu1_2(int);
void menu_1_2_1(int,char**);
char menu_difficulte();
BOOL saisie_securisee(int,char**,int*,char*);
void saisie_securisee_jouer(int,char**,int*,char*,char**);
void generate_mask(char** , int , char** , charFOn);
int Random_index(int);
void initialize_matrix_personnaliser(int,char**);
char conversion_column(int);
void print_mask(char**, int);
BOOL colonne_remplie(int,char**,int);
BOOL ligne_remplie(int,char**,int);
void reset_lig(char**,char**,int,int);
void reset_col(char**,char**,int,int);
BOOL matrice_pleine(char**,int);

#endif //PROJETS2_C_FONCTION_H
