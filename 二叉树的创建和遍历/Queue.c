#include "Queue.h"
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
// 队列的初始化
void QueueInit(Queue* q){
	assert(q);
	q->_pHead = NULL;
	q->_pTail = NULL;
}
// 检测队列是否为空
int QueueEmpty(Queue* q){
	assert(q);
	if (q->_pHead == NULL)
		return 1;
	return 0;
}
PQueueNode Queue_BuyNode(QueueDataType data){
	PQueueNode pNewNode = NULL;
	pNewNode = (PQueueNode)malloc(sizeof(QueueNode));
	if (pNewNode == NULL)
		return NULL;
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}
// 入队列
void QueuePush(Queue* q, QueueDataType data){
	assert(q);
	PQueueNode pNewNode = NULL;
	pNewNode = Queue_BuyNode(data);
	if (QueueEmpty(q))
	{
		q->_pHead = pNewNode;
		q->_pTail = pNewNode;
		
	}
	else{ q->_pTail->_pNext = pNewNode; 
	q->_pTail = q->_pTail->_pNext;
	}
	
}

// 出队列
void QueuePop(Queue* q){
	PQueueNode pcur = NULL;
	assert(q);
	if (QueueEmpty(q))
		return;
	pcur = q->_pHead;
	q->_pHead = q->_pHead->_pNext;
	free(pcur);
}
// 取队头元素
QueueDataType QueueFront(Queue* q){
	assert(q);
	if (QueueEmpty(q))
		return NULL;
	return (q->_pHead)->_data;
}

// 取队尾元素
QueueDataType QueueBack(Queue* q){
	assert(q);
	if (QueueEmpty(q))
		return NULL;
	return (q->_pTail)->_data;
}

// 获取队列中元素的个数
int QueueSize(Queue* q){
	int count = 1;
	assert(q);
	if (QueueEmpty(q))
		return 0;
	while (q->_pTail!=q->_pHead)
	{
		count++;
		q->_pHead = q->_pHead->_pNext;
	}
	return count;
}