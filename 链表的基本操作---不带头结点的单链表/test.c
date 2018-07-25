#include "SList.h"
#include<stdio.h>
#include<stdlib.h>
//SListInit()//SListPushBack()//SListPushFront()//SListPopBack()////SListPopFront()
void test1(){
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushFront(&pHead, 4);
    SListPushBack(&pHead, 2);
	PrintList(pHead);
	SListPopBack(&pHead);
	SListPopBack(&pHead);
	PrintList(pHead);
	SListPopBack(&pHead);
	PrintList(pHead);
	SListPushFront(&pHead, 4);
	SListPushBack(&pHead, 2);
	PrintList(pHead);
	SListPopFront(&pHead);
	PrintList(pHead);
	SListPopFront(&pHead);
	PrintList(pHead);
}
//SListFind()
void test2(){
	PNode pHead;
	PNode pret=NULL;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushFront(&pHead, 4);
	SListPushBack(&pHead, 2);
	PrintList(pHead);
	//pret=SListFind(pHead,4);
	pret = SListFind(pHead, 5);
	if (pret!=NULL)
	{
		printf("%d ", pret->_data);
	}
	else{
		printf("没找到\n");
	}
}
//SListInsert()
void test3(){
	PNode pHead;
	PNode pret = NULL;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushFront(&pHead, 4);
	SListPushBack(&pHead, 2);
	PrintList(pHead);
	pret = SListFind(pHead, 4);
	SListInsert(&pHead, pret, 5);
	PrintList(pHead);
}
//SListErase()//SListDestroy()//SListBack()//SListSize()//SListClear()
void test4(){
	PNode pHead;
	PNode pret = NULL;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushFront(&pHead, 4);
	SListPushBack(&pHead, 2);
	PrintList(pHead);
	/*pret = SListFind(pHead, 4);
	SListErase(&pHead,pret);
	PrintList(pHead);
	SListDestroy(&pHead);
	PrintList(pHead);
	int tmp=SListSize(pHead);
	printf("%d\n", tmp);
	SListClear(&pHead);
	PrintList(pHead);*/
	pret=SListBack(pHead);
	if (pret != NULL)
	{
		printf("%d ", pret->_data);
	}
	else{
		printf("链表为空\n");
	}
}
//-------------------------------------------------//
//-------------------------------------------------//
//------------------链表面试题---------------------//
//-------------------------------------------------//
//DeleteNotTailNode()//InsertPosFront()
void test5(){
	PNode pHead;
	PNode pret = NULL;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushFront(&pHead, 4);
	SListPushBack(&pHead, 2);
	PrintList(pHead);
	pret = SListFind(pHead, 4);
	//DeleteNotTailNode(pret);
	//PrintList(pHead);
	InsertPosFront(pret,6);
	PrintList(pHead);
}


