#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

// ��Ģ : ���� �ڽ� ���� ������ �۰�, ������ �ڽ� ���� ������ ũ��

#include <iostream>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagBSTNode
{
	struct tagBSTNode* Left;
	struct tagBSTNode* Right;

	ElementType Data;
}BSTNode;

BSTNode* BST_CreateNode(ElementType NewData);									// ��� ���� �Լ�
void BST_DestroyNode(BSTNode* Node);											// ��� �Ҹ� �Լ�
void BST_DestroyTreE(BSTNode* Tree);											// Ʈ�� ���� �Լ�

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target);						// ��� Ž�� �Լ�
BSTNode* BST_SearchMinNode(BSTNode* Tree);										// �ּڰ� ��� Ž�� �Լ�
void BST_InsertNode(BSTNode* Tree, BSTNode *Child);								// ��� ���� �Լ�
BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target);	// ��� ���� �Լ�
void BST_InorderPrintTree(BSTNode* Node);										// ���� ��ȸ�� ������ ��� �Լ�

#endif