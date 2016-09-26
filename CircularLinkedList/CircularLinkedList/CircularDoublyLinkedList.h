#ifndef CIRCULAR_DOUBLY_LINKEDLIST_H
#define CIRCULAR_DOUBLY_LINKEDLIST_H

#include <iostream>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
}Node;

// �Լ� ���� ����
Node* CDLL_CreateNode(ElementType NewData);				// ��� ���� �Լ�
void CDLL_DestroyNode(Node* Node);						// ��� �Ҹ�	�Լ�
void CDLL_AppendNode(Node** Head, Node* NewNode);		// ��� �߰� �Լ�
void CDLL_InsertAfter(Node* Current, Node* NewNode);	// ��� ���� �Լ�
void CDLL_RemoveNode(Node** Head, Node* Remove);		// ��� ���� �Լ�
Node* CDLL_GetNodeAt(Node* Head, int Location);			// ��� Ž�� �Լ�
int CDLL_GetNodeCount(Node* Head);						// ��� �� ���� �Լ�

#endif