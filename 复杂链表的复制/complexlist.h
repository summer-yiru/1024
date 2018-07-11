#define _CRT_SECURE_NO_WARNINGS 1
typedef int DataType;
typedef struct ComplexListNode
{
	struct ComplexListNode* _pNext;
	struct ComplexListNode* _random;
	DataType _data;
}CListNode, *PCListNode;
PCListNode BuyNewNode(int data);
PCListNode MakeComplexList();
PCListNode CopyComplexList(PCListNode pHead);