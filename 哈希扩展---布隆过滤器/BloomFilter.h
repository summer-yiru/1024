#include"BitMap.h"
typedef char* DataType;
typedef int(*pStrToInt)(char *str);
typedef struct BloomFilter{
	BitMap _bmp;
	int _size;
	pStrToInt _StrToInt_method[5];
}BloomFilter;

void BloomFilterInit(BloomFilter *bf, int capacity, pStrToInt *_StrToInt);
int StrToInt1(char *str);
int StrToInt2(char *str);
int StrToInt3(char *str);
int StrToInt4(char *str);
int StrToInt5(char *str);
void BloomFilterInsert(BloomFilter *bf, DataType str);
int IsIn(BloomFilter *bf, DataType str);