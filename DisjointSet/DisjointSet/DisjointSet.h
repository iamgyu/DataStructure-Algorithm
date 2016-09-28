#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <iostream>
#include <stdlib.h>

typedef struct tagDisjointSet
{
	struct tagDisjointSet* Parent;
	void* Data;
}DisjointSet;

void DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2);		// 분리 집합의 합집합 연산 함수
DisjointSet* DS_FindSet(DisjointSet* Set);					// 집합 탐색 함수
DisjointSet* DS_MakeSet(void* NewData);						// 집합 생성 함수
void DS_DestroySet(DisjointSet* Set);						// 집합 소멸 함수

#endif