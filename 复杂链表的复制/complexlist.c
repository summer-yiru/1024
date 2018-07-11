#include "complexlist.h"
#include<stdlib.h>
//创建节点
PCListNode BuyNewNode(int data){
	PCListNode NewNode = (PCListNode)malloc(sizeof(CListNode));
	if (NewNode == NULL)
	{
		return NULL;
	}
	NewNode->_data = data;
	NewNode->_pNext= NULL;
	NewNode->_random = NULL;
	return NewNode;
}
//构造复杂链表 
PCListNode MakeComplexList(){
	PCListNode pHead = NULL;
	PCListNode pcur= NULL;
	PCListNode newnode = BuyNewNode(1);
	PCListNode Node1, Node2, Node3, Node4 = NULL;
	pHead = newnode;
	pcur = pHead;
	Node1 = pcur;

    newnode = BuyNewNode(2);
	pcur->_pNext = newnode;
	pcur = pcur->_pNext;
	Node2 = pcur;

	newnode = BuyNewNode(3);
	pcur->_pNext = newnode;
	pcur = pcur->_pNext;
	Node3 = pcur;

	newnode = BuyNewNode(4);
	pcur->_pNext = newnode;
	pcur = pcur->_pNext;
	Node4 = pcur;
    Node4->_pNext = NULL;

	Node1->_random = Node3;
	Node2->_random = Node1;
	Node3->_random = Node3;
	Node4->_random = NULL;

	return pHead;

}
// 复杂链表的复制
PCListNode CopyComplexList(PCListNode pHead){
	if (pHead == NULL)
	{
		return NULL;
	}
	PCListNode pcur = pHead;
	PCListNode pre = pHead;
	PCListNode ret = NULL;
	PCListNode newnode = NULL;
	//1.在原链表每个结点后插入值相同的结点
	while (pre)
	{
		pcur = pre->_pNext;
		newnode =BuyNewNode(pre->_data);
		if (newnode == NULL)
		{
			return NULL;
		}
		newnode->_pNext = pcur;
		pre->_pNext = newnode;
		pre = pcur;
	
		
	}
	//2,给新插入的结点的随机指针域赋值
	pre = pHead;
	pcur = pHead->_pNext;
	while (pcur)
    {
		pcur = pre->_pNext;
		if (pre->_random == NULL)
		{
			pcur->_random = NULL;
		}
		else
		{
			pcur->_random = pre->_random->_pNext;
		}
		pre = pcur->_pNext;
		

}

	//3,将插入的新结点从链表中拆下来
	pre = pHead;
	pcur = pHead->_pNext;
	ret = pcur;
	while (pcur)
	{
		pre->_pNext = pcur->_pNext;
		pre = pcur;
		pcur = pre->_pNext;
	}
	return ret;

}
