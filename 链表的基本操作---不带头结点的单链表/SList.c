#include "SList.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

// 链表初始化
void SListInit(PNode* pHead){
	assert(pHead);
	*pHead = NULL;
}
// 获取结点
PNode BuySListNode(DataType data){
	PNode pNewNode = (PNode)malloc(sizeof(struct Node));
	if (NULL == pNewNode)
	{
		return NULL;
	}
	pNewNode->_data = data;
	//注意使开辟的新节点的指向为空
	pNewNode->_pNext = NULL;
	return pNewNode;
}
// 头插
void SListPushFront(PNode* pHead, DataType data){
	PNode newnode = NULL;
	assert(pHead);
	if (pHead == NULL)
		return;
	newnode = BuySListNode(data);
	if (newnode == NULL)
	{
		return;
	}
	newnode->_pNext = *pHead;
	(*pHead) = newnode;
}
// 尾插
void SListPushBack(PNode* pHead, DataType data){
	PNode insertnode = NULL;
	PNode pcurnode = NULL;
	assert(pHead);
	if (NULL==pHead){
		return;
	}
	insertnode = BuySListNode(data);
	if (insertnode == NULL)
	{
		return;
	}
    pcurnode =*pHead;
	if (pcurnode==NULL){
		
		 *pHead=insertnode;
		 insertnode->_pNext = NULL;
		 return;
	}
	while (pcurnode->_pNext){
		pcurnode = pcurnode->_pNext;
	}
	pcurnode->_pNext = insertnode;
	insertnode->_pNext = NULL;
	
}
// 尾删
void SListPopBack(PNode* pHead){
	PNode pcur=NULL;
	PNode Pre = NULL;
	assert(pHead);
	pcur = *pHead;
	if (pcur == NULL)
		return;
	if (pcur->_pNext==NULL){
		*pHead=NULL;
		free(pcur);
		pcur = NULL;
		return;
	}
	while (pcur->_pNext)
	{
		Pre = pcur;
		pcur = pcur->_pNext;
    }
	Pre->_pNext = NULL;
	free(pcur);
	pcur = NULL;
}

// 头删
void SListPopFront(PNode* pHead){
	PNode pcur=NULL;
	assert(pHead);
	if (*pHead == NULL)
		return;
	pcur = *pHead;
	if (pcur->_pNext==NULL){
		*pHead = NULL;
		free(pcur);
		pcur = NULL;
		return;
	}
	else
	{
		*pHead = pcur->_pNext;
		free(pcur);
		pcur = NULL;
		
	}
	
	
}
// 查找值为data的结点，返回该结点在链表中的位置
PNode SListFind(PNode pHead, DataType data){
	PNode pcur=NULL;
	assert(pHead);
	if (pHead == NULL)
		return NULL;
	pcur = pHead;
	while (pcur)
	{
		if (pcur->_data == data){
			return pcur;
		}
		pcur = pcur->_pNext;
		
		
	}
	return NULL;
}

// 在链表pos位置后插入结点data
void SListInsert(PNode* pHead, PNode pos, DataType data){
	PNode p_cur=NULL;
	PNode insertnode = NULL;
	assert(pHead);
	if (*pHead == NULL)
		return;
	if (pos==NULL){
		return;
	}
	p_cur = *pHead;
	while ((p_cur!=pos)&&(p_cur!=NULL))
	{
	    p_cur = p_cur->_pNext;
	}
	if (p_cur == NULL){
		return;
	}
	else
	{
		insertnode = BuySListNode(data);
		if (insertnode == NULL)
		{
			return;
		}
		insertnode->_pNext=p_cur->_pNext;
		p_cur->_pNext = insertnode;

	}
}
// 删除链表pos位置上的结点
void SListErase(PNode* pHead, PNode pos)
{
	PNode p_pre=NULL;
	PNode p_cur=NULL;
	assert(pHead);
	if (*pHead == NULL)
		return;
	if (pos == NULL){
		return;
	}
	p_pre=*pHead;
	p_cur = *pHead;
	while ((p_cur != pos) && (p_cur != NULL))
	{
		p_pre = p_cur;
		p_cur = p_cur->_pNext;
	}
	if (p_cur == NULL){
		return;
	}
	else
	{
		if (pos==(*pHead))
		{
			*pHead = p_cur->_pNext;
			free(p_cur);
			p_cur = NULL;
			return;
        }
		p_pre->_pNext = p_cur->_pNext;
		free(p_cur);
		p_cur = NULL;
	}


}

