#include <stdio.h>
enum{SUCCESS,ERROR};
typedef int ElemType;
typedef struct  Node{
	ElemType data;
	struct Node *next;
} Node;
typedef struct Node* LinkList;


ElemType  getElem(LinkList list,int i,ElemType *e)
{
	LinkList current = list;
	int k = 1;
	while (current && k < i)
	{
		current = current->next;
		k++;
	}

	if (!current || k > i)
	{
		return ERROR;
	}

	*e = list->data;
		 
	return SUCCESS;
}


ElemType  instertElem(LinkList list, int i, ElemType * e)
{
	int k = 1;
	LinkList current = list;
	LinkList pre = NULL;
	// 找到位置

	while (current && k < i)
	{
		current = current->next;
		k++;
	}

	if (!current || k > i)
	{
		return ERROR;
	}
	pre = (LinkList)malloc(sizeof(LinkList));
	pre->data = *e;
	pre->next = current->next;
	current->next = pre;

	return SUCCESS;
}

ElemType  deleteElem(LinkList list, int i, ElemType * e)
{
	int k = 1;
	LinkList current = list;
	// 找到位置

	while (current && k < i)
	{
		current = current->next;
		k++;
	}

	// 下一个节点为null
	if (!(current->next) || k > i)
	{
		return ERROR;
	}

	*e = current->next->data;
	current->next = current->next->next;
	

	return SUCCESS;
}