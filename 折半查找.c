#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void sort(int arr[],int sz){
	int i = 0;
	int j = sz - 1;
	for (i = 0; i <= j;i++){
		if (arr[i] % 2 != 0)continue;
		else{
			if (arr[j] % 2 != 0){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}


			else{
				i--;
				j--;
			}
		}
	}

}
int main()
	{
		int arr[9] = { 2, 4, 5, 7, 9, 0, 8, 1, 3 };
		int sz = sizeof(arr) / sizeof(arr[0]);
		sort(arr, sz);
		int i = 0;
		for (i = 0; i < sz;i++){
			printf("%3d", arr[i]);
		}

	printf("\n");
	system("pause");
	return 0;
}