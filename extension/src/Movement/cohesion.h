#ifndef COHESION_CLASS
#define COHESION_CLASS

#include "steeringbehaviour.h"

using namespace godot;

class Cohesion : public SteeringBehaviour {
private:
	float subTimer = 0.0f;
	KnowledgeKinematicGroup* buddies;
	const float activationDistance = 14.0f;
public:
	Cohesion();
	Cohesion(Kinematics* inKin);
	Cohesion(Kinematics* inKin, KnowledgeKinematicGroup* group);
	~Cohesion();

	SteeringForce get_force() override;
};

#endif // !COHESION_CLASS
