#define _CRT_SECURE_NO_WARNINGS 1
typedef int DataType;
typedef struct StackNode
{
	DataType data;
	struct StackNode * next;
}StackNode,*pStackNode;
typedef struct LinkStack{
	StackNode *top;//栈顶指针
	int stackSize;//栈的当前容量
}LinkStack,*pLinkStack;
void StackInit(LinkStack *s);

// 入栈
void StackPush(pLinkStack s, DataType data);

// 出栈
void StackPop(pLinkStack s);

// 获取栈顶元素
DataType StackTop(pLinkStack s);

// 有效元素的个数
int StackSize(pLinkStack s);

// 检测栈是否为空
int StackEmpty(pLinkStack s);
//打印
void PrintfLinkStack(LinkStack s);