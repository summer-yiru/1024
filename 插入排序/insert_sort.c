#include<stdio.h>
#include<stdlib.h>
//二分查找相比较顺序查找而言,比较的次数比较少.
//插入排序在原本升序排升序,原本逆序排逆序,元素集合接近有序时,直接插入排序效率较高.
//直接插入排序,顺序查找
void insert_sort(int *pArr, int size){
	int i = 0;
	int key = 0;
	int end = 0;
	for ( i = 1; i < size; i++)
	{
		key = pArr[i];
		end = i - 1;
		while (end>=0&&key<pArr[end])
		{
			pArr[end+1]=pArr[end];
			end--;
		}
		pArr[end + 1] = key;
	}
}
//直接插入排序,二分查找
void insert_sort_second(int *pArr, int size){
	int left = 0;
	int right = size-1;
	int mid = 0;
	int i = 0;
	int key = 0;
	for (i = 1; i < size; i++)
	{
		key = pArr[i];
		left = 0;
		right = i - 1;
		//二分查找寻找待插入元素的位置
		while (left <= right)
		{
			mid = (left + right) >> 1;
			if (key<pArr[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		//搬移left位置以后的元素
		right = i - 1;
		while (right>=left)
		{
			pArr[right + 1] = pArr[right];
			right--;
		}
		//插入元素
		pArr[left] = key;
    }
}
int main(){
	int i = 0;
	int array[9] = {2,6,4,9,5,8,7,0,1};
	int size = sizeof(array) / sizeof(array[0]);
	//insert_sort(array, size);
	insert_sort_second(array, size);
	for ( i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}