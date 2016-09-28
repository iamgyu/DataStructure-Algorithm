#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#pragma warning (disable : 4996)

#include <iostream>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode
{
	char* Data;
	struct tagNode* NextNode;
}Node;

typedef struct tagLinkedQueue
{
	Node* Front;
	Node* Rear;
	int Count;
}LinkedQueue;

void LQ_CreateQueue(LinkedQueue** Queue);			// 링크드큐 생성 함수
void LQ_DestroyQueue(LinkedQueue* Queue);			// 링크드큐 소멸 함수

Node* LQ_CreateNode(char* NewData);					// 노드 생성 함수
void LQ_DestroyNode(Node* _Node);					// 노드 소멸 함수

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode);	// 노드 삽입 연산 함수
Node* LQ_Dequeue(LinkedQueue* Queue);				// 노드 제거 연산 함수

int LQ_IsEmpty(LinkedQueue* Queue);					// 링크드큐가 비어있는지의 확인 함수

#endif