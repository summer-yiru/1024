#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
  {
	printf("**************************\n");
	printf("*** 1.play   0.exit    ***\n");
	printf("**************************\n");
  }
void game(){
	int num = 0;
	int input = 0;
    num = rand() % 100 + 1;
	//rand() % 100 + 1 就是一个1~100之间的随机数
	while (1)
	{
		printf("请猜数字\n");
		scanf("%d", &input);
		if (input>num){
			printf("猜大了\n");
		}
		if (input<num){
			printf("猜小了\n");
		}
		if (input==num){
			printf("恭喜你,猜对了\n");
			break;
		}
	}
}
int main(){
	int input = 0;
	srand((unsigned int)time(NULL));//随机生成一个数的初始化函数;
	do{
		menu();
		scanf("%d", &input);
		switch (input)
		{  
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
        default:
			printf("选择错误"); 
		    break;
		}
	} 
	while (input);
	system("pause");
	return 0;
}
