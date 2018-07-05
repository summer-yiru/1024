#include "BinTree.h"
#include "Queue.h"
pNode BuyNode(Bin_DataType data){
    pNode pNewNode;
	pNewNode = (pNode)malloc(sizeof(Node));
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	return pNewNode;
}
//创建二叉树
void CreateBinTree(pNode *pRoot, char array[], int size, int *index,Bin_DataType Nouse){
	assert(pRoot);
	if ((*index)<size&&array[*index]!=Nouse)
	{
		*pRoot = BuyNode(array[*index]);
		++(*index);
		CreateBinTree(&((*pRoot)->_pLeft), array, size, index,Nouse);
		++(*index);
		CreateBinTree(&((*pRoot)->_pRight), array, size, index,Nouse);
	}
}
// 二叉树拷贝
pNode CopyBinTree(pNode pRoot){
	pNode pNewRoot;
	if(pRoot == NULL)
		return NULL;
	pNewRoot = BuyNode(pRoot->_data);
	if (pNewRoot)
	{
		if (pRoot->_pLeft)
		pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);
		if (pRoot->_pRight)
		pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}
	return pNewRoot;
}
//打印二叉树
//---------前序遍历递归-------根节点-左子树-右子树
void Print_PreBinTree(pNode pRoot){
	if (pRoot == NULL)
		return;
	printf("%c ",pRoot->_data);
	Print_PreBinTree(pRoot->_pLeft);
	Print_PreBinTree(pRoot->_pRight);
}
//---------前序遍历非递归-------根节点-左子树-右子树(利用栈实现非递归--把递归改为循环)
void Print_PreBinTreeNor(pNode pRoot){
	LinkStack s;
	pNode pcur=NULL;
	if (pRoot == NULL)
		return;
	StackInit(&s);
	StackPush(&s,pRoot);
	while (!StackEmpty(&s))
	{
		pcur= StackTop(&s);
		printf("%c ",pcur->_data);
		StackPop(&s);
		if (pcur->_pRight)
		{
			StackPush(&s, pcur->_pRight);
		}
		if (pcur->_pLeft)
		{
			StackPush(&s, pcur->_pLeft);
		}
	}

}

//---------中序遍历-------
void Print_MidBinTree(pNode pRoot){
	if (pRoot == NULL)
		return;
	Print_MidBinTree(pRoot->_pLeft);
	printf("%c ", pRoot->_data);
	Print_MidBinTree(pRoot->_pRight);
}
// 中序遍历---非递归--左子树-根节点-右子树(利用栈实现非递归--把递归改为循环)
void Print_MidBinTreeNor(pNode pRoot){
	LinkStack s;
	pNode pcur = NULL;
	if (pRoot == NULL)
		return;
	StackInit(&s);
	pcur = pRoot;
	while (pcur||!StackEmpty(&s))
	{
		while (pcur)
		{
			StackPush(&s,pcur);
			pcur = pcur->_pLeft;
		}
		pcur = StackTop(&s);
		printf("%c ",pcur->_data );
		StackPop(&s);
		pcur = pcur->_pRight;
	}

}


//---------后序遍历-------
void Print_FinBinTree(pNode pRoot){
	if (pRoot == NULL)
		return;
	Print_FinBinTree(pRoot->_pLeft);
	Print_FinBinTree(pRoot->_pRight);
	printf("%c ", pRoot->_data);
	
}
// 后序遍历---非递归--左子树-右子树-根节点(利用栈实现非递归--把递归改为循环)
void Print_FinBinTreeNor(pNode pRoot){
	LinkStack s;
	pNode pcur = NULL;
	pNode ret = NULL;
	int flag = 1;
	if (pRoot == NULL)
		return;
	StackInit(&s);
	pcur = pRoot;
	if (pcur)
	{
		do
		{
			while (pcur)
			{
				StackPush(&s,pcur);
				pcur = pcur->_pLeft;
			}
			flag = 1;
			ret = NULL;
			while (!StackEmpty(&s)&&flag==1)
			{
				pcur = StackTop(&s);
				if (pcur->_pRight==ret)
				{
					printf("%c ", pcur->_data);
					ret = pcur;
					StackPop(&s);
				}
				else
				{
					pcur = pcur->_pRight;
					flag = 0;
				}
			}

		} while (!StackEmpty(&s));
	}
}
// 层序遍历-----使用队列---先进先出
void Print_LevelBinTree(pNode pRoot){
	Queue Que;
	pNode ret = NULL;
	if (pRoot == NULL)
		return;
	QueueInit(&Que);
	QueuePush(&Que, pRoot);
	while (!QueueEmpty(&Que))
	{
		ret = QueueFront(&Que);
		printf("%c ", ret->_data);
		QueuePop(&Que);
		if (ret->_pLeft)
		{
			QueuePush(&Que, ret->_pLeft);
		}
		if (ret->_pRight)
		{
			QueuePush(&Que,ret->_pRight);
		}
	}
}
// 二叉树的销毁
void DetroyBinTree(pNode* pRoot){
	assert(pRoot);
	if (*pRoot)
	{
		DetroyBinTree(&(*pRoot)->_pLeft);
		DetroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		(*pRoot) = NULL;
	}
}
// 二叉树的镜像---非递归---利用层序遍历
void MirrorBinTreeNor(pNode pRoot){
	Queue Que;
	pNode ret = NULL;
	pNode temp = NULL;
	if (pRoot == NULL)
		return;
	QueueInit(&Que);
	QueuePush(&Que, pRoot);
	while (!QueueEmpty(&Que))
	{
		ret = QueueFront(&Que);
		temp = ret->_pLeft;
		ret->_pLeft = ret->_pRight;
		ret->_pRight = temp;
		if (ret->_pLeft)
		{
			QueuePush(&Que, ret->_pLeft);
		}
		if (ret->_pRight)
		{
			QueuePush(&Que, ret->_pRight);
		}
		QueuePop(&Que);
	}

}

