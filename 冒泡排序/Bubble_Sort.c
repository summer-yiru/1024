#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
	int ret = 0;
	ret = *a;
	*a = *b;
	*b = ret;
}
void Bubble_sort(int *arr,int size){
	int i = 0;
	int j = 0;
	for ( i = 0; i < size-1; i++)
	{
		for (j = 0; j < size-1-i; j++)
		{
			if (arr[j]>arr[j+1])//这是升序的写法,降序将改为if(arr[j]<arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}
int main(){
	int i = 0;
	int arr[10] = { 2, 0, 4, 9, 3, 6, 8, 7, 1, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Bubble_sort(arr,size);
	for ( i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}