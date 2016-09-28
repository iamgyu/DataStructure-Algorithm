#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagSBTNode
{
	struct tagSBTNode* Left;
	struct tagSBTNode* Right;

	ElementType Data;
}SBTNode;

SBTNode* SBT_CreateNode(ElementType NewData);		// ��� ���� �Լ�
void SBT_DestroyNode(SBTNode* Node);				// ��� �Ҹ� �Լ�
void SBT_DestroyTree(SBTNode* Node);				// Ʈ�� �Ҹ� �Լ�

void SBT_PreorderPrintTree(SBTNode* Node);			// ���� ��ȸ�� ������ ��� �Լ�
void SBT_InorderPrintTree(SBTNode* Node);			// ���� ��ȸ�� ������ ��� �Լ�
void SBT_PostorderPrintTree(SBTNode* Node);			// ���� ��ȸ�� ������ ��� �Լ�

#endif