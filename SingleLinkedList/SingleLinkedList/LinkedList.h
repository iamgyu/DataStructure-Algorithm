#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;
}Node;

// �Լ� ���� ����
Node* SLL_CreateNode(ElementType NewData);				// ��� ���� �Լ�
void SLL_DestroyNode(Node* Node);						// ��� �Ҹ� �Լ�
void SLL_AppendNode(Node** Head, Node* NewNode);		// ��� �߰� �Լ�
void SLL_InsertAfter(Node* Current, Node* NewNode);		// ��� ���� �Լ�
void SLL_InsertNewHead(Node** Head, Node* NewHead);		
void SLL_RemoveNode(Node** Head, Node* Remove);			// ��� ���� �Լ�
Node* SLL_GetNodeAt(Node* Head, int Location);			// ��� Ž�� �Լ�
int SLL_GetNodeCount(Node* Head);						// ��� �� ���� �Լ�

#endif