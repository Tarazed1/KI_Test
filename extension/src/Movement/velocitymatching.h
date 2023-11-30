#ifndef VELOCITYMATCHING_CLASS
#define VELOCITYMATCHING_CLASS

#include <godot_cpp/variant/vector3.hpp>
#include "Movement/steeringbehaviour.h"

using namespace godot;

class VelocityMatching : public SteeringBehaviour {
private:
	KnowledgeKinematicGroup* buddies;
	const float activationDistance = 12.0f;
protected:
public:
	VelocityMatching();
	VelocityMatching(Kinematics* inKin);
	VelocityMatching(Kinematics* inKin, KnowledgeKinematicGroup* group);
	~VelocityMatching();

	SteeringForce get_force() override;
};

#endif // !VELOCITYMATCHING_CLASS
