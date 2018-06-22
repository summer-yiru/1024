#include "Stack_By2Queue.h"
#include <assert.h>
void Stack_By2Queue_Init(Stack_By2Queue *S){
	assert(S);
	QueueInit(&S->Que1);
	QueueInit(&S->Que2);
}
void Stack_By2Queue_Push(Stack_By2Queue *S, DataType data){
	assert(S);
	QueuePush(&S->Que1,data);
}
void Stack_By2Queue_Pop(Stack_By2Queue *S){
	if (Stack_By2Queue_Empty(S))
		return;
	if (!QueueEmpty(&S->Que1))
	{
		while (QueueSize(&S->Que1)>1)
		{
			QueuePush(&S->Que2, QueueFront(&S->Que1));
			QueuePop(&S->Que1);
		}
		QueuePop(&S->Que1);
	}
	else
	{
		while (QueueSize(&S->Que2)>1)
		{
			QueuePush(&S->Que1, QueueFront(&S->Que2));
			QueuePop(&S->Que2);
		}
		QueuePop(&S->Que2);
	}

}
DataType Stack_By2Queue_Top(Stack_By2Queue *S){
	assert(S);
	if (Stack_By2Queue_Empty(S))
		return;
	if (!QueueEmpty(&S->Que1))
	{
		return QueueBack(&S->Que1);
	}
	else
	{
		return QueueBack(&S->Que2);
	}
}
int Stack_By2Queue_Size(Stack_By2Queue *S){
	assert(S);
	return QueueSize(&S->Que1) + QueueSize(&S->Que2);
}
int Stack_By2Queue_Empty(Stack_By2Queue *S){
	assert(S);
	return QueueEmpty(&S->Que1) && QueueEmpty(&S->Que2);
}