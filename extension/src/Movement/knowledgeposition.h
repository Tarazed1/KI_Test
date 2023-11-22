#ifndef KNOWLEDGEPOSITIONPTR_CLASS
#define KNOWLEDGEPOSITIONPTR_CLASS


#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include "steeringforce.h"
#include "../Utility/knowledge.h"

using namespace godot;

class KnowledgePosition : Knowledge {
private:
	Vector3 position;
public:
	KnowledgePosition();
	KnowledgePosition(std::string name, Vector3 pos);
	~KnowledgePosition();

	Vector3 get_position();
	void set_position(Vector3 pos);
};
#endif