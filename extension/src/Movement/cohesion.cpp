#include "cohesion.h"
#include <godot_cpp/variant/utility_functions.hpp>

Cohesion::Cohesion(): SteeringBehaviour()
{

}

Cohesion::Cohesion(Kinematics* inKin) : SteeringBehaviour(inKin)
{

}

Cohesion::Cohesion(Kinematics* inKin, KnowledgeKinematicGroup* group) : SteeringBehaviour(inKin)
{
	buddies = group;
}

Cohesion::~Cohesion()
{
	buddies = nullptr;
}

SteeringForce Cohesion::get_force()
{
	subTimer += 0.01f;
	SteeringForce aSteeringForce;
	if (!buddies) return aSteeringForce;
	if (buddies->get_size() == 0) return aSteeringForce;

	Vector3 centerOfMass = Vector3();
	int numberOfRelativBoys = 0;
	Kinematics* kinematicBoy = this->kinematics;

	for (int i = 0; i < buddies->get_size(); i++) {
		Kinematics* target = buddies->get_kinematic(i, false);
		if (target == nullptr) UtilityFunctions::printerr("Target is null. Can't calculate SteeringForce. (Location: Cohesion, get_force())");
		if (target == kinematicBoy) {
			continue;
		}
		if (target) {
			Vector3 dir = kinematicBoy->position - target->position;
			float distance = dir.length();
			if (distance < activationDistance) {
				centerOfMass += target->position;
				numberOfRelativBoys++;
			}
		}
	}
	if (numberOfRelativBoys > 0) {
		centerOfMass /= numberOfRelativBoys;
		Vector3 dir = centerOfMass - kinematicBoy->position;
		float force = this->kinematics->maxMovementForce * dir.length() / activationDistance;
		dir = dir.normalized() * force;
		aSteeringForce.movementForce = dir;
	}

	return aSteeringForce;
}
