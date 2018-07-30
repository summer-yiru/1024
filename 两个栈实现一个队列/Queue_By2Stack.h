#include"stack.h"
typedef struct Queue_By2Stack
{
	SeqStack S1;
	SeqStack S2;
}Queue_By2Stack; 
void Queue_By2Stack_Init(Queue_By2Stack * Que);
void Queue_By2Stack_Push(Queue_By2Stack * Que,DataType data);
void Queue_By2Stack_Pop(Queue_By2Stack * Que);
int Queue_By2Stack_Empty(Queue_By2Stack * Que);
int Queue_By2Stack_Size(Queue_By2Stack * Que);
DataType Queue_By2Stack_Front(Queue_By2Stack * Que);
DataType Queue_By2Stack_Back(Queue_By2Stack * Que);