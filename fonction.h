//
// Created by louka on 06/04/2022.
//

#ifndef PROJETS2_C_FONCTION_H
#define PROJETS2_C_FONCTION_H
#define BOOL int
#define TL1 16

#define TRUE 1
#define FALSE 0
#define TP 32
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>



void Color_Text(int,int);
void print_matrix(char**,int);
void initialize_matrix(int,char**);
int** create_matrix(int);
BOOL counter_number_line(int,char**);
BOOL counter_number_column(int,char**);
BOOL compare_line(int,char**);
void Mask_input(char**,int);
void menu_mask_input(char**,int);
int column_conversion(char);
void Game_gridd(char**, char**,int);
void copy_matrix(char**,char[4][4],int);
void menu1(char*);
void menu1_1(char*);
void menu1_2(int);
void menu_1_2_1(int,char**);




#endif //PROJETS2_C_FONCTION_H
