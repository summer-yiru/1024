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
PNode BuyNode(DataType data){
	PNode pNewNode = NULL;
	pNewNode = (PNode)malloc(sizeof(Node));
	if (pNewNode == NULL)
		return NULL;
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}
// 入队列
void QueuePush(Queue* q, DataType data){
	assert(q);
	PNode pNewNode = NULL;
	pNewNode = BuyNode(data);
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
	PNode pcur=NULL;
	assert(q);
	if (QueueEmpty(q))
		return;
	pcur = q->_pHead;
	if (pcur)
	{
		q->_pHead = pcur->_pNext;
	}
	
}
// 取队头元素
DataType QueueFront(Queue* q){
	assert(q);
	if (QueueEmpty(q))
		return -1;
	return (q->_pHead)->_data;
}

// 取队尾元素
DataType QueueBack(Queue* q){
	assert(q);
	if (QueueEmpty(q))
		return -1;
	return (q->_pTail)->_data;
}

// 获取队列中元素的个数
int QueueSize(Queue* q){
	int count = 0;
	assert(q);
	PNode pcur = q->_pHead;
	if (QueueEmpty(q))
		return 0;
	while (pcur)
	{
		count++;
		pcur = pcur->_pNext;
	}
	return count;
}