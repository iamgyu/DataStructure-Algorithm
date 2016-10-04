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

HashTable* SHT_CreateHashTable(int TableSize);				// 해쉬 테이블 생성 함수
void SHT_Set(HashTable* HT, KeyType Key, ValueType Value);	// 해쉬 테이블 setter
ValueType SHT_Get(HashTable* HT, KeyType Key);				// 해쉬 테이블 getter
void SHT_DestroyHashTable(HashTable* HT);					// 해쉬 테이블 파괴 함수
int SHT_Hash(KeyType Key, int TableSize);					// Key를 Hash(암호화) 시키는 함수 -> 나눗셈법 사용

#endif