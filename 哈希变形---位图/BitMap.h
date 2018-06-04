typedef struct BitMap
{
	int * Bit_bset;//位的集合
	int _capacity;
	int _size;//有效bit位的个数
}BitMap;
void BitMapInit(BitMap * bmp,int capacity);
void BitMapSet_zero(BitMap * bmp,int pos);
void BitMapSet_one(BitMap *bmp,int pos);
int  BitMapTest(BitMap *bmp, int pos);//测试bit位为1还是为0;
int BitMapSize(BitMap *bmp);
int BitMapCount(BitMap *bmp);
void BitMapDestroy(BitMap *bmp);