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

void Flee::set_force() {
	if (!target) return;

	force.movementForce = this->kinematics->position - target->get_position();
	force.movementForce = force.movementForce.normalized() * this->kinematics->maxMovementForce;
	force.angularForce = 0;
}

SteeringForce Flee::get_force()
{
	SteeringForce aSteeringForce;
	if (!target) return aSteeringForce;

	aSteeringForce.movementForce = this->kinematics->position - target->get_position();
	aSteeringForce.movementForce = aSteeringForce.movementForce.normalized() * this->kinematics->maxMovementForce;
	aSteeringForce.angularForce = 0;

	return aSteeringForce;
}

void Flee::SetTarget(KnowledgePosition* inNewTarget)
{
	this->target = inNewTarget;
}