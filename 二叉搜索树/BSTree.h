#pragma once
//二叉搜索树---左子树比根节点小,右子树比根节点大,中序遍历时可得到升序序列
typedef int DataType;
typedef struct BSTreeNode{
	struct BSTreeNode* _pLeft;
	struct BSTreeNode* _pRight;
	DataType _data;
}BSTreeNode;
void InitBSTree(BSTreeNode**pRoot);
void InsertBSTree(BSTreeNode**pRoot, DataType data);
int FindBSTree(BSTreeNode*pRoot, DataType data);
void DeleteBSTree(BSTreeNode**pRoot, DataType data);
void PreOrder(BSTreeNode* pRoot);
void DestroyBSTree(BSTreeNode**pRoot);
int DG_FindBSTree(BSTreeNode*pRoot, DataType data);
void DG_InsertBSTree(BSTreeNode**pRoot, DataType data);
void DG_DeleteBSTree(BSTreeNode**pRoot, DataType data);