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
	int Capacity;		// 용량
	int Front;			// 전단의 인덱스
	int Rear;			// 후단의 인덱스

	Node* Nodes;		// 노드 배열
}CircularQueue;

void CQ_CreateQueue(CircularQueue** Queue, int Capacity);	// 순환큐 생성 함수
void CQ_DestroyQueue(CircularQueue* Queue);					// 순환큐 소멸 함수
void CQ_Enqueue(CircularQueue* Queue, ElementType Data);	// 삽입 연산 함수
ElementType CQ_Dequeue(CircularQueue* Queue);				// 제거 연산 함수
int CQ_GetSize(CircularQueue* Queue);						// 현재 큐 크기 확인 함수
int CQ_IsEmpty(CircularQueue* Queue);						// 공백 상태 확인 함수
int CQ_IsFull(CircularQueue* Queue);						// 포화 상태 확인 함수

#endif