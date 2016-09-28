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

LCRSNode* LCRS_CreateNode(ElementType NewData);						// 노드 생성 함수
void LCRS_DestroyNode(LCRSNode* Node);								// 노드 소멸 함수
void LCRS_DestroyTree(LCRSNode* Root);								// 트리 소멸 함수

void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child);			// 자식 노드 추가 함수
void LCRS_PrintTree(LCRSNode* Node, int Depth);					// 트리 출력 함수

#endif