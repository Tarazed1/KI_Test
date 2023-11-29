#include "velocitymatching.h"
#include <godot_cpp/variant/utility_functions.hpp>

VelocityMatching::VelocityMatching() : SteeringBehaviour()
{
}

VelocityMatching::VelocityMatching(Kinematics* inKin) : SteeringBehaviour(inKin)
{
}

VelocityMatching::VelocityMatching(Kinematics* inKin, KnowledgeKinematicGroup* group) : SteeringBehaviour(inKin)
{
	buddies = group;
}

VelocityMatching::~VelocityMatching()
{
}

SteeringForce VelocityMatching::get_force()
{
	SteeringForce aSteeringForce;

	if (!buddies) {
		return aSteeringForce;
	}
	if (buddies->get_size() == 0) {
		return aSteeringForce;
	}

	Vector3 averageVelocity = Vector3();
	Kinematics* kinematicBoy = this->kinematics;

	for (size_t i = 0; i < buddies->get_size(); i++) {
		Kinematics* target = buddies->get_kinematic(i);
		if (target == kinematicBoy) {
			continue;
		} 
		if (target) {
			Vector3 dir = target->position - kinematicBoy->position;
			float distance = dir.length();
			if (distance < activationDistance) {
				averageVelocity += target->velocity;
				//UtilityFunctions::print("AAAA", distance, averageVelocity);
			}
		}
	}

	aSteeringForce.movementForce = averageVelocity;
	//UtilityFunctions::print("VM: ", aSteeringForce.movementForce);
	return aSteeringForce;
}
