#ifndef CHAINING_H
#define CHAINING_H
#pragma warning(disable: 4996)

#include <iostream>
#include <stdlib.h>
#include <string.h>

typedef char* KeyType;		// Ű�� �ڷ���
typedef char* ValueType;	// Ű�� ¦���� �Էµ� �������� �ڷ���

// ��ũ�� ����Ʈ�� ���
typedef struct tagNode
{
	KeyType Key;
	ValueType Value;

	struct tagNode* Next;
}Node;

// ��ũ�� ����Ʈ
typedef Node* List;

// �ؽ� ���̺�
typedef struct tagHashTable
{
	int TableSize;
	List* Table;
}HashTable;

HashTable* CHT_CreateHashTalbe(int TableSize);
void CHT_DestroyHashTable(HashTable* HT);

Node* CHT_CreateNode(KeyType Key, ValueType Value);
void CHT_DestroyNode(Node* TheNode);

void CHT_Set(HashTable* HT, KeyType Key, ValueType Value);
ValueType CHT_Get(HashTable* HT, KeyType Key);
int CHT_Hash(KeyType Key, int KeyLength, int TableSize);

#endif