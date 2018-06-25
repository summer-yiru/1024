#include "Heap.h"
//优先级队列
typedef struct PriorityQueue
{
	Heap _hp;
}PriorityQueue;
//优先级队列基本操作
void PriorityQueueInit(PriorityQueue *q, Compare com);
void PriorityQueuePush(PriorityQueue *q,DataType data);
void PriorityQueuePop(PriorityQueue *q);
void PriorityQueueSize(PriorityQueue *q);
int PriorityQueueEmpty(PriorityQueue *q);
void PriorityQueuePrint(PriorityQueue q);
DataType PriorityQueueTop(PriorityQueue *q);