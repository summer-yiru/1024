#include "Queue_By2Stack.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
	Queue_By2Stack S;
	Queue_By2Stack_Init(&S);
	Queue_By2Stack_Push(&S, 5);
	Queue_By2Stack_Push(&S, 6);
	Queue_By2Stack_Push(&S, 8);
	Queue_By2Stack_Push(&S, 0);
	Queue_By2Stack_Push(&S, 1);
	printf("%d ", Queue_By2Stack_Size(&S));
	printf("%d ", Queue_By2Stack_Front(&S));
	printf("%d ", Queue_By2Stack_Back(&S));
	Queue_By2Stack_Pop(&S);
	Queue_By2Stack_Pop(&S);
	printf("%d ", Queue_By2Stack_Size(&S));
	printf("%d ", Queue_By2Stack_Front(&S));
	printf("%d ", Queue_By2Stack_Back(&S));
	system("pause");
	return 0;
}