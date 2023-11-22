#ifndef KNOWLEDGE_CLASS
#define KNOWLEDGE_CLASS

#include <string>

class Knowledge abstract {
protected:
	std::string knowledgeName;

public:
	Knowledge();
	Knowledge(std::string name);
	~Knowledge();
};

#endif // !KNOWLEDGE_CLASS
