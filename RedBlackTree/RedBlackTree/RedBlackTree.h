#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H
#pragma warning(disable: 4996)

// ���� �� Ʈ�� ��Ģ
// 1. ��� ���� ������ �ƴϸ� �������̴�
// 2. ��Ʈ ���� �������̴�
// 3. �� ���� ��� �������̴�
// 4. ���� ����� �ڽĵ��� ��� �������̴� ������ ������ ����� �ڽ��� �������� �ʿ�� ����
// 5. ��Ʈ ��忡�� ��� �� ��� ���̿� �ִ� ������ ����� ���� ��� �����ϴ� -> ���ذ� �� �ʿ���

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagRBTNode
{
	struct tagRBTNode* Parent;
	struct tagRBTNode* Left;
	struct tagRBTNode* Right;

	enum { RED, BLACK } Color;									//	��� ���� ��Ÿ��

	ElementType Data;
}RBTNode;

void RBT_DestroyTree(RBTNode* Tree);							// Ʈ�� �Ҹ� �Լ�

RBTNode* RBT_CreateNode(ElementType NewData);					// ��� ���� �Լ�
void RBT_DestroyNode(RBTNode* Node);							// ��� �Ҹ� �Լ�

RBTNode* RBT_SearchNode(RBTNode* Tree, ElementType Target);		// ��� Ž�� �Լ�
RBTNode* RBT_SearchMinNode(RBTNode Tree);						// �ּڰ� ��� Ž�� �Լ�
void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode);			// ��� ���� �Լ�
void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode);	
RBTNode* RBT_RemoveNode(RBTNode** Root, ElementType Data);		// ��� ���� �Լ�
void RBT_RebuildAfterInsert(RBTNode** Tree, RBTNode* NewNode);	// ��� ���� �� ����� �Լ�
void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* Successor);// ��� ���� �� ����� �Լ�

void RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount);	// Ʈ�� ��� �Լ�
void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent);			// ��ȸ�� ���� �Լ� -> ������ �ڽİ� �θ��� ��ġ�� ��ȯ
void RBT_RotateRight(RBTNode** Root, RBTNode* Parent);			// ��ȸ�� ���� �Լ� -> ���� �ڽİ� �θ��� ��ġ�� ��ȯ

#endif