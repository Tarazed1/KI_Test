#ifndef SEPARATION_CLASS
#define SEPARATION_CLASS

#include <godot_cpp/variant/vector3.hpp>
#include "steeringbehaviour.h"

using namespace godot;

class Separation : public SteeringBehaviour {
private:
	KnowledgeKinematicGroup* buddies;
	const float activationDistance = 5.0f;
protected:
public:
	Separation();
	Separation(Kinematics* inKin);
	Separation(Kinematics* inKin, KnowledgeKinematicGroup* group);
	~Separation();

	SteeringForce get_force() override;
};

#endif // !SEPARATION_CLASS
