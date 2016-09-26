#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <iostream>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
}Node;

typedef struct tagArrayStack
{
	int Capacity;	// 스택 용량
	int Top;		// 최상위 노드 위치
	Node* Nodes;		// 노드 배열 (포인터 배열)
}ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity);		// 스택 생성 함수
void AS_DestroyStack(ArrayStack* Stack);					// 스택 소멸 함수
void AS_Push(ArrayStack* Stack, ElementType Data);			// 스택 노드 삽입 연산
ElementType AS_Pop(ArrayStack* Stack);						// 스택 노드 제거 연산
ElementType AS_Top(ArrayStack* Stack);						// 최상위 노드의 데이터 반환 함수
int AS_GetSize(ArrayStack* Stack);							// 현재 스택 크기 반환 함수
int AS_IsEmpty(ArrayStack* Stack);							// 스택이 비어 있는지 검사 하는 함수

#endif