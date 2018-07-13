#include "Hash.h"
#include<malloc.h>
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
int i = 0;
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
	for ( i = 0; i < _PrimeSize; i++)
	{
		if (_PrimeList[i]>Old_Capacity)
			return _PrimeList[i];
	}
	return -1;
}
void HashInit(pHash Ht, int capacity, explore exp){
	int i = 0;
	assert(Ht);
	Ht->_capacity = capacity;
	Ht->_table = (HashElemt*)malloc((Ht->_capacity)*sizeof(HashElemt));
	assert(Ht->_table);
	for ( i = 0; i < Ht->_capacity; i++)
	{
		(Ht->_table)[i]._state = Empty;
	}
    Ht->_size = 0;
	Ht->_exp = exp;
}
//交换两个哈希表的内容
void Swap(pHash Ht,pHash New_Hash)
{
	int temp = 0;
	HashElemt * ret = NULL;
	//交换容量
	temp = Ht->_capacity;
	Ht->_capacity = New_Hash->_capacity;
	New_Hash->_capacity = temp;
	//交换有效元素的个数
	temp = Ht->_size;
	Ht->_size = New_Hash->_size;
	New_Hash->_size = temp;
	//交换底层数组
	ret = Ht->_table;
	Ht->_table = New_Hash->_table;
	New_Hash->_table = ret;
}
//扩容
void Increase_Capacity(pHash Ht){
	Hash New_Hash;
	int i = 0;
	assert(Ht);
	int New_Capacity = GetNextPrimeNum(Ht->_capacity);
    //创建一个新的哈希表
	HashInit(&New_Hash,New_Capacity,Ht->_exp);
	for (i = 0; i < Ht->_capacity; i++)
	{
		if (Ht->_table[i]._state==Exist)
		{
			Hash_Insert(&New_Hash, Ht->_table[i]._data);
		}
	}
	Swap(Ht, &New_Hash);
	Hash_Destory(&New_Hash);
}
int HashFun(pHash Ht, DataType data){
	int ret = 0;
	ret = (int)(data%(Ht->_capacity));
	return ret;
}
int Hash_Insert(pHash Ht, DataType data){
	assert(Ht);
	if (((Ht->_size)*10/(Ht->_capacity))>=7)
	{
		Increase_Capacity(Ht);
	}
	int Hash_Addr = HashFun(Ht, data);
	while ((Ht->_table)[Hash_Addr]._state!=Empty)
	{
		if (((Ht->_table)[Hash_Addr]._state == Exist )&& ((Ht->_table)[Hash_Addr]._data == data))
			return -1;
		Ht->_exp(&Hash_Addr, Ht->_capacity);
	}
	(Ht->_table)[Hash_Addr]._data = data;
	(Ht->_table)[Hash_Addr]._state = Exist;
    Ht->_size++;
	i = 0;
	return 0;
}
void Hash_Delete(pHash Ht, DataType data){
	HashElemt* ret = NULL;
	assert(Ht);
	ret = Hash_Find(Ht, data);
	if (ret == NULL)
		return;
	ret->_state = Delete;
	Ht->_size--;
}
HashElemt* Hash_Find(pHash Ht, DataType data){
	assert(Ht);
	int Hash_Addr = HashFun(Ht, data);
	while (Ht->_table[Hash_Addr]._state!=Empty)
	{
		if (((Ht->_table)[Hash_Addr]._state == Exist)&&(Ht->_table[Hash_Addr]._data == data))
		{
			return &(Ht->_table[Hash_Addr]);
		}
		Hash_Addr++;
		if (Hash_Addr == Ht->_capacity)
			Hash_Addr = 0;
	}
	return NULL;
}
void Hash_Destory(pHash Ht){
	assert(Ht);
	free(Ht->_table);
	Ht->_size = 0;
	Ht->_capacity = 0;
}
void Hash_Print(pHash Ht){
	int i = 0;
	assert(Ht);
	for (i = 0; i < Ht->_capacity; i++)
	{
		if (Ht->_table[i]._state == Exist)
		  printf("%d=Exist%d \n",i, Ht->_table[i]._data);
		//if (Ht->_table[i]._state == Delete)
		//printf("%d=Delete \n",i);
		//if (Ht->_table[i]._state == Empty)
		//printf("%d=Empty\n ",i);
    }
	printf("%d",Ht->_capacity);
	printf("\n");
}
void Line_explore(int *addr, int capacity){
	assert(addr);
	(*addr)++;
	if ((*addr) == capacity)
		*addr == 0;
}
void second_explore(int *addr, int capacity){
	assert(addr);
	*addr = *addr+i*i+1;
	if ((*addr) == capacity)
	   *addr = *addr%capacity;
}