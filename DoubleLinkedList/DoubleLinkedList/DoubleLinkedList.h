#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
}Node;

// 함수 원형 선언
Node* DLL_CreateNode(ElementType NewData);				// 노드 생성 함수
void DLL_Destroy(Node* Node);							// 노드 소멸 함수
void DLL_AppendNode(Node** Head, Node* NewNode);		// 노드 추가 함수
void DLL_InsertAfter(Node* Current, Node* NewNode);		// 노드 삽입 함수
void DLL_RemoveNode(Node** Head, Node* Remove);			// 노드 제거 함수	
Node* DLL_GetNodeAt(Node* Head, int Location);			// 노드 탐색 함수
int DLL_GetNodeCount(Node* Head);						// 노드 수 세기 함수

#endif