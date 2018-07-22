#include "BitMap.h"
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
void BitMapInit(BitMap * bmp, int total_Bit){
	assert(bmp); //total_Bit代表总共的bit位数
	bmp->_capacity = (total_Bit >> 5 )+ 1;//代表需要的整形空间的个数
	bmp->Bit_bset = calloc(bmp->_capacity, sizeof(int));//void *calloc(空间的个数,每个空间的字节数);
	bmp->_size = total_Bit;//有效比特位的个数
}
//将pos的位置0;
void BitMapSet_zero(BitMap * bmp, int pos){
	assert(bmp);
	int pos_Byte = pos >> 5;
	int pos_Bit = pos % 32;
	if (pos > bmp->_size)
		return;
	bmp->Bit_bset[pos_Byte] = bmp->Bit_bset[pos_Byte] &( ~(1 << pos));
	
}
//将pos的位置1;
void BitMapSet_one(BitMap *bmp, int pos){
	assert(bmp);
	int pos_Byte = pos >> 5;
	int pos_Bit = pos % 32;
	if (pos > bmp->_size)
		return;
	bmp->Bit_bset[pos_Byte] = bmp->Bit_bset[pos_Byte] |(1 << pos);
	
}
int  BitMapTest(BitMap *bmp, int pos)//测试bit位为1还是为0;
{
	assert(bmp);
	int pos_Byte = pos >> 5;
	int pos_Bit = pos % 32;
	if (pos > bmp->_size)
		return;
	return bmp->Bit_bset[pos_Byte] & (1 << pos);
}
int BitMapSize(BitMap *bmp)
{
	assert(bmp);
	return bmp->_size;
}
//统计bit位上1的个数
int BitMapCount(BitMap *bmp){
	int i = 0;
	int count = 0;
	assert(bmp);
	const char * bit1Count = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4";
	for ( i = 0; i <bmp->_capacity; i++)
	{
		int value = bmp->Bit_bset[i];
		int j = 0;
		//一个整数占4个字节,我们按一个字节为单元查看bit位上1的个数
		while (j<sizeof(bmp->Bit_bset[0])){
			char c = value;
			//统计一个字节的底4位
      		count+=bit1Count[c&0x0f];
			c >>= 4;
			//统计一个字节的高4位
			count+=bit1Count[c&0x0f];
			value >>= 8;
			j++;
		}
	}
	return count;
}
void BitMapDestroy(BitMap *bmp){
	assert(bmp);
	if (bmp->Bit_bset)
		free(bmp->Bit_bset);
	bmp->_size = 0;
	bmp->_capacity = 0;
}