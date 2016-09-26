#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

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
Node* DLL_CreateNode(ElementType NewData);				// ��� ���� �Լ�
void DLL_Destroy(Node* Node);							// ��� �Ҹ� �Լ�
void DLL_AppendNode(Node** Head, Node* NewNode);		// ��� �߰� �Լ�
void DLL_InsertAfter(Node* Current, Node* NewNode);		// ��� ���� �Լ�
void DLL_RemoveNode(Node** Head, Node* Remove);			// ��� ���� �Լ�	
Node* DLL_GetNodeAt(Node* Head, int Location);			// ��� Ž�� �Լ�
int DLL_GetNodeCount(Node* Head);						// ��� �� ���� �Լ�

#endif