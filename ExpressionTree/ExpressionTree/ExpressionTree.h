#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

typedef struct tagETNode
{
	struct tagETNode* Left;
	struct tagETNode* Right;
	
	ElementType Data;
}ETNode;

ETNode* ET_CreateNode(ElementType NewData);		// ��� ���� �Լ�
void ET_DestroyNode(ETNode* Node);				// ��� ���� �Լ�
void ET_DestroyTree(ETNode* Root);				// Ʈ�� ���� �Լ�

void ET_PreorderPrintTree(ETNode* Node);		// ���� ��ȸ�� ������ ��� �Լ�
void ET_InorderPrintTree(ETNode* Node);			// ���� ��ȸ�� ������ ��� �Լ�
void ET_PostorderPrintTree(ETNode* Node);		// ���� ��ȸ�� ������ ��� �Լ�
void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node);	// ���� Ʈ�� ���� �Լ�
double ET_Evaluate(ETNode* Tree);				// ���� Ʈ�� ��� �Լ�

#endif