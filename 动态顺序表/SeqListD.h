#pragma once  //避免重复引入头文件
#define _CRT_SECURE_NO_WARNINGS 1
typedef int DataType;
typedef unsigned int size_t;
typedef struct SeqListD{
	DataType* _array;
	size_t _capacity; // 底层空间的大小
	size_t _size; // 有效元素的个数 
}SeqListD, *PSeqListD;

void SeqListDInit(PSeqListD pSeq);
void SeqListDPushBack(PSeqListD pSeq, DataType data);
void SeqListDPopBack(PSeqListD pSeq);
int SeqListDEmpty(PSeqListD pSeq);
int SeqListDSize(PSeqListD pSeq);
//打印顺序表
void PrintSeqList(PSeqListD pSeq);
// 清空顺序表中的所有元素，注意不改变底层空间的大小
void SeqListDClear(PSeqListD pSeq);
int SeqListDCapacity(PSeqListD pSeq);

// 销毁顺序表
void SeqListDDestroy(PSeqListD pSeq);

// 检测顺序表是否需要增容
int CheckCapacity(PSeqListD pSeq);
