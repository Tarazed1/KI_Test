#pragma once

#include "PathNode.h"
#include <map>
#include <vector>
#include <DirectXMath.h>
#include <math.h>

using namespace std;
using namespace DirectX;

struct NodeConnection
{
public:
	PathNode* startNode;
	PathNode* endNode;
	float weight;

	NodeConnection(PathNode* start, PathNode* end) {
		this->startNode = start;
		this->endNode = end;
		XMFLOAT3 startPoint = start->get_position(), endPoint = end->get_position();
		XMFLOAT3 length = XMFLOAT3(endPoint.x - startPoint.x, endPoint.y - startPoint.y, endPoint.z - startPoint.z);
		weight = sqrt(pow(length.x, 2) + pow(length.y, 2) + pow(length.z, 2));
	}
};

class GraphCore
{
private:
	vector<PathNode*> graphNodes;
	map<PathNode*, vector<NodeConnection>> connectionList;
	

public:
	GraphCore();
	GraphCore(vector<PathNode*> startNodes);
	~GraphCore();

	void add_node_to_graph(PathNode* inNode);
	void create_connection(PathNode* startNode, PathNode* endNode, bool oneWay, bool addToGraph);
	void generate_sample_graph();
};

