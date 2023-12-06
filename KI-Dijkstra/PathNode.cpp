#include "PathNode.h"

PathNode::PathNode()
{
	name = "empty";
	nodePosition = XMFLOAT3(0, 0, 0);
	neighbourNodes = list<PathNode*>();
}

PathNode::PathNode(string name, XMFLOAT3 pos)
{
	this->name = name;
	this->nodePosition = pos;
	neighbourNodes = list<PathNode*>();
}

PathNode::PathNode(string name, XMFLOAT3 pos, list<PathNode*> startNodes)
{
	this->name = name;
	this->nodePosition = pos;
	this->neighbourNodes = startNodes;
}

PathNode::~PathNode()
{
}

void PathNode::add_node(PathNode* inNode)
{
	neighbourNodes.push_back(inNode);
}

void PathNode::remove_node(PathNode* outNode)
{
	if (is_neighbour(outNode)) {
		neighbourNodes.remove(outNode);
	}
}

bool PathNode::is_neighbour(PathNode* nodeToCheck)
{
	bool exists = false;

	for (auto const& i : neighbourNodes) {
		if (nodeToCheck == i) {
			exists = true;
			break;
		}
	}

	return exists;
}

XMFLOAT3 PathNode::get_position()
{
	return nodePosition;
}
