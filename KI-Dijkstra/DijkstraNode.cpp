#include "DijkstraNode.h"

DijkstraNode::DijkstraNode()
{
}

DijkstraNode::~DijkstraNode()
{
}

float DijkstraNode::get_cost()
{
	return accumulatedCost;
}

PathNode* DijkstraNode::get_previous_node()
{
	return prevNode;
}

PathNode* DijkstraNode::get_this_node()
{
	return thisNode;
}
