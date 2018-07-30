#include "Min_Stack.h"
#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
	Min_Stack SM;
	Min_StackInit(&SM);
	Min_StackPush(&SM, 5);
	Min_StackPush(&SM, 6);
	Min_StackPush(&SM, 8);
	Min_StackPush(&SM, 2);
	Min_StackPush(&SM, 1);
	printf("%d \n", GetMinValue(&SM));
	printf("%d \n", Get_Top_Value(&SM));
	printf("%d \n", Min_Stack_Size(&SM));
	Min_StackPop(&SM);
	Min_StackPop(&SM);
	printf("%d \n", GetMinValue(&SM));
	printf("%d \n", Get_Top_Value(&SM));
	printf("%d \n", Min_Stack_Size(&SM));
	system("pause");
	return 0;
}