#include "Queue_By2Stack.h"
#include<assert.h>
void Queue_By2Stack_Init(Queue_By2Stack * Que){
	assert(Que);
	StackInit(&Que->S1);
	StackInit(&Que->S2);
}
void Queue_By2Stack_Push(Queue_By2Stack * Que, DataType data){
	assert(Que);
	StackPush(&Que->S1, data);
}
void Queue_By2Stack_Pop(Queue_By2Stack * Que){
	assert(Que);
	if (Queue_By2Stack_Empty(Que))
		return;
	if (StackEmpty(&Que->S2))
	{
		while (!StackEmpty(&Que->S1))
		{
			StackPush(&Que->S2, StackTop(&Que->S1));
			StackPop(&Que->S1);
		}
	}
	StackPop(&Que->S2);
}
int Queue_By2Stack_Empty(Queue_By2Stack * Que){
	assert(Que);
	return StackEmpty(&Que->S1)&&StackEmpty(&Que->S2);
}
int Queue_By2Stack_Size(Queue_By2Stack * Que){
	assert(Que);
	return StackSize(&Que->S1) + StackSize(&Que->S2);
}
DataType Queue_By2Stack_Front(Queue_By2Stack * Que){
	assert(Que);
	if (Queue_By2Stack_Empty(Que))
		return;
	if (StackEmpty(&Que->S2))
	{
		while (!StackEmpty(&Que->S1))
		{
			StackPush(&Que->S2, StackTop(&Que->S1));
			StackPop(&Que->S1);
		}
	}
	return StackTop(&Que->S2);
}
DataType Queue_By2Stack_Back(Queue_By2Stack * Que){
	assert(Que);
	if (Queue_By2Stack_Empty(Que))
		return;
	if (StackEmpty(&Que->S1))
	{
		while (!StackEmpty(&Que->S2))
		{
			StackPush(&Que->S1, StackTop(&Que->S2));
			StackPop(&Que->S2);
		}
	}
	return StackTop(&Que->S1);
}