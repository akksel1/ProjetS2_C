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
void print_matrix(int**,int);
void initialize_matrix(int,int**);
int** create_matrix(int);
void menu1(char*);
void menu1_1(char*);
BOOL counter_number_line(int,int**);
BOOL counter_number_column(int,int**);
BOOL compare_line(int,int**);
void menu1_2(int, int**);
void Mask_input(int**,int);
void menu_mask_input(int**,int);



#endif //PROJETS2_C_FONCTION_H
