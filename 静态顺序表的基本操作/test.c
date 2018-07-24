#include "Seqlist.h"
#include<stdlib.h>
void test1(){
	Seqlist seq = {0};
	InitSeqlist(&seq);
    PushBack(&seq,10);
	PushBack(&seq, 9);
	PushBack(&seq, 8);
	PushBack(&seq, 7);
	PushBack(&seq, 6);
	Printf(&seq);
	PopBack(&seq);
	Printf(&seq);
	PushFront(&seq, 3);
	Printf(&seq);
	PopFront(&seq);
	Printf(&seq);
	Insert(&seq, 3, 5);
	Printf(&seq);
	Erase(&seq, 3);
	Printf(&seq);
	SeqListRemove(&seq, 9);
	Printf(&seq);
	Insert(&seq, 2, 5);
	Insert(&seq, 4, 5);
	Insert(&seq, 5, 5);
	Printf(&seq);
	SeqListRemoveAll(&seq,5);
	Printf(&seq);
	PushBack(&seq, 4);
	PushBack(&seq, 2);
	PushBack(&seq, 9);
	Printf(&seq);
	//BubbleSort(seq.array,seq.size);
	//Printf(&seq);
	//SelectSort(seq.array, seq.size);
	//Printf(&seq);
	SelectSort_OP(seq.array, seq.size);
	Printf(&seq);
}
int main(){
	test1();
	system("pause");
	return 0;
}