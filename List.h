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
//����������
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
//������ʵ��
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
	//����ڵ�
	ListNode* s = _BuyNode(v);
	//����ڵ�
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
	ListNode* prev = NULL;//����һ��ǰ���ڵ�
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
	if (*plist == NULL)//������
	{
		*plist = s;
		return;
	}
	if (v < (*plist)->data)//�����һ���ڵ����С���²������
	{
		s->next = *plist;
		*plist = s;
		return;
	}
	p = *plist;
	while (p->next != NULL && v > p->next->data)
		p=p->next;
	s->next = p->next;//����
	p->next = s;
}
void ListEraseByVal(List* plist, ElemType key)
{
	ListNode* p = *plist;
	ListNode *prev = NULL;
	if (p == NULL)//���Ϊ��ֱ�ӷ���
		return;
	while (p != NULL && p->data != key)//���α������
	{
		prev = p;
		p = p->next;
	}
	if (p == NULL)//���û���ҵ�ֱ�ӷ���
		return;
	if (prev == NULL)//����ҵ����ǵ�һ�����
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
	if (*plist == NULL && (*plist)->next == NULL)//�����һ���ڵ�Ϊ�ջ��ߵ�һ���ڵ����һ�����Ϊ������������
		return;
	p = (*plist)->next;
	(*plist)->next = 0;//�Ͽ�����
	while (p != NULL)
	{
		ListNode* q = p->next;//����һ��q��㣬��q���ʼ��ָ��p����һ�����
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
	(*plist)->next = NULL;//�Ͽ�����
	while (p != NULL)
	{
		ListNode* q = p->next;
		//ͷ��ڵ�
		p->next = *plist;
		*plist = p;
		p = q;
	}
}
#endif /* _LIST_H_ */