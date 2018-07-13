#pragma once
typedef void(*explore)(int*, int);
typedef int DataType;
typedef enum state
{
	Empty,
	Exist,
	Delete,
}state;
typedef struct HashElemt
{
	DataType _data;
	state _state;
}HashElemt;
typedef struct Hash
{
	HashElemt * _table;
	int _size;//有效元素的个数
	int _capacity;//数组的容量;
	explore _exp;//线性探测还是二次探测
}Hash,*pHash;
void HashInit(pHash Ht,int _capacity,explore exp);
int Hash_Insert(pHash Ht,DataType data);
void Hash_Delete(pHash Ht,DataType data);
HashElemt* Hash_Find(pHash Ht,DataType data);
void Hash_Destory(pHash Ht);
void Hash_Print(pHash Ht);
void Line_explore(int *addr,int capacity);
void second_explore(int *addr, int capacity);
