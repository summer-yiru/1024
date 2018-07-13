#include "Hash.h"
#include<stdio.h>
int main(){
	Hash Ht;
	HashElemt* ret = NULL;
	//HashInit(&Ht,5,Line_explore);
	HashInit(&Ht, 5, second_explore);
	Hash_Insert(&Ht, 37);
	Hash_Insert(&Ht, 25);
	Hash_Insert(&Ht, 14);
	Hash_Insert(&Ht, 36);
	Hash_Insert(&Ht, 49);
	Hash_Insert(&Ht, 68);
	Hash_Insert(&Ht, 57);
	Hash_Insert(&Ht, 11);
	Hash_Insert(&Ht, 24);
	Hash_Insert(&Ht, 89);
	Hash_Print(&Ht);
	printf("%d\n", Ht._size);
	//Hash_Delete(&Ht, 25);
	//Hash_Delete(&Ht, 57);
	//Hash_Print(&Ht);
	//ret = Hash_Find(&Ht,24);
	//printf("%d\n",ret->_data);
    system("pause");
	return 0;
}