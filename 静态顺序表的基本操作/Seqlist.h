#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 10
typedef int DateType;
typedef unsigned int size_t;
typedef struct seqlist
{
	DateType array[MAX];
	int size;//数组中有效元素的个数
}Seqlist,*pSeqlist;//Seqlist===struct seqlist     pSeqlist===struct seqlist*
//顺序表的初始化
void InitSeqlist(pSeqlist);
//顺序表的打印
void Printf(pSeqlist);
//顺序表尾插
void PushBack(pSeqlist, DateType);
//顺序尾删
void PopBack(pSeqlist);
//顺序头插
void PushFront(pSeqlist,DateType);
//顺序头删
void PopFront(pSeqlist);
//插入任意位置的操作
void Insert(pSeqlist, size_t, DateType);
//删除任意位置的操作
void Erase(pSeqlist, size_t);
// 在顺序表中查找值为data的元素，返回该元素在顺序表中的下标
int SeqListFind(pSeqList, DataType);
// 删除顺序表中值为data的元素
void SeqListRemove(pSeqList, DataType);
// 删除顺序表中所有值为data的元素
void SeqListRemoveAll(pSeqList, DataType);
// 判断顺序表是否为空
int SeqListEmpty(pSeqlist);
// 获取顺序表中元素的个数
int SeqListSize(pSeqlist);
// 用冒泡排序对顺序表中的元素进行排序
void BubbleSort(int* array, int size);
// 用选择排序对顺序表中的元素进行排序
void SelectSort(int* array, int size);
// 选择排序优化---一次找出最大最小元素所在的位置
void SelectSort_OP(int* array, int size);