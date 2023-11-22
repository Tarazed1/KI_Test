#ifndef ARRIVE_CLASS
#define ARRIVE_CLASS

#include "steeringbehaviour.h"
#include "knowledgeposition.h"

using namespace godot;
class Arrive : public SteeringBehaviour {
private:
	KnowledgePosition* target;
	float breakRadius;
	float breakFactor;
public:
	Arrive();
	Arrive(Kinematics* inKin);
	~Arrive();

	void SetTarget(KnowledgePosition* inNewTarget);
	SteeringForce get_force() override;
};

#endif