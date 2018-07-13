#include "HashBucket.h"
#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
int HashFun(Hash_Bucket *hb,DataType data){
	assert(hb);
	return  (hb->_pElemToInt)(data) % (hb->_capacity);
}
//哈希字符串转换函数
int Strtoint(const char * str)
{
	unsigned int seed = 131; // 31 131 1313 13131 131313
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash * seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}
//默认处理方式
int ElemToint(int data){
	return data;
}
//素数表
int GetNextPrimeNum(int Old_Capacity){
	int i = 0;
	const int _PrimeSize = 28;
	static const unsigned long _PrimeList[28] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};
	for (i = 0; i < _PrimeSize; i++)
	{
		if (_PrimeList[i]>Old_Capacity)
			return _PrimeList[i];
	}
	return -1;
}
//扩容
void HashBucketAddCapacity(Hash_Bucket *hb){
	pHash_Node pcur = NULL;
	int i = 0;
	assert(hb);
	int new_capacity = GetNextPrimeNum(hb->_capacity);
	pHash_Node * _newTable = (pHash_Node *)malloc(sizeof(pHash_Node)*new_capacity);
	if (_newTable==NULL)
	{
		assert(0);
		return;
	}
	for ( i = 0; i < new_capacity; i++)
	{
		_newTable[i]->_pNext = NULL;
	}
	for (i=0; i < hb->_capacity;i++){
		pcur = hb->_HashTable[i];
		int  new_bucketNober = -1;
		while (pcur)
		{
			hb->_HashTable[i] = pcur->_pNext;
			//插入pcur节点到_newTable中
			new_bucketNober = hb->_pElemToInt(pcur->_data) % new_capacity;
			pcur->_pNext = _newTable[new_bucketNober];
			_newTable[new_bucketNober] = pcur;
			pcur = hb->_HashTable[i];
		}
	}
	free(hb->_HashTable);
	hb->_HashTable = _newTable;
	hb->_capacity = new_capacity;
}

//初始化
void  HashBucketInit(Hash_Bucket *hb, pElemToInt  ElemToInt){
	int i = 0;
	assert(hb);
	hb->_capacity = 3;
	hb->_HashTable = (pHash_Node *)malloc(sizeof(pHash_Node)*(hb->_capacity));
	if (hb->_HashTable==NULL)
	{
		assert(0);
		return;
	}
	for ( i = 0; i < hb->_capacity; i++)
	{
		hb->_HashTable[i] = NULL;
	}
	hb->_size = 0;
	hb->_pElemToInt = ElemToInt;
}
Hash_Node* Buy_Hash_Node(DataType data){
	Hash_Node *ret = (Hash_Node *)malloc(sizeof(Hash_Node));
	if (ret==NULL)
	{
		assert(0);
		return;
	}
	ret->_data = data;
	ret->_pNext = NULL;
	return ret;
}
//插入（元素不重复）
void  HashBucketInsertUnique(Hash_Bucket*hb, DataType data){
	Hash_Node*pcur = NULL;
	Hash_Node*NewNode = NULL;
	assert(hb);
	if (hb->_capacity==hb->_size)
	{
		HashBucketAddCapacity(hb);
	}
	int Hash_Addr = HashFun(hb, data);
	pcur = hb->_HashTable[Hash_Addr];
	while (pcur)
	{
		if (pcur->_data==data)
		  return;
		else
	     pcur = pcur->_pNext;
	}
    NewNode = Buy_Hash_Node(data);
	NewNode->_pNext = hb->_HashTable[Hash_Addr];
	hb->_HashTable[Hash_Addr] = NewNode;
}
//插入（元素可以重复）
void  HashBucketInsertEqual(Hash_Bucket*hb, DataType data){
	Hash_Node*NewNode = NULL;
	assert(hb);
	int Hash_Addr = HashFun(hb, data);
	NewNode = Buy_Hash_Node(data);
	NewNode->_pNext = hb->_HashTable[Hash_Addr];
	hb->_HashTable[Hash_Addr] = NewNode;
}

//删除（元素不重复）
void  HashBucketDeleteUnique(Hash_Bucket*hb, DataType data){
	Hash_Node*pcur = NULL;
	Hash_Node*pre = NULL;
	assert(hb);
	int Hash_Addr = HashFun(hb, data);
	pcur = hb->_HashTable[Hash_Addr];
	while (pcur)
	{
		if (pcur->_data == data)
		{
			if (pcur == hb->_HashTable[Hash_Addr])
			   hb->_HashTable[Hash_Addr] = pcur->_pNext;
			else
			   pre->_pNext = pcur->_pNext;
			free(pcur);
			hb->_size--;
			return;
		}
		else
		{
			pre = pcur;
			pcur = pcur->_pNext;
		}
	}

}

//删除（元素有可能重复）
void  HashBucketDeleteEquel(Hash_Bucket*hb, DataType data){

	Hash_Node*pcur = NULL;
	Hash_Node*pre = NULL;
	assert(hb);
	int Hash_Addr = HashFun(hb, data);
	pcur = hb->_HashTable[Hash_Addr];
	while (pcur)
	{
		if (pcur->_data == data)
		{
			if (pcur == hb->_HashTable[Hash_Addr])
			{
				hb->_HashTable[Hash_Addr] = pcur->_pNext;
				free(pcur);
				pcur = hb->_HashTable[Hash_Addr];
			}
			else
			{
				pre->_pNext = pcur->_pNext;
				free(pcur);
				pcur = pre->_pNext;
			}
			
			hb->_size--;

		}
		else
		{
			pre = pcur;
			pcur = pcur->_pNext;
		}
		
		
	}
}

//找到指定元素
Hash_Node*  HashBucketFind(Hash_Bucket*hb, DataType data){
	Hash_Node*pcur = NULL;
    assert(hb);
	int Hash_Addr = HashFun(hb, data);
	pcur = hb->_HashTable[Hash_Addr];
	while (pcur)
	{
		if (pcur->_data == data)
			return pcur;
		else
			pcur = pcur->_pNext;
	}
	return NULL;
}

//桶的大小
int  HashBucketSize(Hash_Bucket*hb){
	return hb->_size;
}

//桶是否为空
int HashBucketEmpty(Hash_Bucket*hb){
	return 0 == hb->_size;
}

//销毁哈希桶
void HashBucketDestory(Hash_Bucket*hb){
	int i = 0;
	assert(hb);
	for ( i = 0; i < hb->_capacity; i++)
	{
		free(hb->_HashTable[i]);
	}
	free(hb->_HashTable);
	hb->_capacity = 0;
	hb->_size = 0;
}
//打印哈希桶
void HashBucketPrint(Hash_Bucket*hb){
	Hash_Node *pcur = NULL;
	int i = 0;
	assert(hb);
	for (i = 0; i < hb->_capacity; i++)
	{
		pcur = hb->_HashTable[i];
		while (pcur)
		{
			printf("%d---", pcur->_data);
			pcur = pcur->_pNext;
		}
		printf("\n");
   }
}

