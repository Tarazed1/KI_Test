#ifndef FLEE_CLASS
#define FLEE_CLASS

#include "steeringbehaviour.h"

using namespace godot;
class Flee : public SteeringBehaviour {
private:
	KnowledgePosition* target;

public:
	Flee();
	Flee(Kinematics* inKin);
	~Flee();

	SteeringForce get_force() override;
	void set_target(KnowledgePosition* inNewTarget);
};

#endif