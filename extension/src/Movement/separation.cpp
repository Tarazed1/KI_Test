#include "separation.h"
#include "../Utility/macros.h"
#include <godot_cpp/variant/utility_functions.hpp>

Separation::Separation()
{
}

Separation::Separation(Kinematics* inKin)
{
}

Separation::Separation(Kinematics* inKin, KnowledgeKinematicGroup* group) : SteeringBehaviour(inKin)
{
	buddies = group;
}

Separation::~Separation()
{
}

SteeringForce Separation::get_force()
{
	SteeringForce aSteeringForce;

	if (!buddies) return aSteeringForce;
	if (buddies->get_size() == 0) return aSteeringForce;

	float fov = DEGREES_TO_RADIANS(360);

	for (size_t i = 0; i < buddies->get_size(); i++) {
		Kinematics* target = buddies->get_kinematic(i); 
		if (target == this->kinematics) continue;
		
		if (target) {
			Vector3 dirNPCToTarget = target->position - this->kinematics->position;
			Vector3 dirTargetToNPC = this->kinematics->position - target->position;
			float distance = dirTargetToNPC.length();
			if (distance < activationDistance && this->in_fov(this->kinematics->velocity, dirNPCToTarget, fov)) {
				float force = this->kinematics->maxMovementForce * (activationDistance - distance) / activationDistance;
				aSteeringForce.movementForce += dirTargetToNPC.normalized() * force;
			}
		}
	}
	//UtilityFunctions::print("Separation: ", aSteeringForce.movementForce);
	return aSteeringForce;
}
