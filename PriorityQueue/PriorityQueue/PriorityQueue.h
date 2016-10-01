#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <memory.h>
#include <stdlib.h>

typedef int PriorityType;

typedef struct tagePQNode
{
	PriorityType Priority;
	void* Data;
}PQNode;

typedef struct tagPriorityQueue
{
	PQNode* Nodes;
	int Capacity;
	int UsedSize;
}PriorityQueue;

PriorityQueue* PQ_Create(int IntitialSize);						// 힙을 이용한 큐 생성 함수
void PQ_Destroy(PriorityQueue* PQ);								// 힙을 이용한 큐 소멸 함수
void PQ_Enqueue(PriorityQueue* PQ, PQNode NewData);				// 노드 삽입 함수
void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root);				// 노드 삭제 함수
int PQ_GetParent(int Index);									// 부모 노드를 가져오는 함수
int PQ_GetLeftChild(int Index);									// 자식 노드를 가져오는 함수
void PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2);	// 노드를 바꿔주는 함수
int PQ_IsEmpty(PriorityQueue* PQ);								// 큐가 비어있는지 확인 하는 함수

#endif