#include "Heap.h"
#include "PriorityQueue.h"
void PriorityQueueInit(PriorityQueue *q,Compare com){
	HeapInit(&q->_hp,com);
}
void PriorityQueuePush(PriorityQueue *q, DataType data){
	InsertHeap(&q->_hp, data);
}
void PriorityQueuePop(PriorityQueue *q){
	DeleteHeapTop(&q->_hp);
}
void PriorityQueueSize(PriorityQueue *q){
	return SizeHeap(&q->_hp);
}
int PriorityQueueEmpty(PriorityQueue *q){
	return EmptyHeap(&q->_hp);
}
void PriorityQueuePrint(PriorityQueue q){
	PrintfHeap(q._hp);
}
DataType PriorityQueueTop(PriorityQueue *q){
	return GetHeapTop(&q->_hp);
}