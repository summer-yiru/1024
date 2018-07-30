#include"Min_Stack.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
void Min_StackInit(Min_Stack *MS){
	assert(MS);
	StackInit(&MS->s);
}
//获取栈顶最小值
_DataType GetMinValue(Min_Stack *MS){
	return StackTop(&MS->s)._Min_Value;
}
// 入栈
void Min_StackPush(Min_Stack *MS, _DataType data){
	assert(MS);
	Min_stack_Value Value;
	Value._Min_Value = Value._Value = data;
	if (!StackEmpty(&MS->s))
	{
		if (Value._Min_Value>GetMinValue(MS))
		{
			Value._Min_Value = GetMinValue(MS);
		}
	}
	StackPush(&MS->s,Value);

}
//最小栈是否为空.
int Min_Stack_Empty(Min_Stack *MS){
	return 0 == StackEmpty(&MS->s);
}
// 出栈
void Min_StackPop(Min_Stack* MS){
	assert(MS);
	assert(!StackEmpty(&MS->s));
    StackPop(&MS->s);

	
}
//获取栈顶元素
_DataType Get_Top_Value(Min_Stack * MS){
	assert(MS);
	return StackTop(&MS->s)._Value;
}
int Min_Stack_Size(Min_Stack *MS){
	assert(MS);
	return StackSize(&MS->s);
}