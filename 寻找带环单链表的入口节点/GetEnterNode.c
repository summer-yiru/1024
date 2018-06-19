#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
typedef int DataType;
typedef struct Node{
	struct Node*_pNext;
	DataType _data;
}Node, *PNode;
//打印单链表  
void PrintList(PNode pHead){
	PNode p_cur = NULL;
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
// 尾插  
void SListPushBack(PNode* pHead, DataType data){
	PNode insertnode = NULL;
	PNode pcurnode = NULL;
	assert(pHead);
	if (NULL == pHead){
		return;
	}
	insertnode = BuySListNode(data);
	if (insertnode == NULL)
	{
		return;
	}
	pcurnode = *pHead;
	if (pcurnode == NULL){

		*pHead = insertnode;
		insertnode->_pNext = NULL;
		return;
	}
	while (pcurnode->_pNext){
		pcurnode = pcurnode->_pNext;
	}
	pcurnode->_pNext = insertnode;
	insertnode->_pNext = NULL;

}
PNode SListFind(PNode pHead, DataType data){
	PNode pcur = NULL;
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
PNode SListBack(PNode pHead){
	PNode p_pre = NULL;
	PNode p_cur = NULL;
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
PNode GetEnterNode(PNode pHead){
	PNode pcur = NULL;
	PNode pFast = NULL;
	PNode pSlow = NULL;
	PNode pMeet = NULL;
	pFast = pHead;
	pSlow = pHead;
	pcur = pHead;
	pFast = pFast->_pNext->_pNext;
	pSlow = pSlow->_pNext;
	while (pFast != pSlow){
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
	}
	pMeet = pFast;
	while (pcur != pMeet){
		pcur = pcur->_pNext;
		pMeet = pMeet->_pNext;
	}
	return pcur;
}
int main(){
	PNode pHead;
	
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 9);

	SListBack(pHead)->_pNext = SListFind(pHead, 6);
	
	GetEnterNode(pHead);
	

	return 0;
}
