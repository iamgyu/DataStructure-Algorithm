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

PriorityQueue* PQ_Create(int IntitialSize);						// ���� �̿��� ť ���� �Լ�
void PQ_Destroy(PriorityQueue* PQ);								// ���� �̿��� ť �Ҹ� �Լ�
void PQ_Enqueue(PriorityQueue* PQ, PQNode NewData);				// ��� ���� �Լ�
void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root);				// ��� ���� �Լ�
int PQ_GetParent(int Index);									// �θ� ��带 �������� �Լ�
int PQ_GetLeftChild(int Index);									// �ڽ� ��带 �������� �Լ�
void PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2);	// ��带 �ٲ��ִ� �Լ�
int PQ_IsEmpty(PriorityQueue* PQ);								// ť�� ����ִ��� Ȯ�� �ϴ� �Լ�

#endif