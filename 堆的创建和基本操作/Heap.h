#pragma once
//指针可以赋值,类型不可以赋值
typedef int(*Compare)(DataType , DataType );//compare是一个类型
typedef int DataType;
typedef struct Heap
{
	DataType* _array;
	int _capacity;
	int _size;
	Compare _compare;
}Heap;
void HeapCreate(Heap *hp, DataType*array, int size, Compare com);
void PrintfHeap(Heap hp);
void InsertHeap(Heap *hp, DataType data);
void DeleteHeapTop(Heap *hp);
int SizeHeap(Heap *hp);
//大堆
int Greater(DataType left, DataType right);
//小堆
int Less(DataType left, DataType right);