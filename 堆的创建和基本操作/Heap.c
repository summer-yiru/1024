#include "Heap.h"
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
//小堆
int Less(DataType left, DataType right){
	return left < right;
}
//大堆
int Greater(DataType left, DataType right){
	return left > right;
}

//交换
void swap(DataType*a,DataType *b){
	DataType c = 0;
	assert(a);
	assert(b);
	c = *a;
	*a = *b;
	*b = c;
}
//调整堆向下
void HeapAdjustDown(Heap* hp, int parent){
	//用child来标记左右孩子中最小的元素
	int child = parent * 2 + 1;
	int size = hp->_size;
	while (child<size)
	{
		if ((child + 1)<size&&(hp->_compare(hp->_array[child+1],hp->_array[child])))
			child += 1;
		if (hp->_compare(hp->_array[child],hp->_array[parent]))
		{
			swap(&hp->_array[parent], &hp->_array[child]);
			//交换后就影响了下面的结构,需要继续调
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
	
}
//调整堆向上
void HeapAdjustUp(Heap* hp, int child){
	int parent = ((child-1)>>1);
	while (child)
	{
		if (hp->_compare(hp->_array[child],hp->_array[parent]))
		{
			swap(&hp->_array[parent], &hp->_array[child]);
			child = parent;
			parent = ((child - 1) >> 1);
		}
		else
		   return;
	}
	

}
//堆创建
void HeapCreate(Heap *hp, DataType*array, int size,Compare com){
	int i = 0;
	int root = ((size - 2) >> 1);
	if (hp == NULL)
		return;
	hp->_array = (DataType*)malloc(sizeof(DataType)*size);
	if (hp->_array==NULL)
	{
		assert(0);
		return;
	}
    //将数组的元素放到堆中去
	for (i = 0; i < size; i++)
	{
		hp->_array[i] = array[i];
	}
	hp->_size = size;
	hp->_capacity = size;
	hp->_compare = com;
   //堆调整1.向下调整
	for (; root >=0; --root)
	{
		HeapAdjustDown(hp,root);
	}
	
}
//检查堆容量  //开辟新空间,搬移元素,释放旧空间
void _CheckCapacity(Heap *hp){
	int i = 0;
	assert(hp);
	if (hp->_size==hp->_capacity)
	{
		int NewCapacity = 2 *(hp->_capacity);
		DataType *temp = (DataType*)malloc(NewCapacity*sizeof(DataType));
		if (temp==NULL)
		{
			assert(0);
			return;
		}
		for (i = 0; i < hp->_size; i++)
		{
			temp[i] = hp->_array[i];
		}
		free(hp->_array);
		hp->_array = temp;
	}

}
//向堆中插入元素
void InsertHeap(Heap *hp,DataType data){
	assert(hp);
	_CheckCapacity(hp);
	hp->_array[hp->_size++] = data;
	int child = (hp->_size) - 1;
	HeapAdjustUp(hp, child);
}
void PrintfHeap(Heap hp){
	int i = 0;
	int size = hp._size;
	for (i = 0; i < size; i++)
	{
		printf("%d ", hp._array[i]);
	}
	printf("\n");
}
int EmptyHeap(Heap *hp){
	assert(hp);
	return 0 == hp->_size;
}
//向堆中删除元素--一般删除堆顶元素
void DeleteHeapTop(Heap *hp, DataType data){
	assert(hp);
	if (EmptyHeap(hp))
		return;
	hp->_array[0] = hp->_array[hp->_size-1];
	hp->_size--;
	HeapAdjustDown(hp, 0);
}
//堆中有效的元素
int SizeHeap(Heap *hp){
	return hp->_size;
}