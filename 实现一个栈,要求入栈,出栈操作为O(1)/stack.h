#ifndef FileName_H_
#define FileName_H_ 
#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 100
#define AddSize 2
typedef int _DataType;
typedef struct Min_stack_Value DataType;
typedef struct Min_stack_Value{
	_DataType _Min_Value;
	_DataType _Value;
}Min_stack_Value;
typedef struct SeqStack
{
	DataType * _bottom; //表示栈底位置
	DataType * _top; // 表示栈顶位置
	int stacksize; // 栈的大小
}SeqStack,*pSeqStack;
void StackInit(pSeqStack s);

// 入栈
void StackPush(pSeqStack s, DataType data);

// 出栈
void StackPop(pSeqStack s);

// 获取栈顶元素
DataType StackTop(pSeqStack s);

// 有效元素的个数
int StackSize(pSeqStack s);

// 检测栈是否为空
int StackEmpty(pSeqStack s);
#endif