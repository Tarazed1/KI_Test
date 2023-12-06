#pragma once
#include <list>
#include <directxmath.h>
#include <string>

using namespace std;
using namespace DirectX;

class PathNode
{
protected:
	string name;
	XMFLOAT3 nodePosition;
	list<PathNode*> neighbourNodes;

public:
	PathNode();
	PathNode(string name, XMFLOAT3 pos);
	PathNode(string name, XMFLOAT3 pos, list<PathNode*> startNodes);
	~PathNode();

	void add_node(PathNode* inNode);
	void remove_node(PathNode* outNode);
	bool is_neighbour(PathNode* nodeToCheck);
	XMFLOAT3 get_position();
};

