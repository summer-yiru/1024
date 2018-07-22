#include "BloomFilter.h"
#include<stdio.h>
#include<stdlib.h>
void TestBloomFilter(){
	BloomFilter bf;
	pStrToInt PSTInt[] = { StrToInt1, StrToInt2, StrToInt3, StrToInt4, StrToInt5 };
	BloomFilterInit(&bf, 100, PSTInt);
	
	BloomFilterInsert(&bf,"lalalala");
	BloomFilterInsert(&bf, "Alalalala");
    BloomFilterInsert(&bf, "Balalala");
    BloomFilterInsert(&bf, "Calalala");
	BloomFilterInsert(&bf, "Dalalala");
	if (IsIn(&bf, "Alalalala"))
		printf("在\n");
	else printf("不在\n");
	if (IsIn(&bf, "Glalalala"))
		printf("在\n");
	else printf("不在\n");
}
int main(){
	TestBloomFilter();
	system("pause");
	return 0;
}