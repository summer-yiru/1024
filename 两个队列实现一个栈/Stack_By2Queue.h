#include "Queue.h"
typedef struct Stack_By2Queue{
	Queue Que1;
	Queue Que2;
}Stack_By2Queue;
void Stack_By2Queue_Init(Stack_By2Queue *S);
void Stack_By2Queue_Push(Stack_By2Queue *S,DataType data);
void Stack_By2Queue_Pop(Stack_By2Queue *S);
DataType Stack_By2Queue_Top(Stack_By2Queue *S);
int Stack_By2Queue_Size(Stack_By2Queue *S);
int Stack_By2Queue_Empty(Stack_By2Queue *S);