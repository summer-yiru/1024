#include "Mase.h"
#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
SeqStack s;
int main(){
	Maze m;
	Position enter;
	enter._x = 5;
	enter._y = 2;
	int map[MAX_ROW][MAX_COL] = {
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 0 },
		{ 0, 0, 1, 0, 1, 1 },
		{ 0, 0, 1, 0, 0, 0 }
	};
	StackInit(&s);
	InitMaze(&m, map);
	PrintMaze(&m);
	PassMazeNor(&m,enter,&s);
	//PassMaze(&m, enter,enter);
	printf("\n");
	PrintMaze(&m);
	PrintPath(&s);
	system("pause");
	return 0;
}