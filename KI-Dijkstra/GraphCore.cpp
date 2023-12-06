#include "GraphCore.h"
#include "DijkstraNode.h"
#include <iostream>

GraphCore::GraphCore()
{

}

GraphCore::GraphCore(vector<PathNode*> startNodes)
{
	graphNodes = startNodes;
}

GraphCore::~GraphCore()
{
}

void GraphCore::add_node_to_graph(PathNode* inNode)
{
	if (std::find(graphNodes.begin(), graphNodes.end(), inNode) == graphNodes.end()) {
		graphNodes.push_back(inNode);
		connectionList.insert({ inNode, vector<NodeConnection>() });
	}
}

void GraphCore::create_connection(PathNode* startNode, PathNode* endNode, bool oneWay, bool addToGraph)
{
	bool startInGraph = true;

	if (std::find(graphNodes.begin(), graphNodes.end(), startNode) == graphNodes.end()) {
		//startNode not in list
		if (addToGraph) {
			startInGraph = false;
		} else {
			cout << "One or more nodes are not part of the graph!" << endl;
			return;
		}
	}

	if (std::find(graphNodes.begin(), graphNodes.end(), endNode) != graphNodes.end()) {
		//endNode not in graph
		if (addToGraph) {
			graphNodes.push_back(endNode);
			connectionList.insert({ endNode, vector<NodeConnection>() });
			if (!startInGraph) {
				graphNodes.push_back(startNode);
				connectionList.insert({ startNode, vector<NodeConnection>() });
			}
		}
		else {
			cout << "One or more nodes are not part of the graph!" << endl;
			return;
		}
	}

	//check if nodes have each other as neighbours
	if (!startNode->is_neighbour(endNode)) startNode->add_node(endNode);
	if (!endNode->is_neighbour(startNode)) endNode->add_node(startNode);

	if (connectionList.find(startNode) != connectionList.end()) {
		connectionList[startNode].push_back(NodeConnection(startNode, endNode));
	}

	if (!oneWay) {
		if (connectionList.find(endNode) != connectionList.end()) {
			connectionList[endNode].push_back(NodeConnection(endNode, startNode));
		}
	}
}

void GraphCore::generate_sample_graph()
{
	DijkstraNode* node = new DijkstraNode();
}
