#include "Queue.h"
#include<stdio.h>
#include<stdlib.h>
Queue q;
int main(){
	int ret = 0;
	QueueInit(&q);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	QueuePush(&q, 7);
	ret = QueueSize(&q);
	printf("%d", ret);
	//ret=QueueFront(&q);
	//ret=QueueBack(&q);
	QueuePush(&q, 9);
	QueuePush(&q, 0);
	ret = QueueSize(&q);
	printf("%d", ret);
	QueuePop(&q);
	//ret=QueueFront(&q);
	//ret=QueueBack(&q);
	ret = QueueSize(&q);
	printf("%d", ret);
	system("pause");
	return 0;
}