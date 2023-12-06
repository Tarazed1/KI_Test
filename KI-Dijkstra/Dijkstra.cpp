#include "Dijkstra.h"

Dijkstra::Dijkstra() : PathNode()
{
	graph = new GraphCore();
	currentNode = new DijkstraNode();
	startNode = new PathNode();
	stopNode = new PathNode();

}

Dijkstra::Dijkstra(string name, XMFLOAT3 pos) : PathNode(name, pos)
{
	graph = new GraphCore();
	currentNode = new DijkstraNode();
	startNode = new PathNode();
	stopNode = new PathNode();
}

Dijkstra::Dijkstra(string name, XMFLOAT3 pos, list<PathNode*> startNodes) : PathNode (name, pos, startNodes)
{
	graph = new GraphCore();
	currentNode = new DijkstraNode();
	startNode = new PathNode();
	stopNode = new PathNode();
}

Dijkstra::~Dijkstra()
{
}

void Dijkstra::compute()
{
}

void Dijkstra::print()
{
}
