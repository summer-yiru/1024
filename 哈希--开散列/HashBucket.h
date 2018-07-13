typedef int DataType;
typedef struct Hash_Node{
	struct Hash_Node* _pNext;
	DataType _data;
}Hash_Node,*pHash_Node;
typedef int (*pElemToInt)(DataType data);
typedef struct Hash_Bucket{
	pHash_Node* _HashTable;
	int _size;
	int _capacity;
	pElemToInt _pElemToInt;
}Hash_Bucket;
int ElemToint(int data);
int Strtoint(const char * str);
int GetNextPrimeNum(int Old_Capacity);
//初始化
void  HashBucketInit(Hash_Bucket *hb, pElemToInt ElemToInt);

//扩容
void HashBucketAddCapacity(Hash_Bucket *hb);

//插入（元素不重复）
void  HashBucketInsertUnique(Hash_Bucket*hb, DataType data);

//插入（元素可以重复）
void  HashBucketInsertEqual(Hash_Bucket*hb, DataType data);

//删除
void  HashBucketDeleteUnique(Hash_Bucket*hb, DataType data);

//删除所有指定元素
void  HashBucketDeleteEquel(Hash_Bucket*hb, DataType data);

//找到指定元素
Hash_Node*  HashBucketFind(Hash_Bucket*hb, DataType data);

//桶的大小
int  HashBucketSize(Hash_Bucket*hb);

//桶是否为空
int HashBucketEmpty(Hash_Bucket*hb);

//销毁哈希桶
void HashBucketDestory(Hash_Bucket*hb);

//打印哈希桶
void HashBucketPrint(Hash_Bucket*hb);
