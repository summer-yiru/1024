#include "SeqListD.h"
#include<stdio.h>
#include<stdlib.h>
SeqListD seqList;
int main(){
	SeqListDInit(&seqList);
	SeqListDPushBack(&seqList, 6);
	PrintSeqList(&seqList);
	SeqListDPopBack(&seqList);
	PrintSeqList(&seqList);
	system("pause");
	return 0;
}