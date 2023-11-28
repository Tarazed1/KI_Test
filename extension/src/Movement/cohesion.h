#ifndef COHESION_CLASS
#define COHESION_CLASS

#include "steeringbehaviour.h"

using namespace godot;

class Cohesion : public SteeringBehaviour {
	KnowledgeKinematicGroup* buddies;
	const float activationDistance = 7.0f;
public:
	Cohesion();
	Cohesion(Kinematics& inKin);
	Cohesion(Kinematics& inKin, KnowledgeKinematicGroup& group);
	~Cohesion();

	SteeringForce get_force() override;
};

#endif // !COHESION_CLASS
