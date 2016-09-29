#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

// 규칙 : 왼쪽 자식 노드는 나보다 작고, 오른쪽 자식 노드는 나보다 크다

#include <iostream>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagBSTNode
{
	struct tagBSTNode* Left;
	struct tagBSTNode* Right;

	ElementType Data;
}BSTNode;

BSTNode* BST_CreateNode(ElementType NewData);									// 노드 생성 함수
void BST_DestroyNode(BSTNode* Node);											// 노드 소멸 함수
void BST_DestroyTreE(BSTNode* Tree);											// 트리 제거 함수

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target);						// 노드 탐색 함수
BSTNode* BST_SearchMinNode(BSTNode* Tree);										// 최솟값 노드 탐색 함수
void BST_InsertNode(BSTNode* Tree, BSTNode *Child);								// 노드 삽입 함수
BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target);	// 노드 삭제 함수
void BST_InorderPrintTree(BSTNode* Node);										// 중위 순회를 응용한 출력 함수

#endif