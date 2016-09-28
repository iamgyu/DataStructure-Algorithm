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

void LQ_CreateQueue(LinkedQueue** Queue);			// ��ũ��ť ���� �Լ�
void LQ_DestroyQueue(LinkedQueue* Queue);			// ��ũ��ť �Ҹ� �Լ�

Node* LQ_CreateNode(char* NewData);					// ��� ���� �Լ�
void LQ_DestroyNode(Node* _Node);					// ��� �Ҹ� �Լ�

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode);	// ��� ���� ���� �Լ�
Node* LQ_Dequeue(LinkedQueue* Queue);				// ��� ���� ���� �Լ�

int LQ_IsEmpty(LinkedQueue* Queue);					// ��ũ��ť�� ����ִ����� Ȯ�� �Լ�

#endif