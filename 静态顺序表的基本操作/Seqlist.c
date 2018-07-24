#include "Seqlist.h"
#include<stdio.h>
#include<memory.h>
#include<assert.h>
//顺序表的初始化
void InitSeqlist(pSeqlist seq)
{
    seq->size = 0;
	memset(seq->array, 0, sizeof(seq));
}
//顺序表的打印
void Printf(pSeqlist seq)
{
	int i = 0;
	assert(seq);
	for (i = 0; i< seq->size;i++){
		printf("%d ", seq->array[i]);
	}
    printf("\n");
}
//顺序表尾插
void PushBack(pSeqlist seq, DateType data)
{ 
	assert(seq);
	if (seq->size>MAX){
		return;
	}
	seq->array[seq->size] = data;
	seq->size++;
}
//顺序尾删
void PopBack(pSeqlist seq){
	assert(seq);
	if (seq->size==0){
		return;
	}
	seq->size--;
}
//顺序头插
void PushFront(pSeqlist seq, DateType data)
{ 
	int i = 0;
	assert (seq);
	if (seq->size>MAX){
		return;
	}
	for (i = seq->size; i >0;i--){
		seq->array[i] = seq->array[i-1];
	}
	seq->array[0] = data;
	seq->size++;
}
//顺序头删
void PopFront(pSeqlist seq){
	int i = 0;
	assert(seq);
	for (; i< seq->size-1; i++){
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}
//插入任意位置的操作
void Insert(pSeqlist seq,size_t pos,DateType data){
	int i = 0;
	assert(seq);
	if (pos>=MAX){
		return;
	}
	for (i = seq->size; i>pos;i--){
		seq->array[i] = seq->array[i-1];

	}
	seq->array[pos] = data;
	seq->size++;
}
//删除任意位置的操作
void Erase(pSeqlist seq,size_t pos){
	int i = 0;
	assert(seq);
	if (pos>MAX){
		return;
	}
	for (i = pos; i < seq->size-1;i++){
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}
// 在顺序表中查找值为data的元素，返回该元素在顺序表中的下标
int SeqListFind(pSeqlist seq, DateType data){
	int i = 0;
	assert(seq);
	for (i = 0; i < seq->size;i++){
		if (seq->array[i]==data){
			return i;
		}
	}
	return -1;
}
// 删除顺序表中值为data的元素
void SeqListRemove(pSeqlist seq, DateType data){
	int ret = 0;
	assert(seq);
	ret = SeqListFind(seq,data);
	if (ret==-1){
		return;
	}
	Erase(seq, ret);
}
// 删除顺序表中所有值为data的元素
void SeqListRemoveAll(pSeqlist seq, DateType data){
	int count = 0;
	int i = 0;
	for (i = 0; i < seq->size;i++){
		if (seq->array[i]==data){
			count++;
		}
		else{
			seq->array[i - count] = seq->array[i];
		}
	}
	seq->size = seq->size - count;
}
// 判断顺序表是否为空
int SeqListEmpty(pSeqlist seq){
	assert(seq);
	if (seq->size==0){
		return 0;
	}
	return 1;
}
// 获取顺序表中元素的个数
int SeqListSize(pSeqlist seq){
	assert(seq);
	return seq->size;
}
// 用冒泡排序对顺序表中的元素进行排序
void BubbleSort(int* array, int size){
	int i = 0;
	int j = 0;
	int ret = 0;
	for (i = 0; i < size-1 ; i++){
		for (j = 0; j <size-1-i; j++){
			if (array[j]>array[j+1])
			{
				
				ret = array[j];
				array[j] = array[j + 1];
				array[j + 1] = ret;
			}
		}
		
	}
}


// 用选择排序对顺序表中的元素进行排序
//初始序列：{49 27 65 97 76 12 38}
//第1趟：12与49交换：12{ 27 65 97 76 49 38 }
//第2趟：27不动　：12 27{65 97 76 49 38}
//第3趟：65与38交换：12 27 38{97 76 49 65}
//第4趟：97与49交换：12 27 38 49{76 97 65}
//第5趟：76与65交换：12 27 38 49 65{97 76}
//第6趟：97与76交换：12 27 38 49 65 76 97 完成
void SelectSort(int* array, int size){
	int i = 0;
	int j = 0;
	int flag = 0;
	int ret = 0;
	for (i = 0; i < size - 1;i++){
        flag = i;
		for (j = i; j<size-1;j++){
			if (array[flag]>array[j + 1]){
				flag = j+1;
			}
		}
		if (flag != i){
			ret = array[flag];
			array[flag] = array[i];
			array[i] = ret;

		}
	}
}
// 选择排序优化---一次找出最大最小元素所在的位置
void swap(int *a,int *b){
	int p;
	p = *a;
	*a = *b;
	*b = p;
}
void SelectSort_OP(int* array, int size){
	
	int i = 0;
	int left = 0;
	int right = size - 1;
	
	while (left<=right)
	{
		int min = left;
		int max = right;
		for (i = left; i <=right;i++){
			if (array[i]<array[min]){
				min = i;
			}
			if (array[i]>array[max]){
				max = i;
			}
		}
		swap(&array[left], &array[min]);
		if (left == max)//最大的在最小位置上,最小的在最大
			max = min;
		swap(&array[right], &array[max]);
		left++;
		right--;
	}
}