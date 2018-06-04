#include "BitMap.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
	BitMap bmp;
	int i = 0;
	int len = 0;
	int array[] = {1,3,7,4,12,16,19,13,22,18};
	BitMapInit(&bmp, 24);
	len = sizeof(array) / sizeof(array[0]);
	for ( i = 0; i < len; i++)
	{
		BitMapSet_one(&bmp, array[i]);
	}
	if (BitMapTest(&bmp, 22)){
		printf("存在\n");
	}
	if (BitMapTest(&bmp, 20)){
		printf("不存在\n");
	}
	printf("%d\n", BitMapSize(&bmp));
	printf("%d\n", BitMapCount(&bmp));
	system("pause");
	return 0;
}