//BubbleSort(pHead)//ReverseSList(&pHead)
void test6(){
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushFront(&pHead, 2);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 3);
	PrintList(pHead);
	BubbleSort(pHead);
	PrintList(pHead);
	//ReverseSList(&pHead);
	ReverseSListOP(&pHead);
	PrintList(pHead);
}
//MergeSList(&pHead1, &pHead2)
void test7(){
	PNode pHead1, pHead2;
	PNode pret = NULL;
	SListInit(&pHead1);
	SListInit(&pHead2);
	SListPushBack(&pHead1, 1);
	SListPushFront(&pHead1, 2);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 8);
	SListPushBack(&pHead2, 6);
	SListPushBack(&pHead2, 3);
	SListPushBack(&pHead2, 4);
	SListPushBack(&pHead2, 7);
	PrintList(pHead1);
	PrintList(pHead2);
	BubbleSort(pHead1);
	BubbleSort(pHead2);
	PrintList(pHead1);
	PrintList(pHead2);
	pret=MergeSList(&pHead1, &pHead2);
	if (pret!=NULL){
		PrintList(pret);
	}

}
//FindMiddleNode(pHead)
void test8(){
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushFront(&pHead, 2);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 6);
	//SListPushBack(&pHead, 3);
	//SListPushBack(&pHead, 4);
	PrintList(pHead);
	PNode pret = NULL;
	pret = FindMiddleNode(pHead);
	if (pret != NULL){
		printf("%d\n",pret->_data);
	}
}
//FindLastKNode(PNode pHead, int K)//DeleteLastKNode(PNode pHead, int K)
void test9(){
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushFront(&pHead, 2);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	PrintList(pHead);
	PNode pret = NULL;
	pret = FindLastKNode(pHead, 7);
	if (pret != NULL){
		printf("%d\n", pret->_data);
	}
	else
	{
		printf("无此结点\n");
	}
	DeleteLastKNode(&pHead,6);
	PrintList(pHead);
}
//IsCrossWithoutCircle(pHead1, pHead2);//GetCrossNode(pHead1, pHead2);
void test10(){
	PNode pHead1,pHead2;
	PNode pret = NULL;
	int ret = 0;
	SListInit(&pHead1);
	SListInit(&pHead2);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 8);
	SListPushBack(&pHead1, 6);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 4);
	PrintList(pHead1);
	SListPushBack(&pHead2, 1);
	SListPushBack(&pHead2, 7);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 9);
	SListPushBack(&pHead2, 10);
	PrintList(pHead2);
	SListBack(pHead1)->_pNext = SListFind(pHead2,2);
	ret=IsCrossWithoutCircle(pHead1, pHead2);
	if (ret!=0)
	{
		printf("两个不带环链表相交\n");
		pret = GetCrossNode(pHead1, pHead2);
		printf("%d\n", pret->_data);
	}
	else if (ret==0)
	{
		printf("两个不带环链表不相交\n");
	}
	
	
}
//JosephCircle(PNode* pHead, const int M)
void test11(){
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushFront(&pHead, 3);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 9);
	PrintList(pHead);
	SListBack(pHead)->_pNext = SListFind(pHead, 1);
	JosephCircle(&pHead, 3);
	pHead->_pNext = NULL;
	PrintList(pHead);
}
//IsCircle(PNode pHead)//GetCircleLen(PNode pHead)//GetEnterNode(PNode pHead, PNode pMeetNode)
void test12(){
	PNode pHead;
	PNode pret = NULL;
	PNode pEnter = NULL;
	int ret = 0;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushFront(&pHead, 3);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 9);
	PrintList(pHead);
	SListBack(pHead)->_pNext = SListFind(pHead, 5);
	pret = IsCircle(pHead);
	if (pret!=NULL)
	{
		printf("此单链表带环\n");
		printf("在这个点相遇 %d\n", pret->_data);
	}
	ret = GetCircleLen(pHead);
	if (ret!=0)
	{
		printf("环的长度为 %d\n", ret);

	}
	pEnter=GetEnterNode(pHead,pret);
	if (pret != NULL)
	{
		printf("入口点为 %d\n",pEnter->_data);
		
	}
}
void test13(){
	PNode pHead1, pHead2;
	PNode pret = NULL;
	int ret = 0;
	SListInit(&pHead1);
	SListInit(&pHead2);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 8);
	SListPushBack(&pHead1, 6);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 4);
	PrintList(pHead1);
	SListPushBack(&pHead2, 1);
	SListPushBack(&pHead2, 7);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 9);
	SListPushBack(&pHead2, 10);
	PrintList(pHead2);//默认状态下不带环不想交
	//SListBack(pHead1)->_pNext = SListFind(pHead2, 2);//两个不带环相交
	SListBack(pHead1)->_pNext = SListFind(pHead1, 6);
	//SListBack(pHead2)->_pNext = SListFind(pHead1, 8);//两个带环相交且为环外相交
	//SListBack(pHead2)->_pNext = SListFind(pHead1, 3);//两个带环相交且为环内相交
	SListBack(pHead2)->_pNext = SListFind(pHead2, 2);//带环不相交
	ret = IsListCrossWithCircle(pHead1, pHead2);

	if (ret == 0)
		printf("不相交\n");
	else if (ret == 1)
		printf("不带环相交\n");
	else if (ret == 2)
		printf("带环相交\n");
}
int main(){
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	//test11();
	//test12();
	test13();
	system("pause");
	return 0;
}