#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
	int ret = 0;
	ret = *a;
	*a = *b;
	*b = ret;
}
void Selection(int *arr,int size){
	int left = 0;
	int right = size - 1;
	int i = 0;
	while (left<right)
	{
		int MinIndex = left;
		int MaxIndex = left;
		for (i = left; i <= right; i++)
		{
			if (arr[MinIndex]>arr[i])
				MinIndex = i;
			if (arr[MaxIndex]<arr[i])
				MaxIndex = i;
		}
		swap(&arr[left],&arr[MinIndex]);
		if (MaxIndex==left)
		{
			MaxIndex = MinIndex;
		}
		swap(&arr[right], &arr[MaxIndex]);
		left++;
		right--;
	}
}
int main(){
	int i = 0;
	int arr[10] = {2,5,4,9,3,6,8,7,1,0};
	int size = sizeof(arr) / sizeof(arr[0]);
	Selection(arr,size);
	for ( i = 0; i < size; i++)
	{
		printf("%d ",arr[i]);
	}
	system("pause");
	return 0;
}