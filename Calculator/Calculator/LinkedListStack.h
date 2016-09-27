#ifndef LINKED_LIST_STACK
#define LINKED_LIST_STACK
#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include <stdlib.h>

typedef struct tagNode
{
	char* Data;
	struct tagNode* NextNode;
}Node;

typedef struct tagLinkedListStack
{
	Node* List;		// 헤드 노드의 주소를 가리킴
	Node* Top;		// 테일 노드의 주소를 가리킴
}LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack);				// 스택 생성 함수
void LLS_DestroyStack(LinkedListStack* Stack);				// 스택 소멸 함수

Node* LLS_CreateNode(char* Data);							// 스택 노드 생성 함수
void LLS_DestroyNode(Node* _Node);							// 스택 노드 소멸 함수

void LLS_Push(LinkedListStack* Stack, Node* NewNode);		// 노드 삽입 연산 함수
Node* LLS_Pop(LinkedListStack* Stack);						// 노드 제거 연산 함수

Node* LLS_Top(LinkedListStack* Stack);						// 스택의 최상위 노드를 반환하는 함수(제거X)
int LLS_GetSize(LinkedListStack* Stack);					// 스택의 크기를 재는 함수
int LLS_IsEmpty(LinkedListStack* Stack);					// 스택이 비어 있는지를 점검하는 함수

#endif