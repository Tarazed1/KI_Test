#include "arrive.h"
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

Arrive::Arrive()
{
	breakRadius = 10.0f;
	breakFactor = 0.25f;
}

Arrive::Arrive(Kinematics* inKin) : SteeringBehaviour(inKin)
{
	breakRadius = 10.0f;
	breakFactor = 0.25f;
}

Arrive::~Arrive() {

}

void Arrive::SetTarget(KnowledgePosition* inNewTarget)
{
	this->target = inNewTarget;
}

SteeringForce Arrive::get_force()
{
	SteeringForce aSteeringForce;
	if (!target) {
		UtilityFunctions::printerr("Your Target is empty. (Location: Arrive get_force()");
		return aSteeringForce;
	}

	Vector3 direction = target->get_position() - this->kinematics->position;

	float forceFactor = 0.0f;
	float distance = direction.length();
	if (distance > breakRadius) {
		forceFactor = this->kinematics->maxMovementForce;
	}
	else {
		forceFactor = this->kinematics->maxMovementForce * distance / breakRadius;
	}

	direction = direction.normalized() * forceFactor;

	aSteeringForce.movementForce = direction - this->kinematics->velocity;
	aSteeringForce.movementForce /= breakFactor;
	aSteeringForce.angularForce = 0.0f;

	return aSteeringForce;
}
