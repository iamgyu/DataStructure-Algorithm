#ifndef CHAINING_H
#define CHAINING_H
#pragma warning(disable: 4996)

#include <iostream>
#include <stdlib.h>
#include <string.h>

typedef char* KeyType;		// 키의 자료형
typedef char* ValueType;	// 키의 짝으로 입력될 데이터의 자료형

// 링크드 리스트의 노드
typedef struct tagNode
{
	KeyType Key;
	ValueType Value;

	struct tagNode* Next;
}Node;

// 링크드 리스트
typedef Node* List;

// 해시 테이블
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