#include "seek.h"
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

Seek::Seek()
{
}

Seek::Seek(Kinematics* inKin) : SteeringBehaviour(inKin)
{
}

Seek::~Seek()
{
}

void Seek::SetTarget(KnowledgePosition* inNewTarget)
{
	target = inNewTarget;
}

void Seek::set_force() {
	if (!target) return;

	force.movementForce = target->get_position() - this->kinematics->position;
	force.movementForce = force.movementForce.normalized() * this->kinematics->maxMovementForce;
	force.angularForce = 0;
}

SteeringForce Seek::get_force()
{
	SteeringForce aSteeringForce;
	if (!target) return aSteeringForce;

	aSteeringForce.movementForce = target->get_position() - this->kinematics->position;
	aSteeringForce.movementForce = aSteeringForce.movementForce.normalized() * this->kinematics->maxMovementForce;
	aSteeringForce.angularForce = 0;

	return aSteeringForce;
}
