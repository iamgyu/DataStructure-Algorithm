#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <iostream>
#include <stdlib.h>

typedef struct tagDisjointSet
{
	struct tagDisjointSet* Parent;
	void* Data;
}DisjointSet;

void DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2);		// �и� ������ ������ ���� �Լ�
DisjointSet* DS_FindSet(DisjointSet* Set);					// ���� Ž�� �Լ�
DisjointSet* DS_MakeSet(void* NewData);						// ���� ���� �Լ�
void DS_DestroySet(DisjointSet* Set);						// ���� �Ҹ� �Լ�

#endif