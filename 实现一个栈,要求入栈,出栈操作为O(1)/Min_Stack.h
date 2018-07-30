#include "stack.h"
typedef struct Min_Stack{
	SeqStack s;
}Min_Stack;
//初始化
void Min_StackInit(Min_Stack *MS);
// 入栈
void Min_StackPush(Min_Stack *MS, _DataType data);
// 出栈
void Min_StackPop(Min_Stack* MS);
int Min_Stack_Empty(Min_Stack *MS);
_DataType Get_Top_Value(Min_Stack * MS);
_DataType GetMinValue(Min_Stack *MS);
int Min_Stack_Size(Min_Stack *MS);