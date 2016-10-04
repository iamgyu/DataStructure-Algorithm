#ifndef SIMPLE_HASHTABLE_H
#define SIMPLE_HASHTABLE_H

#include <iostream>
#include <stdlib.h>

typedef int KeyType;
typedef int ValueType;

typedef struct tagNode
{
	KeyType Key;
	ValueType Value;
}Node;

typedef struct tagHashTable
{
	int TableSize;
	Node* Table;
}HashTable;

HashTable* SHT_CreateHashTable(int TableSize);				// �ؽ� ���̺� ���� �Լ�
void SHT_Set(HashTable* HT, KeyType Key, ValueType Value);	// �ؽ� ���̺� setter
ValueType SHT_Get(HashTable* HT, KeyType Key);				// �ؽ� ���̺� getter
void SHT_DestroyHashTable(HashTable* HT);					// �ؽ� ���̺� �ı� �Լ�
int SHT_Hash(KeyType Key, int TableSize);					// Key�� Hash(��ȣȭ) ��Ű�� �Լ� -> �������� ���

#endif