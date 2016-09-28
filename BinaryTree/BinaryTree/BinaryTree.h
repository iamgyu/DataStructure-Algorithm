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

SBTNode* SBT_CreateNode(ElementType NewData);		// 노드 생성 함수
void SBT_DestroyNode(SBTNode* Node);				// 노드 소멸 함수
void SBT_DestroyTree(SBTNode* Node);				// 트리 소멸 함수

void SBT_PreorderPrintTree(SBTNode* Node);			// 전위 순회를 응용한 출력 함수
void SBT_InorderPrintTree(SBTNode* Node);			// 중위 순회를 응용한 출력 함수
void SBT_PostorderPrintTree(SBTNode* Node);			// 후위 순회를 응용한 출력 함수

#endif