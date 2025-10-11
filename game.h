#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define ROW 9//行
#define COL 9//列

#define ROWS ROW+1 
#define COLS COL+1
//初始化棋盘

void  InitBoard(char board[ROWS][COLS], int rows, int cols,char set);


void print_Board(char board[ROWS][COLS], int row, int col);


void set_bomb(char board[ROWS][COLS], int row, int col);



int count_of_bomb(char board[ROWS][COLS], int row, int col);



void find_bomb(char bomb[ROWS][COLS], char show[ROWS][COLS], int row, int col);
