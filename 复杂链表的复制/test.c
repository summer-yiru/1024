#include "complexlist.h"
#include<stdio.h>
#include<stdlib.h>
void test(){
	PCListNode pHead1 = NULL;
	PCListNode pHead2 = NULL;
	pHead1=MakeComplexList();
	pHead2 = CopyComplexList(pHead1);
	
}
int main(){
	test();
	system("pause");
	return 0;
}