#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
int Is_valid_Stack(int *In,int In_szie, int *Out,int Out_size){
	int In_index = 0;
	int Out_index = 0;
	SeqStack s;
	if (In_szie != Out_size)
		return 0;
	StackInit(&s);
	while (Out_index<Out_size)
	{
		while (StackEmpty(&s)||StackTop(&s)!=Out[Out_index])
		{
			if (In_index < In_szie)
				StackPush(&s, In[In_index++]);
			else
				return 0;
		}
		StackPop(&s);
		Out_index++;
	}
	return 1;
}
int main(){
	int In[] = {1,2,3,4,5};
	int Out[] = {4,5,3,2,1};
	int ret = 0;
	int In_size = sizeof(In) / sizeof(In[0]);
	int Out_size = sizeof(Out) / sizeof(Out[0]);
	ret = Is_valid_Stack(In,In_size,Out,Out_size);
	if (ret == 1)
		printf("合法\n");
	else
		printf("不合法\n");
	system("pause");
	return 0;
}