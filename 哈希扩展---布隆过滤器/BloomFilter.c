#include "BloomFilter.h"
#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
void BloomFilterInit(BloomFilter *bf, int size, pStrToInt _StrtoInt[5]){
	int i = 0;
	assert(bf);
	BitMapInit(&bf->_bmp,size*5);//一个元素对应5个bit位
	bf->_size = 0;
	for ( i = 0; i < 5; i++)
	{
		bf->_StrToInt_method[i] = _StrtoInt[i];
	}
}
int StrToInt1(char *str){
	unsigned int seed = 131; // 31 131 1313 13131 131313
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash * seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}
int StrToInt2(char *str){
	unsigned int hash = 0;
	int i;

	for (i = 0; *str; i++)
	{
		if ((i & 1) == 0)
		{
			hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
		}
		else
		{
			hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
		}
	}

	return (hash & 0x7FFFFFFF);
}
int StrToInt3(char *str){
	unsigned int hash = 5381;

	while (*str)
	{
		hash += (hash << 5) + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}
int StrToInt4(char *str){
	unsigned int hash = 1315423911;

	while (*str)
	{
		hash ^= ((hash << 5) + (*str++) + (hash >> 2));
	}

	return (hash & 0x7FFFFFFF);
}
int StrToInt5(char *str){
	unsigned int hash = 0;
	unsigned int x = 0;

	while (*str)
	{
		hash = (hash << 4) + (*str++);
		if ((x = hash & 0xF0000000L) != 0)
		{
			hash ^= (x >> 24);
			hash &= ~x;
		}
	}

	return (hash & 0x7FFFFFFF);
}

void BloomFilterInsert(BloomFilter *bf,DataType str){
	int addr1, addr2, addr3, addr4, addr5;
	int TotalBits = bf->_bmp._size;
	addr1 = bf->_StrToInt_method[0](str) % TotalBits;
	BitMapSet_one(&bf->_bmp, addr1);
	addr2 = bf->_StrToInt_method[1](str) % TotalBits;
	BitMapSet_one(&bf->_bmp, addr2);
	addr3 = bf->_StrToInt_method[2](str) % TotalBits;
	BitMapSet_one(&bf->_bmp, addr3);
	addr4 = bf->_StrToInt_method[3](str) % TotalBits;
	BitMapSet_one(&bf->_bmp, addr4);
	addr5 = bf->_StrToInt_method[4](str) % TotalBits;
	BitMapSet_one(&bf->_bmp, addr5);
	bf->_size++;
}
int IsIn(BloomFilter *bf, DataType str){
	int addr1, addr2, addr3, addr4, addr5;
	int TotalBits = bf->_bmp._size;
	addr1 = bf->_StrToInt_method[0](str) % TotalBits;
	if (!BitMapTest(&bf->_bmp, addr1))
		return 0;
	addr2 = bf->_StrToInt_method[1](str) % TotalBits;
	if (!BitMapTest(&bf->_bmp, addr2))
		return 0;
	addr3 = bf->_StrToInt_method[2](str) % TotalBits;
	if (!BitMapTest(&bf->_bmp, addr3))
		return 0;
	addr4 = bf->_StrToInt_method[3](str) % TotalBits;
	if (!BitMapTest(&bf->_bmp, addr4))
		return 0;
	addr5 = bf->_StrToInt_method[4](str) % TotalBits;
	if (!BitMapTest(&bf->_bmp, addr5))
		return 0;
	return 1;
}
