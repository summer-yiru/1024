#include "QuickSort.h"
#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
	int ret = 0;
	ret = *a;
	*a = *b;
	*b = ret;
}
//设定一个基准值,在保证不越界的情况下,从前往后查找比基准值小的元素,找到了然后停下来,若begin和end没有相遇,就交换,相遇了
//就交换begin和数组中基准值所代表的元素
int partion_hoare(int *array, int left, int right){
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];
	while (begin<end)
	{
		while ((begin<end)&&array[begin]<key)
		   begin++;
		while ((begin<end)&&array[end]>=key)
		   end--;
		if (begin<end)
		   swap(&array[begin], &array[end]);
		
	}
	if (begin!=right-1)
	   swap(&array[begin], &array[right-1]);
	return begin;
}
//快速排序---挖坑法
int partion_WK(int *array, int left, int right){
	int begin = left;
	int end = right-1;
	int key = array[right - 1];
	while (begin<end)
	{
		while (begin<end&&array[begin]<key)
		  begin++;
		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}
		while (begin<end&&array[end]>key)
			end--;
		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}
	if (begin!=right-1)
	{
		array[begin] = key;
	}
	return begin;
}
//快速排序---前后指针
int partion_P(int *array, int left, int right){
	int pre = left-1;
	int pcur = left;
	int key = array[right - 1];
	while (pcur<right)
	{
		if (array[pcur] < key&&(++pre) != pcur)
			swap(&array[pre], &array[pcur]);
		pcur++;
		
	}
	if ((++pre)!=right-1)
	{
		swap(&array[pre], &array[right-1]);
	}
	return pre;
}
void QuickSort(int *array,int left,int right){
	if (right-left>1)
	{
		int base = partion_hoare(array, left, right);
        //int base = partion_WK(array, left, right);
		//int base = partion_P(array, left, right);
		QuickSort(array, 0, base);
		QuickSort(array,base+1,right);
	}
}
int main(){
	int i = 0;
	//int arr[] = {2,0,4,9,3,6,8,7,1,5};
	int arr[] = {1,2,3,4,5,6};
	int size = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr,0,size);
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}