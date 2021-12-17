#define _CRT_SECURE_NO_WARNINGS
#ifndef _DCLIST_H_
#define _DCLIST_H_

#include"Common.h"
typedef struct DCListNode
{
	ElemType data;
	struct DCListNode* next;
	struct DCListNode* prev;
}DCListNode;

typedef struct DCList
{
	struct DCListNode* head;
}DCList;
DCListNode* _Buynode(ElemType v);
void DCListInit(DCList* plist);
void DCListPushBack(DCList* plist, ElemType v);
void DCListPushFront(DCList* plist, ElemType v);
void DCListShow(DCList* plist);
void DCListPopBack(DCList* plist);
void DCListPopFront(DCList* plist);
DCListNode* DCListFind(DCList* plist, ElemType key);
void DCListInsertByVal(DCList* plist, ElemType v);
void DCListErase(DCList* plist, ElemType key);
size_t DCListLength(DCList* plist);
void DCListSort(DCList* plist);
void DCListReverse(DCList* plist);
void DCListClear(DCList* plist);
void DCListDestroy(DCList* plist);


DCListNode* _BuyNode(ElemType v)//创建节点
{
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->data = v;
	s->prev = s->next = s;
	return s;
}
void DCListInit(DCList* plist)//初始化节点
{
	plist->head = _BuyNode(0);
}
void DCListPushBack(DCList* plist, ElemType v)
{
	DCListNode* s = _BuyNode(v);
	s->next = plist->head;
	s->prev = plist->head->prev;
	s->next->prev = s;
	s->prev->next = s;
}
void DCListPushFront(DCList* plist, ElemType v)
{
	DCListNode* s = _BuyNode(v);
	s->next = plist->head->next;
	s->prev = plist->head;
	s->next->prev = s;
	s->prev->next = s;

}
void DCListShow(DCList* plist)
{
	DCListNode* p = plist->head->next;
	while (p!= plist->head)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
void DCListPopBack(DCList* plist)
{
	DCListNode* p = plist->head->prev;
	if (plist->head->next == plist->head)
		return;
	p->next->prev = p->prev;
	p->prev->next = p->next;
	free(p);
}
void DCListPopFront(DCList* plist)
{
	DCListNode* p = plist->head->next;
	if (plist->head->next == plist->head)
		return;
	p->next->prev = p->prev;
	p->prev->next = p->next;
	free(p);
}
DCListNode* DCListFind(DCList* plist, ElemType key)
{
	DCListNode* p = plist->head->next;
	while (p != plist->head && p->data != key)
		p = p->next;
	if (p == plist->head)
		return NULL;
	return p;
}
void DCListInsertByVal(DCList* plist, ElemType v)
{
	DCListNode* p = plist->head->next;
	while (p != plist->head && v > p->data)
		p = p->next;
	DCListNode* s = _BuyNode(v);
	s->next = p;
	s->prev = p->prev;
	s->prev->next = s;
	s->next->prev = s;
}
void DCListErase(DCList* plist, ElemType key)
{
	DCListNode* p = DCListFind(plist, key);
	if (p == NULL)
		return;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);

}
size_t DCListLength(DCList* plist)
{
	DCListNode* p = plist->head->next;
	size_t len = 0;
	while (p != plist->head)
	{
		len++;
		p = p->next;
	}
	return len;
}
void DCListSort(DCList* plist)
{
	DCListNode* p, * q;
	size_t size = DCListLength(plist);
	if (size <= 1)
		return;
	p = plist->head->next;
	q = p->next;
	//断开节点
	p->next = plist->head;
	plist->head->prev = p;
	while (q != plist->head)
	{
		p = q;
		q = q->next;
		//寻找插入的位置
		DCListNode* pos = plist->head->next;
		while (pos != plist->head && p->data>pos->data  )
			pos = pos->next;
		//插入节点p
		p->next = pos;
		p->prev = pos->prev;
		p->prev->next = p;
		p->next->prev = p;
	}
}
void DCListReverse(DCList* plist)
{
	DCListNode* p, * q;
	size_t size = DCListLength(plist);
	if (size <= 1)
		return;
	p = plist->head->next;
	q = p->next;
	//断开链表
	p->next = plist->head;
	plist->head->prev = p;
	while (q != plist->head)
	{
		p = q;
		q = q->next;

		p->next = plist->head->next;
		p->prev = plist->head;
		p->next->prev = p;
		p->prev->next = p;
	}
}
void DCListClear(DCList* plist)
{
	DCListNode* p = plist->head->next;
	while (p != plist->head)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);

		p = plist->head->next;
	}
}

void DCListDestroy(DCList* plist)
{
	DCListClear(plist);
	free(plist->head);
	plist->head = NULL;
}




#endif /* _DCLIST_H_ */