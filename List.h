#define _CRT_SECURE_NO_WARNINGS
#ifndef _LIST_H_
#define _LIST_H_
#include"Common.h"
typedef struct ListNode
{
	ElemType data;
	struct ListNode* next;
}ListNode;
typedef ListNode* List;
//函数的声明
ListNode* _BuyNode(ElemType v);
void ListInit(List* plist);
void ListShow(List plist);
void ListPushBack(List* plist, ElemType v);
void ListPushFront(List* plist, ElemType v);
void ListPopBack(List* plist);
void ListPopFront(List* plist);
void ListInsertByVal(List* plist, ElemType v);
void ListEraseByVal(List* plist, ElemType key);
void ListClear(List* plist);
void ListDestroy(List* plist);
ListNode* ListFindByVal(List plist, ElemType key);
size_t ListLength(List plist);
void ListSort(List* plist);
void ListReverse(List* plist);
//函数的实现
ListNode* _BuyNode(ElemType v)
{
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));
	assert(s != NULL);
	s->data = v;
	s->next = NULL;
	return s;
}
void ListInit(List* plist)
{
	*plist = NULL;
}
void ListShow(List plist)
{
	ListNode* p = plist;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p=p->next;
	}
	printf("Over.\n");
}
void ListPushBack(List* plist, ElemType v)
{
	//申请节点
	ListNode* s = _BuyNode(v);
	//插入节点
	ListNode* p = *plist;
	if (p == NULL)
	{
		*plist = s;
		return;
	}
	while (p->next != NULL)
		p = p->next;

	p->next = s;
}
void ListPushFront(List* plist, ElemType v)
{
	ListNode* s = _BuyNode(v);
	s->next = *plist;
	*plist = s;
}
void ListPopBack(List* plist)
{
	ListNode* p = *plist;
	ListNode* prev = NULL;//创建一个前驱节点
	if (*plist == NULL)
		return;
	while(p->next != NULL)
	{
		prev = p;
		p = p->next;
	}
	if (prev == NULL)
		*plist = NULL;
	else
		prev->next = NULL;
	free(p);
}
void ListPopFront(List* plist)
{
	ListNode* p = *plist;
	if (*plist == NULL)
		return;
	*plist = p->next;
	free(p);
}
void ListInsertByVal(List* plist, ElemType v)
{
	ListNode* p = NULL;
	ListNode* s = _BuyNode(v);
	if (*plist == NULL)//空链表
	{
		*plist = s;
		return;
	}
	if (v < (*plist)->data)//如果第一个节点的数小于新插入的数
	{
		s->next = *plist;
		*plist = s;
		return;
	}
	p = *plist;
	while (p->next != NULL && v > p->next->data)
		p=p->next;
	s->next = p->next;//插入
	p->next = s;
}
void ListEraseByVal(List* plist, ElemType key)
{
	ListNode* p = *plist;
	ListNode *prev = NULL;
	if (p == NULL)//如果为空直接返回
		return;
	while (p != NULL && p->data != key)//依次遍历结点
	{
		prev = p;
		p = p->next;
	}
	if (p == NULL)//如果没有找到直接返回
		return;
	if (prev == NULL)//如果找到的是第一个结点
		*plist = p->next;
	else
		prev->next = p->next;
	free(p);
}
void ListClear(List* plist)
{
	ListNode* p = NULL;
	while (*plist != NULL)
	{
		p = *plist;
		*plist = p->next;
		free(p);

	}
}
void ListDestroy(List* plist)
{
	ListClear(plist);
}
ListNode* ListFindByVal(List plist, ElemType key)
{
	ListNode* p = plist;
	while (p != NULL && p->data != key)
		p = p->next;
	return p;
}
size_t ListLength(List plist)
{
	ListNode* p = plist;
	size_t len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}
void ListSort(List* plist)
{
	ListNode* p;
	if (*plist == NULL && (*plist)->next == NULL)//如果第一个节点为空或者第一个节点的下一个结点为空则无需排序
		return;
	p = (*plist)->next;
	(*plist)->next = 0;//断开链表
	while (p != NULL)
	{
		ListNode* q = p->next;//创建一个q结点，让q结点始终指向p的下一个结点
		if (p->data < (*plist)->data)
		{
			p->next = *plist;
			*plist = p;
		}
		else
		{
			ListNode* prev = *plist;
			while (prev->next != NULL && p->data > prev->next->data)
				prev = prev->next;
			p->next = prev->next;
			prev->next = p;
		}
		p = q;
	}

}
void ListReverse(List* plist)
{
	ListNode* p = NULL;
	if (*plist == NULL || (*plist)->next == NULL)
		return;
	p = (*plist)->next;
	(*plist)->next = NULL;//断开链表
	while (p != NULL)
	{
		ListNode* q = p->next;
		//头插节点
		p->next = *plist;
		*plist = p;
		p = q;
	}
}
#endif /* _LIST_H_ */