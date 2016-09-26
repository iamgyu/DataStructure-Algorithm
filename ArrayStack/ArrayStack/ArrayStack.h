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
	int Capacity;	// ���� �뷮
	int Top;		// �ֻ��� ��� ��ġ
	Node* Nodes;		// ��� �迭 (������ �迭)
}ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity);		// ���� ���� �Լ�
void AS_DestroyStack(ArrayStack* Stack);					// ���� �Ҹ� �Լ�
void AS_Push(ArrayStack* Stack, ElementType Data);			// ���� ��� ���� ����
ElementType AS_Pop(ArrayStack* Stack);						// ���� ��� ���� ����
ElementType AS_Top(ArrayStack* Stack);						// �ֻ��� ����� ������ ��ȯ �Լ�
int AS_GetSize(ArrayStack* Stack);							// ���� ���� ũ�� ��ȯ �Լ�
int AS_IsEmpty(ArrayStack* Stack);							// ������ ��� �ִ��� �˻� �ϴ� �Լ�

#endif