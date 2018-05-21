#include "Heap.h"
#include<stdio.h>
#include<stdlib.h>
//向下调整 
void HeapAdjust(int *arrar,int size,int parent){
	int child = parent * 2 + 1;
	while (child<size)
	{
		if ((child + 1)<size&&arrar[child + 1]>arrar[child])
			child += 1;
		if (arrar[parent]<arrar[child])
		{
			swap(&arrar[parent], &arrar[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		  return;
	
	}
	
}
void HeapSort(int arrar[],int size){
	//1,建堆
	int root = ((size - 2) >> 1);
	int end = size - 1;
	for ( ;  root>=0; --root)
	{
		HeapAdjust(arrar, size, root);
	}
	//2,调整
	while (end)
	{
		swap(&arrar[end],&arrar[0]);
		HeapAdjust(arrar, end, 0);
        --end;
	}

}
int main(){
	int arrar[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	int size = sizeof(arrar) / sizeof(arrar[0]);
	HeapSort(arrar,size);
	for (int i = 0; i <size; i++)
	{
		printf("%d ", arrar[i]);
	}
	system("pause");
	return 0;
}