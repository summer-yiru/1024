#include "HashBucket.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
	Hash_Node* ret;
	Hash_Bucket hb;
	HashBucketInit(&hb, ElemToint);
	HashBucketInsertUnique(&hb,37);
	HashBucketInsertUnique(&hb,25);
	HashBucketInsertUnique(&hb,14);
	HashBucketInsertUnique(&hb,36);
	HashBucketInsertUnique(&hb,49);
	HashBucketInsertUnique(&hb,68);
	HashBucketInsertUnique(&hb,57);
	HashBucketInsertUnique(&hb,11);
	HashBucketInsertEqual(&hb, 14);
	HashBucketInsertEqual(&hb, 68);
	//HashBucketPrint(&hb);
	//HashBucketDeleteEquel(&hb, 14);
	printf("//////////");
	HashBucketPrint(&hb);
	ret = HashBucketFind(&hb, 11);
	printf("%d\n",ret->_data);
	HashBucketDeleteUnique(&hb, 49);
	HashBucketPrint(&hb);
	system("pause");
	return 0;
}