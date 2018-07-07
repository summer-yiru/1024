#include "stack.h"
#include <malloc.h>
#include <stdlib.h>
#include<stdio.h>
void StackInit(pSeqStack s){
	s->_bottom = (DataType *)malloc(MaxSize*sizeof(DataType));
	if (s->_bottom == NULL)
		return;
	s->_top = s->_bottom;
	s->stacksize = MaxSize;
}
// 入栈
//假如原来的内存后面还有足够多剩余内存的话，realloc的内存=原来的内存+剩余内存,realloc还是返回原来内存的地址;
//假如原来的内存后面没有足够多剩余内存的话，realloc将申请新的内存，
//然后把原来的内存数据拷贝到新内存里，原来的内存将被free掉,realloc返回新内存的地址
void StackPush(pSeqStack s, DataType data){
	if ((s->_top)-(s->_bottom)>=MaxSize)
	{
		s->_bottom = (DataType *)realloc(s->_bottom, sizeof(DataType)*(s->stacksize + AddSize));
		if (s->_bottom == NULL)
			return;
		s->_top = s->stacksize + s->_bottom;
		s->stacksize += AddSize;
	}
	*(s->_top) = data;
	//printf("%d ", *(s->_top));
	(s->_top)++;
	
}

// 出栈
void StackPop(pSeqStack s){
	if (s->_top == s->_bottom)
		return;
   (s->_top)--;
  // printf("%d ", *(s->_top));
}
// 获取栈顶元素
DataType StackTop(pSeqStack s){
	if (StackEmpty(s))
		return -1;
	return *((s->_top)-1);

}

// 有效元素的个数
int StackSize(pSeqStack s){
	return (s->_top) - (s->_bottom);

}

// 检测栈是否为空
int StackEmpty(pSeqStack s){
	return s->_top==s->_bottom;// 若两者相等,表达式的结果为真,返回1;不相等返回0;
}

