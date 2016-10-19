#include "ListBaseStack.h"
#include <iostream>

void StackInit(Stack* pstack)
{
	pstack->head = NULL;				// ������ ���� head�� NULL�� �ʱ�ȭ�Ѵ�
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->head == NULL)			// ������ ��� head���� NULL�� ����ȴ�
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));	// �� ��� ����

	newNode->data = data;							// �� ��忡 ������ ����
	newNode->next = pstack->head;					// �� ��尡 �ֱٿ� �߰��� ��带 ����Ŵ

	pstack->head = newNode;							// ������ ���� head�� �� ��带 ����Ŵ
}

Data SPop(Stack* pstack)
{
	Data rdata;
	Node* rnode;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;						// ������ ����� �����͸� �ӽ÷� ����
	rnode = pstack->head;							// ������ ����� �ּ� ���� �ӽ÷� ����

	pstack->head = pstack->head->next;				// ������ ����� ���� ��带 head�� ����Ŵ
	free(rnode);									// ��� ����
	return rdata;									// ������ ����� ������ ��ȯ
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;						// head�� ����Ű�� ��忡 ����� ������ ��ȯ
}