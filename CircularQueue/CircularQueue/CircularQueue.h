#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <iostream>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
}Node;

typedef struct tagCircularQueue
{
	int Capacity;		// �뷮
	int Front;			// ������ �ε���
	int Rear;			// �Ĵ��� �ε���

	Node* Nodes;		// ��� �迭
}CircularQueue;

void CQ_CreateQueue(CircularQueue** Queue, int Capacity);	// ��ȯť ���� �Լ�
void CQ_DestroyQueue(CircularQueue* Queue);					// ��ȯť �Ҹ� �Լ�
void CQ_Enqueue(CircularQueue* Queue, ElementType Data);	// ���� ���� �Լ�
ElementType CQ_Dequeue(CircularQueue* Queue);				// ���� ���� �Լ�
int CQ_GetSize(CircularQueue* Queue);						// ���� ť ũ�� Ȯ�� �Լ�
int CQ_IsEmpty(CircularQueue* Queue);						// ���� ���� Ȯ�� �Լ�
int CQ_IsFull(CircularQueue* Queue);						// ��ȭ ���� Ȯ�� �Լ�

#endif