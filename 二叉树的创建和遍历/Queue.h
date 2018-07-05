//#ifndef __TREE_H__
//#define __TREE_H__
#pragma once
extern struct BinTreeNode;
typedef struct BinTreeNode* QueueDataType;
typedef struct QueueNode
{
	QueueDataType _data;
	struct Node* _pNext;
}QueueNode, *PQueueNode;
typedef struct Queue
{
	PQueueNode _pHead;
	PQueueNode _pTail;
}Queue;
// 队列的初始化
void QueueInit(Queue* q);

// 入队列
void QueuePush(Queue* q, QueueDataType data);

// 出队列
void QueuePop(Queue* q);

// 取队头元素
QueueDataType QueueFront(Queue* q);

// 取队尾元素
QueueDataType QueueBack(Queue* q);

// 获取队列中元素的个数
int QueueSize(Queue* q);

// 检测队列是否为空
int QueueEmpty(Queue* q);



//#endif