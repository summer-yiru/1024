//二维数组的传参
//int arr[10][10]={0};
//1.实参arr-----形参int arr[10][10]或者是一个指向数组的指针
//2.实参(int *)arr,10*10------形参int arr,int size (i==数组下标/10  j==数组下标%10  arr[i][j])
#include "Mase.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
void InitMaze(Maze* m, int map[MAX_ROW][MAX_COL]){
	int i = 0;
	int j = 0;
	if (NULL == m)
		return;
	for (i = 0; i < MAX_ROW;i++)
	{
		for (j = 0; j < MAX_COL; j++)
			m->_map[i][j] = map[i][j];
	}
}
void PrintMaze(Maze *m){
	int i = 0;
	int j = 0;
	if (NULL == m)
		return;
	for (i = 0; i < MAX_ROW; i++)
	{
		for (j = 0; j < MAX_COL; j++)
		printf(" %d ", m->_map[i][j]);
		printf("\n");
	}
}
void PrintPath(pSeqStack s){
	Position pcur;
	if (s == NULL)
		return;
	while (StackSize(s)>1)
	{
		pcur = StackTop(s);
		printf("{%d, %d}<---", pcur._x, pcur._y);
		StackPop(s);
	}
	pcur = StackTop(s);
	printf("{%d, %d}", pcur._x, pcur._y);
}
int IsValidEnter(Maze *m, Position enter){
	if (m == NULL)
		return 0;
	if (enter._x == 0 || enter._x == MAX_ROW-1 || enter._y == 0 || enter._y == MAX_COL-1)
	return 1==m->_map[enter._x][enter._y];
	return 0;
}
int IsPass(Maze *m, Position next){
	return 1 == m->_map[next._x][next._y];
}
int IsMazeExit(Maze*m,Position pcur,Position enter){
	if (pcur._x == enter._x&&pcur._y == enter._y)
		return 0;
	if (pcur._x == 0 || pcur._x == MAX_ROW - 1 || pcur._y == 0 || pcur._y == MAX_COL - 1)
		return 1;
	return 0;
}
//迷宫的非递归写法
void PassMazeNor(Maze *m, Position enter, pSeqStack s){
    if (!IsValidEnter(m, enter))
	{
		printf("迷宫的入口有误\n");
		return;
	}
	StackPush(s, enter);
	Position next; 
	Position pcur;
	while (!StackEmpty(s))
	{
		pcur = StackTop(s);
		m->_map[pcur._x][pcur._y] = 2;
		if (pcur._x!=enter._x&&pcur._x!=enter._y)
		{
			if (pcur._x == 0 || pcur._x == MAX_ROW-1|| pcur._y == 0 || pcur._y == MAX_COL-1)
				return;
		}
		
		//走上
		next = pcur;
		next._x -= 1;
		if (IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}
		//走左
		next = pcur;
		next._y -= 1;
		if (IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}
		//走右
		next = pcur;
		next._y += 1;
		if (IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}
		//走下
		next = pcur;
		next._x += 1;
		if (IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}
		//cur步走错了;
		m->_map[pcur._x][pcur._y] = 3;
		StackPop(s);
	}
	
}

//迷宫的递归写法
void PassMaze(Maze *m, Position enter){
	if (!IsValidEnter(m, enter))
	{
		printf("迷宫的入口有误\n");
		return;
	}
	_PassMaze(m,enter,enter);
}
int _PassMaze(Maze *m, Position enter,Position pcur){
	if (IsPass(m,pcur))
	{
		Position next;
		m->_map[pcur._x][pcur._y] = 2;
		if (IsMazeExit(m, pcur, enter))
			return 1;
		//走上
		next = pcur;
		next._x -= 1;
		if (_PassMaze(m, enter, next))return 1;
        //走左
		next = pcur;
		next._y -= 1;
		if (_PassMaze(m, enter, next))return 1;
		//走右
		next = pcur;
		next._y += 1;
		if (_PassMaze(m, enter, next))return 1;
		//走下
		next = pcur;
		next._x += 1;
		if (_PassMaze(m, enter, next))return 1;
		m->_map[pcur._x][pcur._y] = 3;
	}
	return 0;
}
//对复杂迷宫进行求解---迷宫中可能有多条通路，多条路径有可能构成环 

	