// 二叉树的镜像---递归----利用前序遍历
void MirrorBinTree(pNode pRoot){
	pNode temp = NULL;
	if (pRoot == NULL)
		return;
	temp = pRoot->_pLeft;
	pRoot->_pLeft = pRoot->_pRight;
	pRoot->_pRight = temp;
	MirrorBinTree(pRoot->_pLeft);
	MirrorBinTree(pRoot->_pRight);
}
// 求二叉树中结点的个数
int BinTreeSize(pNode pRoot){
	if (pRoot == NULL)
		return 0;
	int left = BinTreeSize(pRoot->_pLeft);
	int right = BinTreeSize(pRoot->_pRight);
	return left + right+1;
}

// 求二叉树中叶子结点的个数
int BinTreeLeaf(pNode pRoot){
	if (pRoot == NULL)
		return 0;
	if (pRoot->_pLeft == NULL&&pRoot->_pRight == NULL)
		return 1;
	int left = BinTreeLeaf(pRoot->_pLeft);
	int right = BinTreeLeaf(pRoot->_pRight);
	return left + right;
}
// 求二叉树中第K层结点的个数
int BinTreeKLevelNode(pNode pRoot, int K){
	if (pRoot == NULL || K <= 0)
		return 0;
	if (K == 1)
		return 1;
	int left = BinTreeKLevelNode(pRoot->_pLeft, K - 1);
	int right =BinTreeKLevelNode(pRoot->_pRight, K - 1);
	return left + right;
}

// 求二叉树的高度
int BinTreeHeight(pNode pRoot){
	if (pRoot == NULL)
		return 0;
	if (pRoot->_pLeft == NULL&&pRoot->_pRight == NULL)
		return 1;
	int left = BinTreeHeight(pRoot->_pLeft);
	int right = BinTreeHeight(pRoot->_pRight);
	return left >= right ? left+1 : right+1;
}
// 在二叉树中查找值为data的结点，找到返回该结点，否则返回空
pNode Find(pNode pRoot, Bin_DataType data){
	if (pRoot == NULL)
		return NULL;
	if (pRoot->_data == data)
		return pRoot;
	Find(pRoot->_pLeft, data);
	if (Find(pRoot->_pLeft, data) == NULL)
	{
		Find(pRoot->_pRight, data);
	}
}
	

// 检测一个节点是否在二叉树中
int IsNodeInBinTree(pNode pRoot, pNode ret){
	if (pRoot == NULL)
		return NULL;
	if (pRoot == ret)
		return 1;
	if (IsNodeInBinTree(pRoot->_pLeft, ret)==0)
	{
		IsNodeInBinTree(pRoot->_pRight, ret);
	}
}

// 检测一棵树是否为完全二叉树
int IsCompleteBinTree(pNode pRoot){
	Queue Que;
	int flag = 0;
	pNode ret = NULL;
	if (pRoot == NULL)
		return 0;
	QueueInit(&Que);
	QueuePush(&Que, pRoot);
	while (!QueueEmpty(&Que))
	{
		ret = QueueFront(&Que);
		QueuePop(&Que);
		if (flag)
		{
			if (ret->_pLeft || ret->_pRight )
				return 0;
		}
		else{
			if (ret->_pLeft&&ret->_pRight)
			{
				QueuePush(&Que, ret->_pLeft);
				QueuePush(&Que, ret->_pRight);
			}
			else if (ret->_pRight)
			return 0;
			else if (ret->_pLeft)
			{
				QueuePush(&Que, ret->_pLeft);
				flag = 1;
			}
			else
				flag = 1;
		  }
	}
}
