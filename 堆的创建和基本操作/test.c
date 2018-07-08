#include "Heap.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
	Heap hp;
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	int size = sizeof(array) / sizeof(array[0]);
	HeapCreate(&hp, array, size, Greater);
	InsertHeap(&hp, 5);
	PrintfHeap(hp);
	DeleteHeapTop(&hp);
	PrintfHeap(hp);
    system("pause");
	return 0;
}