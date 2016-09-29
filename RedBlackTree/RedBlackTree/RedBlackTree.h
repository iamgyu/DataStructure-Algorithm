#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H
#pragma warning(disable: 4996)

// 레드 블랙 트리 규칙
// 1. 모든 노드는 빨간색 아니면 검은색이다
// 2. 루트 노드는 검은색이다
// 3. 잎 노드는 모두 검은색이다
// 4. 빨간 노드의 자식들은 모두 검은색이다 하지만 검은색 노드의 자식이 빨간색일 필요는 없다
// 5. 루트 노드에서 모든 잎 노드 사이에 있는 검은색 노드의 수는 모두 동일하다 -> 이해가 더 필요함

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagRBTNode
{
	struct tagRBTNode* Parent;
	struct tagRBTNode* Left;
	struct tagRBTNode* Right;

	enum { RED, BLACK } Color;									//	노드 색을 나타냄

	ElementType Data;
}RBTNode;

void RBT_DestroyTree(RBTNode* Tree);							// 트리 소멸 함수

RBTNode* RBT_CreateNode(ElementType NewData);					// 노드 생성 함수
void RBT_DestroyNode(RBTNode* Node);							// 노드 소멸 함수

RBTNode* RBT_SearchNode(RBTNode* Tree, ElementType Target);		// 노드 탐색 함수
RBTNode* RBT_SearchMinNode(RBTNode Tree);						// 최솟값 노드 탐색 함수
void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode);			// 노드 삽입 함수
void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode);	
RBTNode* RBT_RemoveNode(RBTNode** Root, ElementType Data);		// 노드 삭제 함수
void RBT_RebuildAfterInsert(RBTNode** Tree, RBTNode* NewNode);	// 노드 삽입 후 재빌드 함수
void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* Successor);// 노드 삭제 후 재빌드 함수

void RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount);	// 트리 출력 함수
void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent);			// 좌회전 연산 함수 -> 오른쪽 자식과 부모의 위치를 교환
void RBT_RotateRight(RBTNode** Root, RBTNode* Parent);			// 우회전 연산 함수 -> 왼쪽 자식과 부모의 위치를 교환

#endif