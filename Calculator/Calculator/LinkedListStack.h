#ifndef LINKED_LIST_STACK
#define LINKED_LIST_STACK
#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include <stdlib.h>

typedef struct tagNode
{
	char* Data;
	struct tagNode* NextNode;
}Node;

typedef struct tagLinkedListStack
{
	Node* List;		// ��� ����� �ּҸ� ����Ŵ
	Node* Top;		// ���� ����� �ּҸ� ����Ŵ
}LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack);				// ���� ���� �Լ�
void LLS_DestroyStack(LinkedListStack* Stack);				// ���� �Ҹ� �Լ�

Node* LLS_CreateNode(char* Data);							// ���� ��� ���� �Լ�
void LLS_DestroyNode(Node* _Node);							// ���� ��� �Ҹ� �Լ�

void LLS_Push(LinkedListStack* Stack, Node* NewNode);		// ��� ���� ���� �Լ�
Node* LLS_Pop(LinkedListStack* Stack);						// ��� ���� ���� �Լ�

Node* LLS_Top(LinkedListStack* Stack);						// ������ �ֻ��� ��带 ��ȯ�ϴ� �Լ�(����X)
int LLS_GetSize(LinkedListStack* Stack);					// ������ ũ�⸦ ��� �Լ�
int LLS_IsEmpty(LinkedListStack* Stack);					// ������ ��� �ִ����� �����ϴ� �Լ�

#endif