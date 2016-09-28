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

ETNode* ET_CreateNode(ElementType NewData);		// 노드 생성 함수
void ET_DestroyNode(ETNode* Node);				// 노드 제거 함수
void ET_DestroyTree(ETNode* Root);				// 트리 제거 함수

void ET_PreorderPrintTree(ETNode* Node);		// 전위 순회를 응용한 출력 함수
void ET_InorderPrintTree(ETNode* Node);			// 중위 순회를 응용한 출력 함수
void ET_PostorderPrintTree(ETNode* Node);		// 후위 순회를 응용한 출력 함수
void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node);	// 수식 트리 구축 함수
double ET_Evaluate(ETNode* Tree);				// 수식 트리 계산 함수

#endif