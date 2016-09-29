#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <memory.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagHeapNode		// 힙의 각 노드를 표현
{
	ElementType Data;
}HeapNode;

typedef struct tagHeap			// 힙 자체를 표현
{
	HeapNode* Nodes;			// 배열의 크기
	int Capacity;				// 힙의 용량
	int UsedSize;				// 실제 배열 안에 들어 있는 큐 요소의 수
}Heap;

Heap* HEAP_Create(int InitialSize);						// 힙 생성 함수
void HEAP_Destroy(Heap* H);								// 힙 소멸 함수
void HEAP_Insert(Heap* H, ElementType NewData);			// 노드 삽입 함수
void HEAP_DeleteMin(Heap* H, HeapNode* Root);			// 최솟값 노드 삭제 함수
int HEAP_GetParent(int Index);							// 부모 노드를 가져오는 함수
int HEAP_GetLeftChild(int Index);						// 왼쪽 자식 노드를 가져오는 함수
void HEAP_SwapNodes(Heap* H, int Index1, int Index2);	// 노드를 서로 바꾸는 함수
void HEAP_PrintNodes(Heap* H);							// 힙 출력 함수

#endif