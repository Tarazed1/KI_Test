#include "flee.h"
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

Flee::Flee() {

}

Flee::Flee(Kinematics* inKin) : SteeringBehaviour(inKin)
{
}

Flee::~Flee() {

}

SteeringForce Flee::get_force()
{
	UtilityFunctions::print("Getting Force");
	SteeringForce aSteeringForce;
	if (!target) return aSteeringForce;

	aSteeringForce.movementForce = this->kinematics->position - target->get_position();
	aSteeringForce.movementForce = aSteeringForce.movementForce.normalized() * this->kinematics->maxMovementForce;
	aSteeringForce.angularForce = 0;
	UtilityFunctions::print(aSteeringForce.movementForce);

	return aSteeringForce;
}

void Flee::SetTarget(KnowledgePosition* inNewTarget)
{
	this->target = inNewTarget;
}