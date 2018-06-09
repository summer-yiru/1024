#include "stack.h"
#include <stdlib.h>
#include<stdio.h>
SeqStack s;
int main(){
	StackInit(&s);
	StackPush(&s, 3);
	StackPush(&s, 5);
	StackPush(&s, 7);
	StackPush(&s, 9);
	StackPush(&s, 0);
    StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	printf("%d ", StackTop(&s));
	printf("%d ", StackSize(&s));
    system("pause");
	return 0;
}