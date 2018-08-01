#include "LinkStack.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
	LinkStack s;
	int ret = 0;
	StackInit(&s);
	StackPush(&s,4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	StackPush(&s, 7);
	StackPush(&s, 8);
	StackPush(&s, 9);
	StackPop(&s);
	StackPop(&s);
	//ret = StackTop(&s);
	ret = StackSize(&s);
	printf("%d\n", ret);
	PrintfLinkStack(s);
	system("pause");
	return 0;
}