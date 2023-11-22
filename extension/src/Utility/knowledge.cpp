#include "knowledge.h"

Knowledge::Knowledge()
{
	this->knowledgeName = "emptyKnowledge";
}

Knowledge::Knowledge(std::string name)
{
	this->knowledgeName = name;
}

Knowledge::~Knowledge()
{
}
