#ifndef __TREE_H__
#define __TREE_H__


#include "LinkStack.h"
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>
typedef char Bin_DataType;
typedef struct BinTreeNode
{
	struct BinTreeNode *_pLeft;
	struct BinTreeNode *_pRight;
	Bin_DataType _data;
}Node, *pNode;
void CreateBinTree(pNode *pRoot, char array[], int size, int *index, Bin_DataType Nouse);
void Print_PreBinTree(pNode pRoot);
void Print_MidBinTree(pNode pRoot);
void Print_FinBinTree(pNode pRoot);
void Print_PreBinTreeNor(pNode pRoot);
void Print_FinBinTreeNor(pNode pRoot);
void Print_LevelBinTree(pNode pRoot);
// 二叉树的销毁
void DetroyBinTree(pNode* pRoot);
//二叉树的复制
pNode CopyBinTree(pNode pRoot);
// 二叉树的镜像---非递归
void MirrorBinTreeNor(pNode pRoot);

// 二叉树的镜像---递归
void MirrorBinTree(pNode pRoot);

// 求二叉树中结点的个数
int BinTreeSize(pNode pRoot);

// 求二叉树中叶子结点的个数
int BinTreeLeaf(pNode pRoot);

// 求二叉树中第K层结点的个数
int BinTreeKLevelNode(pNode pRoot, int K);

// 求二叉树的高度
int BinTreeHeight(pNode pRoot);

// 在二叉树中查找值为data的结点，找到返回该结点，否则返回空
pNode Find(pNode pRoot, Bin_DataType data);

// 检测一个节点是否在二叉树中
int IsNodeInBinTree(pNode pRoot, pNode ret);

// 检测一棵树是否为完全二叉树
int IsCompleteBinTree(pNode pRoot);
#endif
 