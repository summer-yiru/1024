#include "LinkStack.h"
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
void StackInit(LinkStack *s){
	pStackNode  p = NULL;
	p = (pStackNode)malloc(sizeof(StackNode));
	if (p == NULL)
		return;
	p->next = NULL;
	s->top = p;
	s->stackSize = 0;
}
//栈顶--->1--->2--->3---栈底--->NULL
// 入栈
void StackPush(pLinkStack s, DataType data){
	pStackNode newnode = NULL;
	newnode = (pStackNode)malloc(sizeof(StackNode));
	if (newnode == NULL)return;
	newnode->data = data;
	newnode->next = s->top;
	s->top = newnode;
	(s->stackSize)++;
	//printf("%d ", top->data);
}

// 出栈
void StackPop(pLinkStack s){
	pStackNode pcur;
   if(StackEmpty(s))
	   return;
	pcur = s->top;
    s->top = pcur->next;
    free(pcur);
	(s->stackSize)--;
	//printf("%d ", (top)->data);
}

// 获取栈顶元素
DataType StackTop(pLinkStack s){
	if (s->top != NULL)
		return s->top->data;

}

// 有效元素的个数
int StackSize(pLinkStack s)
{
	return s->stackSize;
}

// 检测栈是否为空
int StackEmpty(pLinkStack s){
	return s->stackSize == 0;
}
void PrintfLinkStack(LinkStack s){
	pStackNode pcur = NULL;
	if (s.stackSize== NULL||s.top==NULL)
		return;
	pcur = s.top;
	while (pcur->next)
	{
		printf("%d ", pcur->data);
		pcur = pcur->next;
	}
}