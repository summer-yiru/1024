#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
//统计最大元素的位数
int GetMaxValue_BitCount(int *arr,int size){
	int i = 0;
	int count = 1;
	int ret = 10;
	for ( i = 0; i < size; i++)
	{
		while (arr[i] >= ret)
		{
			count++;
			ret *= 10;
		}
	}
	return count;
}
void _RadixSort(int *arr,int size,int *temp){
	int Max_BitCount = GetMaxValue_BitCount(arr, size);
	//存每个桶中元素的个数.
	int count[10] = { 0 };
	//存每个桶的起始地址
	int start_Addr[10] = { 0 };
	int i = 0;
	int ret = 1;
	int index = 0;
	while (Max_BitCount)
	{
		//统计个数
		for ( i = 0; i < size; i++)
		{
			count[arr[i] / ret % 10]++;
		}
		//计算地址
		for ( i = 1; i < 10; i++)
		{
			start_Addr[i] = start_Addr[i - 1] + count[i - 1];
		}
		//放置元素到临时空间中
		for (i = 0; i <size; i++){
			int Addr = arr[i]/ret% 10;
			temp[start_Addr[Addr]++] = arr[i];
		}
		//回收元素
		//memcpy函数的功能是从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中。
		//void *memcpy(void *dest, const void *src, size_t n);
		memcpy(arr,temp,size*sizeof(arr[0]));
		ret *= 10;
		Max_BitCount--;
	}

}
void RadixSort(int *arr,int size){
	int *temp = (int *)malloc(size*sizeof(arr[0]));
	if (temp==NULL)
	{
		assert(0);
		return;
	}
	_RadixSort(arr,size,temp);
	free(temp);
}
int main(){
	int arr[11] = {198,254,378,852,761,554,581,552,605,479,853};
	int size = sizeof(arr) / sizeof(arr[0]);
	RadixSort(arr,size);
	for (int  i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}