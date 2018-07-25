#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_ROW 6
#define MAX_COL 6
#include "stack.h"
typedef struct  Maze
{
	int _map[MAX_ROW][MAX_COL];
}Maze;
void InitMaze(Maze* m, int map[MAX_ROW][MAX_COL]);
void PrintMaze(Maze *m);
void PassMazeNor(Maze *m, Position enter,pSeqStack s);
void PassMaze(Maze *m, Position enter, Position pcur);
int _PassMaze(Maze *m, Position enter, Position pcur);
void PrintPath(pSeqStack s);