// 销毁单链表
void SListDestroy(PNode* pHead){
	assert(pHead);
	if (*pHead == NULL)
		return;
	SListClear(pHead);
	free(*pHead);
	
}

// 求链表中结点的个数
int SListSize(PNode pHead){
	int count=0;
	PNode p_cur=NULL;
	if (pHead == NULL)
		return 0;
	p_cur = pHead;
	while (p_cur)
	{
		count++;
		p_cur = p_cur->_pNext;
	}
	return count;

}

// 将链表中的结点清空
void SListClear(PNode* pHead){
	PNode p_pre = NULL;
	PNode p_cur = NULL;
	assert(pHead);
	if (*pHead == NULL)
		return;
	p_pre = *pHead;
	p_cur = *pHead;
	while (p_cur)
	{
		p_pre = p_cur->_pNext;
		free(p_cur);
		p_cur = p_pre;
	}
	*pHead = p_cur;
}
// 获取链表中的最后一个结点，返回该结点的地址
PNode SListBack(PNode pHead){
	PNode p_pre=NULL;
	PNode p_cur=NULL;
    if (pHead == NULL)
		return NULL;
	p_pre = pHead;
	p_cur = pHead;
	while (p_cur)
	{
		p_pre = p_cur;
		p_cur = p_cur->_pNext;
	}
	return p_pre;
}


//打印单链表
void PrintList(PNode pHead){
	PNode p_cur=NULL;
	if (pHead == NULL)
	{
		printf("链表为空\n");
		return;
	}
	p_cur = pHead;
	while (p_cur)
	{
		
		printf("%d ", p_cur->_data);
		p_cur = p_cur->_pNext;
		
	}
	printf("\n");
}
//-------------------------------------------------//
//-------------------------------------------------//
//------------------链表面试题---------------------//
//-------------------------------------------------//
// 删除链表的非尾结点，要求不能遍历链表
//思想首先，我们先建立一个节点pCur，令节点pCur指向要删除的节点pos的下一个节点，
//然后，我们先把pCur的值赋给pos,然后再删除掉pCur这个节点
void DeleteNotTailNode(PNode pos){
	if (pos==NULL)
	{
		return;
	}
	PNode pcur = pos->_pNext;
	pos->_data = pcur->_data;
	pos->_pNext = pcur->_pNext;
	free(pcur);
	pcur = NULL;
}
// 在链表pos位置前插入值为data的结点
void InsertPosFront(PNode pos, DataType data){
	if (pos==NULL){
		return;
	}
	PNode insertnode = NULL;
	insertnode = BuySListNode(data);
	if (insertnode==NULL){
		return;
	}
	DataType ret = 0;
	insertnode->_pNext = pos->_pNext;
	pos->_pNext = insertnode;
	ret = pos->_data;
	pos->_data = insertnode->_data;
	insertnode->_data = ret;
}
// 约瑟夫环
//约瑟夫环（约瑟夫问题）是一个数学的应用问题：已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。
//从编号为k的人开始报数，数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；
//依此规律重复下去，直到圆桌周围的人全部出列
void JosephCircle(PNode* pHead, const int M){
	PNode pcur = *pHead;
	PNode pDel = NULL;
	int count = 0;
	assert(pHead);
	if (*pHead==NULL)
	{
		return;
	}
	while (pcur!=pcur->_pNext)
	{
		count = M;
		while (--count)
		{
			pcur = pcur->_pNext;
			pDel = pcur->_pNext;
		}
		pDel->_data = pcur->_data;
		pcur->_pNext = pDel->_pNext;
		free(pDel);
		pDel = NULL;
		
   }

}

