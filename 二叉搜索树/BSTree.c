#include "BSTree.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
void InitBSTree(BSTreeNode**pRoot){
	assert(pRoot);
	*pRoot = NULL;
}
BSTreeNode*  BuyBSTreeNode(DataType data){
	BSTreeNode * NewNode = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	if (NewNode == NULL)
		return NULL;
	NewNode->_data = data;
	NewNode->_pLeft = NULL;
	NewNode->_pRight = NULL;
	return NewNode;
}
void InsertBSTree(BSTreeNode**pRoot, DataType data){
	BSTreeNode *pcur=NULL;
	BSTreeNode *parent=NULL;
	assert(pRoot);
	if (*pRoot == NULL)
	{
		*pRoot = BuyBSTreeNode(data);
		return;
	}
	//查找待插节点的位置
	pcur = *pRoot;
	while (pcur)
	{
		if (data>pcur->_data)
		{
			parent = pcur;
			pcur = pcur->_pRight;
		}
		else if (data < pcur->_data){
			parent = pcur;
			pcur = pcur->_pLeft;
		}
		else
			return;
	}
	//插入新节点
	pcur = BuyBSTreeNode(data);
	if (data<(parent->_data))
	   parent->_pLeft=pcur;
	else 
	   parent->_pRight = pcur;
}
int FindBSTree(BSTreeNode*pRoot, DataType data){
	BSTreeNode *pcur = pRoot;
	while (pcur)
	{
		if (data == pcur->_data)
			return 1;
		else if (data<pcur->_data)
			pcur = pcur->_pLeft;
		else pcur = pcur->_pRight;
	}
	return 0;
}
void DeleteBSTree(BSTreeNode**pRoot, DataType data){
	BSTreeNode *pcur = NULL;
	BSTreeNode *parent = NULL;
	assert(pRoot);
	if (0 == FindBSTree(*pRoot,data))
		return;
	pcur = (*pRoot);
	while (pcur)
		{
			if (data>pcur->_data)
			{
				parent = pcur;
				pcur = pcur->_pRight;
			}
			else if (data < pcur->_data)
			{
				parent = pcur;
				pcur = pcur->_pLeft;
			}
			else break;
	   }
	//待删元素不在树中
	if (pcur == NULL)
		return;
	//找到该节点
	if (pcur->_pLeft==NULL)//该节点是叶子节点或者是只有右子树
	{
		if (pcur == (*pRoot))
			*pRoot = pcur->_pRight;
		else
		{
			if (pcur == parent->_pLeft)
				parent->_pLeft = pcur->_pRight;
			else parent->_pRight = pcur->_pRight;
		}
	
	}
	else if (pcur->_pRight==NULL)//该节点是叶子节点或者是只有左子树
	{
		if (pcur == (*pRoot))
			*pRoot = pcur->_pLeft;
		else
		{
			if (pcur == parent->_pLeft)
				parent->_pLeft = pcur->_pLeft;
			else parent->_pRight = pcur->_pLeft;
		}
		free(pcur);
	}
	else//	左右孩子都有,在左子树中寻找最大节点或者在右子树中寻找最小的节点,替换待删节点,然后删除
	{
		BSTreeNode *pDel = pcur->_pRight;
		parent = pDel;
		while (pDel->_pLeft)
		{
			parent = pDel;
			pDel = pDel->_pLeft;
		}
		pcur->_data = pDel->_data;
		if (pDel = parent->_pLeft)
			parent->_pLeft = pDel->_pRight;
		if (pDel = parent->_pRight)
			parent->_pRight = pDel->_pRight;
	}  

	free(pcur);
}
void PreOrder(BSTreeNode* pRoot){
	if (pRoot)
	{
		PreOrder(pRoot->_pLeft);
		printf("%d ", pRoot->_data);
		PreOrder(pRoot->_pRight);
	}
}
void DestroyBSTree(BSTreeNode**pRoot){
	assert(pRoot);
	if (*pRoot)
	{
		DestroyBSTree(&(*pRoot)->_pLeft);
		DestroyBSTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
    }
}
//递归
int DG_FindBSTree(BSTreeNode*pRoot, DataType data){
	if (NULL == pRoot)
		return 0;
	if (data == pRoot->_data)
		return 1;
	else if(data < pRoot->_data)
		return DG_FindBSTree(pRoot->_pLeft,data);
	else 
		return DG_FindBSTree(pRoot->_pRight,data);
}
void DG_InsertBSTree(BSTreeNode**pRoot, DataType data){
	assert(pRoot);
	if (*pRoot == NULL)
	{
		*pRoot = BuyBSTreeNode(data);
		return;
	}
	else
	{
		if (data < (*pRoot)->_data)
			return DG_InsertBSTree(&(*pRoot)->_pLeft, data);
		else if (data > (*pRoot)->_data)
			return DG_InsertBSTree(&(*pRoot)->_pRight, data);
		else
			return;
		
	}
}
void DG_DeleteBSTree(BSTreeNode**pRoot, DataType data){
	assert(pRoot);
	if (*pRoot == NULL)
	{
		return;
	}
	if (data < (*pRoot)->_data)
		return DG_DeleteBSTree(&(*pRoot)->_pLeft, data);
	else if (data >(*pRoot)->_data)
		return DG_DeleteBSTree(&(*pRoot)->_pRight, data);
	else {
		BSTreeNode *pDel = *pRoot;
		if (pDel->_pLeft == NULL){
			*pRoot = pDel->_pRight;
			free(pDel);
		}
		else if (pDel->_pRight == NULL){
			*pRoot = pDel->_pLeft;
			free(pDel);
		}
		else{
			BSTreeNode *pDel = (*pRoot)->_pRight;
			while (pDel->_pLeft)
				pDel = pDel->_pLeft;
			(*pRoot)->_data = pDel->_data;
			return DG_DeleteBSTree(&(*pRoot)->_pRight, data);
		}
	}
}