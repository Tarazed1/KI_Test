#pragma once
#include "PathNode.h"
class DijkstraNode : public PathNode
{
private:
	float accumulatedCost;
	PathNode* prevNode;
	PathNode* thisNode;

public:
	DijkstraNode();
	~DijkstraNode();

	float get_cost();
	PathNode* get_previous_node();
	PathNode* get_this_node();
};

