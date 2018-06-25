#include "Heap.h"
#include "PriorityQueue.h"
//优先级队列里封装了一个堆
#include<stdio.h>
#include<stdlib.h>
int main(){
	PriorityQueue q;
	PriorityQueueInit(&q,Greater);
	PriorityQueuePush(&q, 3);
	PriorityQueuePush(&q, 8);
	PriorityQueuePush(&q, 2);
	PriorityQueuePush(&q, 4);
	PriorityQueuePush(&q, 9);
	//PriorityQueuePop(&q);
	printf("%d \n",PriorityQueueTop(&q));
	PriorityQueuePrint(q);
	system("pause");
	return 0;
}