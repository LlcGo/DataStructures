#include <stdio.h>
#define MAXSIZE 20

enum{ERROR,SUCCESS};

typedef int ELemType;
typedef struct
{
	ELemType data[MAXSIZE];
	int length; //���Ա���
} List;

int main(void)
{
	return 0;
}

ELemType insterList(List* list, int i, ELemType e)
{   
	int j;
	// ������Ա��Ѿ���Ա
	if (list->length > MAXSIZE)
	{
		return ERROR;
	}
	// ��������λ�ó����洢���λ�û�����Сλ��
	if (i < 1 || i > list->length + 1)
	{
		return ERROR;
	}
	// ����λ�ò��ڱ�β��
	if (i <= list->length)
	{
		for (j = list->length; j > i - 1; j--)
		{
			// �ճ��ռ�
			list->data[j + 1] = list->data[j];
		}
	}
	list->data[i - 1] = e;
	list->length++;
	return SUCCESS;
}

ELemType getElment(List* list, int i, ELemType * e)
{
	// ���i�������Ա�߽�
	if (i > list->length || i < 1)
	{
		return ERROR;
	}
    
	*e = list->data[i - 1];
	return SUCCESS;

}

