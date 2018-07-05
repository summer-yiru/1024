#include "BinTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	//二叉树的根节点
	pNode pRoot;
	pNode ret;
	int index = 0;
	int size = 0;
	char array[] = "ABD###CE##F";
	size = strlen(array);
	CreateBinTree(&pRoot,array,size,&index,'#');
	//Print_PreBinTree(pRoot);
	//Print_PreBinTreeNor(pRoot);
	//Print_MidBinTree(pRoot);
	//Print_MidBinTreeNor(pRoot);
	//Print_FinBinTree(pRoot);
	//Print_FinBinTreeNor(pRoot);
	//Print_LevelBinTree(pRoot);
	//printf("\n");
	//MirrorBinTreeNor(pRoot);
	//Print_LevelBinTree(pRoot);
	//printf("\n");
	//MirrorBinTree(pRoot);
	//Print_LevelBinTree(pRoot);
	//size = BinTreeSize(pRoot);
    //size = BinTreeLeaf(pRoot);
	//size = BinTreeKLevelNode(pRoot, 3);
	//size = BinTreeHeight(pRoot);
	//printf("%d ", size);
	//ret=Find(pRoot, 'E');
	//size = IsNodeInBinTree(pRoot, ret);
	//printf("%d ", size);
	//printf("\n");
	//if (ret)
	//printf("%c ", ret->_data);
	//size = IsCompleteBinTree(pRoot);
	//printf("%d ", size);
	ret = CopyBinTree(pRoot);
	Print_LevelBinTree(ret);
    system("pause");
	return 0;
}