#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stdlib.h>

enum VisitMode { Visited, NotVisited};

typedef int ElementType;

typedef struct tagVertex
{
	ElementType Data;				// �����͸� ��� �ʵ�
	int Visited;					// �׷��� ��ȸ �˰��򿡼� ����� �ʵ�
	int Index;						// ������ �ε���
	
	struct tagVertex* Next;			// ���������� ����Ű�� ������
	struct tagEdge* AdjacencyList;	// ���� ������ ��Ͽ� ���� ������
}Vertex;

typedef struct tagEdge
{
	int Weight;						// ������ ����ġ
	struct tagEdge* Next;			// ���� ������ ����Ű�� ������
	Vertex* From;					// ������ ��������
	Vertex* Target;					// ������ �� ����
}Edge;

typedef struct tagGraph
{
	Vertex* Vertices;				// ���� ��Ͽ� ���� ������
	int VertexCount;				// ������ ��
}Graph;

Graph* CreateGraph();
void DestroyGraph(Graph* G);

Vertex* CreateVertex(ElementType Data);
void DestroyVertex(Vertex* V);

Edge* CreateEdge(Vertex* From, Vertex* Target, int weight);
void DestroyEdge(Edge* E);

void AddVertex(Graph* G, Vertex* V);
void AddEdge(Vertex* v, Edge* E);
void PrintGraph(Graph* G);
#endif 