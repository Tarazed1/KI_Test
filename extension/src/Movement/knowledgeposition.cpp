#include "knowledgeposition.h"

KnowledgePosition::KnowledgePosition()
{
	this->position = Vector3(0, 0, 0);
}

KnowledgePosition::KnowledgePosition(std::string name, Vector3 pos)
{
	this->knowledgeName = name;
	this->position = pos;
}

KnowledgePosition::~KnowledgePosition()
{
}

Vector3 KnowledgePosition::get_position()
{
	return position;
}

void KnowledgePosition::set_position(Vector3 pos)
{
	this->position = pos;
}
