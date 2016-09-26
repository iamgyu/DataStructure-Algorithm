#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;
}Node;

// 함수 원형 선언
Node* SLL_CreateNode(ElementType NewData);				// 노드 생성 함수
void SLL_DestroyNode(Node* Node);						// 노드 소멸 함수
void SLL_AppendNode(Node** Head, Node* NewNode);		// 노드 추가 함수
void SLL_InsertAfter(Node* Current, Node* NewNode);		// 노드 삽입 함수
void SLL_InsertNewHead(Node** Head, Node* NewHead);		
void SLL_RemoveNode(Node** Head, Node* Remove);			// 노드 제거 함수
Node* SLL_GetNodeAt(Node* Head, int Location);			// 노드 탐색 함수
int SLL_GetNodeCount(Node* Head);						// 노드 수 세기 함수

#endif