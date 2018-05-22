#include "SeqListD.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
void PrintSeqList(PSeqListD pSeq){
	size_t i;
	assert(pSeq);
	for (i = 0; i < pSeq->_size; i++){
		printf("%d ", pSeq->_array[i]);
	}
	printf("\n");
}
//顺序表初始化
void SeqListDInit(PSeqListD pSeq){
	pSeq->_size = 0;
	pSeq->_capacity = 2;
	pSeq->_array = (DataType *)malloc(pSeq->_capacity*sizeof(DataType));
	if (NULL==pSeq->_array){
		printf("初始化失败");
	}
}
// 检测顺序表是否需要增容
int CheckCapacity(PSeqListD pSeq){
	DataType* temp = pSeq->_array;
	assert(pSeq);
	if (pSeq->_size>=pSeq->_capacity){//满足条件说明顺序表已满，再想执行插入操作就得增容;
		DataType newCapacity = 2 * pSeq->_capacity;
		pSeq->_array =(DataType *)realloc(pSeq->_array, newCapacity*sizeof(DataType));
		if (NULL==pSeq->_array){
			pSeq->_array = temp;
			printf("扩容失败");
			return -1;
		}
		else{
			pSeq->_capacity = newCapacity;
		}
	}

	return 1;
}
//尾插
void SeqListDPushBack(PSeqListD pSeq, DataType data){
	int ret = 0;
	assert(pSeq);
	ret = CheckCapacity(pSeq);
	if (ret==1){
		pSeq->_array[pSeq->_size] = data;
		pSeq->_size++;
	}
}
//尾删
void SeqListDPopBack(PSeqListD pSeq){
	assert(pSeq);
	if (pSeq->_size==0){
		return;
	}
	pSeq->_size--;
}
//判空
int SeqListDEmpty(PSeqListD pSeq){
	assert(pSeq);
	return pSeq->_size == 0;
}
//有效元素个数;
int SeqListDSize(PSeqListD pSeq){
	assert(pSeq);
	return pSeq->_size;
}
// 清空顺序表中的所有元素，注意不改变底层空间的大小
void SeqListDClear(PSeqListD pSeq){
	size_t i;
	assert(pSeq);
	for (i = 0; i < pSeq->_size;i++){
		pSeq->_array[i] = 0;
	}

}
int SeqListDCapacity(PSeqListD pSeq){
	assert(pSeq);
	return pSeq->_capacity;
}
// 销毁顺序表
void SeqListDDestroy(PSeqListD pSeq){
	assert(pSeq);
	free(pSeq->_array);
	pSeq->_capacity = 0;
	pSeq->_size = 0;
}

