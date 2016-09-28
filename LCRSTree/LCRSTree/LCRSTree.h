#ifndef LCRSTREE_H
#define LCRSTREE_H

#include <iostream>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode
{
	struct tagLCRSNode* LeftChild;
	struct tagLCRSNode* RightSibling;

	ElementType Data;
}LCRSNode;

LCRSNode* LCRS_CreateNode(ElementType NewData);						// ��� ���� �Լ�
void LCRS_DestroyNode(LCRSNode* Node);								// ��� �Ҹ� �Լ�
void LCRS_DestroyTree(LCRSNode* Root);								// Ʈ�� �Ҹ� �Լ�

void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child);			// �ڽ� ��� �߰� �Լ�
void LCRS_PrintTree(LCRSNode* Node, int Depth);					// Ʈ�� ��� �Լ�

#endif