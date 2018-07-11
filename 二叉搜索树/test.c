#include "BSTree.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
	BSTreeNode* tree;
	InitBSTree(&tree);
	DG_InsertBSTree(&tree,4);
	DG_InsertBSTree(&tree, 9);
	DG_InsertBSTree(&tree, 7);
	DG_InsertBSTree(&tree, 5);
	DG_InsertBSTree(&tree, 0);
	DG_InsertBSTree(&tree, 2);
	DG_InsertBSTree(&tree, 3);
	PreOrder(tree);
	printf("\n");
	printf("%d ",FindBSTree(tree, 5));
	DG_DeleteBSTree(&tree, 5);
	printf("\n");
	PreOrder(tree);
	system("pause");
	return 0;
}