// 使用冒泡方式对单链表进行排序
void BubbleSort(PNode pHead){
	PNode pcur = NULL;
	PNode pre = NULL;
	PNode flag = NULL;
	DataType ret = 0;
	if (pHead==NULL)
	{
		return;
	}
	while (flag!=pHead->_pNext)
	{
		pre = pHead;
		pcur = pHead->_pNext;
		while( pcur!=flag)
		{
			    if (pre->_data>pcur->_data){
				ret = pre->_data;
				pre->_data = pcur->_data;
				pcur->_data = ret;
			}
			pre = pcur;
			pcur = pre->_pNext;
		}
		flag = pre;
	}
	
}
// 单链表的逆序---三个指针
//先将当前的头节点从链表中拆出来，
//然后对剩余的节点进行逆序，最后将当前的表头节点连接到新链表的尾部。
void ReverseSList(PNode* pHead){
	PNode pcur = NULL;
	PNode new = NULL;
    assert(pHead);
	if (*pHead==NULL||(*pHead)->_pNext==NULL)
	{
		return;
	}
	while (*pHead)
	{
		pcur = (*pHead)->_pNext;
		(*pHead)->_pNext = new;
		new = *pHead;
		*pHead = pcur;

	}
	*pHead = new;
}
// 单链表的逆序---使用头插法
/*head->a1->a2->a3->a4；
1： 将a2插在a1前面，该链表变为：
head->a2->a1->a3->a4；
2： 将a3插在a2前面，该链表变为：
head->a3->a2->a1->a4；
2： 将a4插在a3前面，该链表变为：
head->a4->a3->a2->a1；*/
PNode ReverseSListOP(PNode* pHead){
	if (*pHead == NULL || (*pHead)->_pNext == NULL)
	{
		return NULL;
	}
	PNode pcur =(*pHead)->_pNext;
	PNode pre = *pHead;
	while (pcur)
	{
		pre->_pNext= pcur->_pNext;
		pcur->_pNext = *pHead;
		*pHead = pcur;
		pcur = pre->_pNext;
	   
	}
	return *pHead;


}
// 合并两个有序链表，合并起来依然要有序
//主要思想是把第二个链表里的元素插到第一个链表里去，
//首先为第二个链表里的元素找到对应到第一个链表里的位置然后把第二个元素插进去，
//如果第一个链表已经到末尾而第二个链表还有元素，则直接把第二个链表剩下的所有元素全部插到第一个链表后面
PNode MergeSList(PNode *pHead1, PNode* pHead2){
	assert(pHead1);
	assert(pHead2);
    if (*pHead1== NULL)
	{
		return *pHead2;
	}
	if (*pHead2 == NULL)
	{
		return *pHead1;
	}
	PNode pTail = NULL;//指向新链表的最后一个结点
	PNode newHead = NULL;//指向合并后链表第一个结点  
	if ((*pHead1)->_data < (*pHead2)->_data)
	{
		newHead = *pHead1;
		*pHead1 = (*pHead1)->_pNext;  //指向链表的第二个结点  
	}
	else
	{
		newHead = *pHead2;
		*pHead2 = (*pHead2)->_pNext;
	}
	pTail = newHead;    //指向第一个结点  
	while ((*pHead1)&&(*pHead2))
	{
		if ((*pHead1)->_data>(*pHead2)->_data)
		{
			pTail->_pNext = *pHead2;
			*pHead2 = (*pHead2)->_pNext;
		}
		else
		{
			pTail->_pNext = *pHead1;
			*pHead1 =( *pHead1)->_pNext;
		}
		pTail = pTail->_pNext;
	}
	if (NULL == *pHead1)
	{
		pTail->_pNext = *pHead2;
	}
	else if (NULL == *pHead2)
	{
		pTail->_pNext = *pHead1;
	}
	return newHead;
}

// 查找链表的中间结点，要求只能遍历一次链表
PNode FindMiddleNode(PNode pHead){
	if (pHead==NULL)
	{
		return NULL;
	}
	PNode pcur = pHead;
	PNode pre =pHead;
	while (pcur!=NULL&&pcur->_pNext!=NULL)
	{
		pre = pre->_pNext;
		pcur = pcur->_pNext->_pNext;
	}
	return pre;
}
// 查找链表的倒数第K个结点
PNode FindLastKNode(PNode pHead, int K){
	if (pHead == NULL)
	{
		return NULL;
	}
	PNode pcur = pHead;
	PNode pre = pHead;
	int count = 0;
	count=SListSize(pHead);
	if (K>count)
	{
		return NULL;
	}
	if (K==count)
	{
		return pHead;
	}
	while (K--)
	{
		pcur = pcur->_pNext;
	}
	while (pcur)
	{
		pcur = pcur->_pNext;
		pre = pre->_pNext;
	}
	return pre;
}
// 删除链表的倒数第K个结点，要求只能遍历链表一次
void DeleteLastKNode(PNode* pHead, int K){
	assert(pHead);
	if (*pHead==NULL)
	{
		return;
	}
	PNode pcur = *pHead;
	PNode Delnode = NULL;
	Delnode = FindLastKNode(*pHead, K);
	if (Delnode==NULL)
	{
		return;
	}
	if (Delnode==pcur)
	{
		*pHead = pcur->_pNext;
		free(Delnode);
		Delnode = NULL;
		return;
	}
	while (pcur!=NULL&&pcur->_pNext!=Delnode)
	{
		pcur = pcur->_pNext;
	}
	if (pcur!=NULL)
	{
		pcur->_pNext = Delnode->_pNext;
		free(Delnode);
		Delnode = NULL;
	}

}
// 判断两个单链表是否相交---链表不带环
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2){
	if (NULL==pHead1 || NULL == pHead2)
	{
		return 0;
	}
	PNode pcur1 = pHead1;
	PNode pcur2 = pHead2;
	while (pcur1->_pNext)
	{
		pcur1 = pcur1->_pNext;
	}
	while (pcur2->_pNext)
	{
		pcur2 = pcur2->_pNext;
	}
	if (pcur1==pcur2)
	{
		return 1;
	}
	return 0;
}

