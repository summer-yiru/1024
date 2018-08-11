#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
int yongsearch(int arr[ROW][COL],int key){
	int i = 0;
	int j = COL - 1;
	int tmp = arr[i][j];
	while (1)
	{
		if (key == tmp)
		{
			return 1;
		}
		else if (tmp<key&&j>=0){
			tmp = arr[i++][j];
		}
		else if (tmp>key&&j>=0){
			tmp = arr[i][j--];
		}
		else {
			return 0;
		}

	}
}
int main(){
	int arr[ROW][COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i = 0;
	int j = 0;
	int key = 0;
	int ret = 0;
	printf("请输入要查找的数\n");
	scanf("%d", &key);
	printf("数组为:\n");
	for (i = 0; i < ROW;i++){
		for (j = 0; j < COL;j++){
			printf("%3d",arr[i][j]);
		}
		printf("\n");
	}
	ret = yongsearch(arr,key);
	if (ret==1){
		printf("找到了");
	}
	else
	{
		printf("找不到");
	}
	system("pause");
	return 0;
}