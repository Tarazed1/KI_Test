#pragma once

#include <set>
#include "DijkstraNode.h"
#include "SortDijkstra.h"
#include "GraphCore.h"

using namespace std;

class Dijkstra : public PathNode
{
private:
	multiset<DijkstraNode*, SortDijkstra> closedList;
	DijkstraNode* currentNode;
	GraphCore* graph;
	multiset<DijkstraNode*, SortDijkstra> openList;
	PathNode* startNode;
	PathNode* stopNode;

public:
	Dijkstra();
	Dijkstra(string name, XMFLOAT3 pos);
	Dijkstra(string name, XMFLOAT3 pos, list<PathNode*> startNodes);
	~Dijkstra();

	void compute();
	void print();
};