// 如果相交 获取交点
PNode GetCrossNode(PNode pHead1, PNode pHead2){
	int size1 = 0;
	int size2 = 0;
	PNode pcur1 = pHead1;
	PNode pcur2 = pHead2;
	int gap = size1 - size2;
	size1=SListSize(pHead1);
	size2 = SListSize(pHead2);
	if (gap>0)
	{
		while (gap--)
		{
			pcur1 = pcur1->_pNext;
		}
	}
	else if (gap<0)
	{
		while (gap++)
		{
			pcur2 = pcur2->_pNext;
		}
	}
	while (pcur1!=pcur2&&pcur1&&pcur2)
	{
		pcur1 = pcur1->_pNext;
		pcur2 = pcur2->_pNext;
	}
	return pcur1;

}
// 判断单链表是否带环
PNode IsCircle(PNode pHead){
	PNode pFast = NULL;
	PNode pSlow = NULL;
	PNode meetnode = NULL;
	if (pHead==NULL)
	{
		return NULL;
	}
	pFast = pHead;
	pSlow = pHead;
	while (pFast!=NULL&&pFast->_pNext)
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
		if (pFast==pSlow)
		{
			meetnode = pFast;
			return meetnode;
		}
	}
	return NULL;

}
// 求环的长度
int GetCircleLen(PNode pHead){
	PNode meetnode = NULL;
	PNode pcur = NULL;
	int count = 1;
	if (pHead==NULL)
	{
		return 0;
	}
	meetnode = IsCircle(pHead);
	if (meetnode==NULL)
	{
		return 0;
	}
	pcur = meetnode;
	while (meetnode!=pcur->_pNext)
	{
		count++;
		pcur = pcur->_pNext;
	}
	return count;
}
// 求环的入口点--注意推断过程
//两个指针,一个是头指针,一个指向相遇点,两个指针同时走,一定会在入口点相遇
PNode GetEnterNode(PNode pHead, PNode pMeetNode){
	PNode pcur = NULL;
	if (pHead==NULL||pMeetNode==NULL)
	{
		return NULL;
	}
	pcur = pHead;
	while (pcur!=pMeetNode)
	{
		pcur = pcur->_pNext;
		pMeetNode = pMeetNode->_pNext;
	}
	return pcur;
}
// 判断两个链表是否相交，链表可能带环
//1,先判断两个链表是否带环
//2,若用1来代表带环,0来代表不带环,则有四种情况(1,1)(1,0)(0,1)(0,0)
//通过分析可得,只有(1,1)(0,0)才可能相交
//若(1,1)即两个带环链表相交,则两个相遇点在同一个环内,分为环外相交和环内相交,(0,0)即两个不带环链表相交,则尾结点相同
int IsListCrossWithCircle(PNode pHead1, PNode pHead2){
	PNode meetnode1 = NULL;
	PNode meetnode2 = NULL;
	PNode pcur1 = NULL;
	PNode pcur2 = NULL;
	if (pHead1==NULL||pHead2==NULL)
	{
		return 0;
	}
	meetnode1 =IsCircle(pHead1);
	meetnode2 = IsCircle(pHead2);
	if (meetnode1==NULL&&meetnode2==NULL)
	{
		pcur1 = pHead1;
		pcur2 = pHead2;
		while (pcur1->_pNext)
		{
			pcur1 = pcur1->_pNext;
		}
		while (pcur2->_pNext)
		{
			pcur2 = pcur2->_pNext;
		}
		if (pcur1==pcur2)
		{
			return 1;
		}
		return 0;
		
	}
	if (meetnode1&&meetnode2)
	{
		pcur1 = meetnode1;
		pcur2 = meetnode2;
		while (meetnode1!=pcur1->_pNext)
		{
			pcur1 = pcur1->_pNext;
			if (pcur1==meetnode2)
			{
				return 2;
			}
		}
		if (pcur1==meetnode2)
		{
			return 2;
		}
		return 0;
	}
	return 0;

}
