#include <stdio.h>
#define MAXSIZE 20

enum{ERROR,SUCCESS};

typedef int ELemType;
typedef struct
{
	ELemType data[MAXSIZE];
	int length; //线性表长度
} List;

int main(void)
{
	return 0;
}

ELemType insterList(List* list, int i, ELemType e)
{   
	int j;
	// 如果线性表已经满员
	if (list->length > MAXSIZE)
	{
		return ERROR;
	}
	// 如果插入的位置超过存储最大位置或者最小位置
	if (i < 1 || i > list->length)
	{
		return ERROR;
	}
	// 插入位置不在表尾巴
	if (i <= list->length)
	{
		for (j = list->length; j > i - 1; j--)
		{
			// 空出空间
			list->data[j + 1] = list->data[j];
		}
	}
	list->data[i - 1] = e;
	list->length++;
	return SUCCESS;
}



