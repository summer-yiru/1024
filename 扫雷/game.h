#ifndef __GAME_H__
#define __GAME_H__
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//初始化
void DisplayBoard(char board[ROWS][COLS], int row, int col);//展示
void SetMine(char board[ROWS][COLS], int row, int col);//设置雷
int GetMineCount(char board[ROWS][COLS], int x, int y);//获取雷的数量
char * spread(char board[ROWS][COLS], int x, int y);
#endif//__GAME_H__