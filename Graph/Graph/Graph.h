#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stdlib.h>

enum VisitMode { Visited, NotVisited};

typedef int ElementType;

typedef struct tagVertex
{
	ElementType Data;				// 데이터를 담는 필드
	int Visited;					// 그래프 순회 알고리즘에서 사용할 필드
	int Index;						// 정점의 인덱스
	
	struct tagVertex* Next;			// 다음정점을 가리키는 포인터
	struct tagEdge* AdjacencyList;	// 인접 정점의 목록에 대한 포인터
}Vertex;

typedef struct tagEdge
{
	int Weight;						// 간선의 가중치
	struct tagEdge* Next;			// 다음 간선을 가리키는 포인터
	Vertex* From;					// 간선의 시작정점
	Vertex* Target;					// 간선의 끝 정점
}Edge;

typedef struct tagGraph
{
	Vertex* Vertices;				// 정점 목록에 대한 포인터
	int VertexCount;				// 정점의 수
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