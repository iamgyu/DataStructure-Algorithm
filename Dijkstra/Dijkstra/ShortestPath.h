#ifndef SHORTESTPAHT_H
#define SHORTESTPAHT_H

#include "Graph.h"
#include "PriorityQueue.h"

#define MAX_WEIGHT 36267

void Dijkstra(Graph* G, Vertex* startVertex, Graph* MST);

#endif