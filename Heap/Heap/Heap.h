#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <memory.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagHeapNode		// ���� �� ��带 ǥ��
{
	ElementType Data;
}HeapNode;

typedef struct tagHeap			// �� ��ü�� ǥ��
{
	HeapNode* Nodes;			// �迭�� ũ��
	int Capacity;				// ���� �뷮
	int UsedSize;				// ���� �迭 �ȿ� ��� �ִ� ť ����� ��
}Heap;

Heap* HEAP_Create(int InitialSize);						// �� ���� �Լ�
void HEAP_Destroy(Heap* H);								// �� �Ҹ� �Լ�
void HEAP_Insert(Heap* H, ElementType NewData);			// ��� ���� �Լ�
void HEAP_DeleteMin(Heap* H, HeapNode* Root);			// �ּڰ� ��� ���� �Լ�
int HEAP_GetParent(int Index);							// �θ� ��带 �������� �Լ�
int HEAP_GetLeftChild(int Index);						// ���� �ڽ� ��带 �������� �Լ�
void HEAP_SwapNodes(Heap* H, int Index1, int Index2);	// ��带 ���� �ٲٴ� �Լ�
void HEAP_PrintNodes(Heap* H);							// �� ��� �Լ�

#endif