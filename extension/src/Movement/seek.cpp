#include "seek.h"

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
}

SteeringForce Seek::get_force()
{
	SteeringForce aSteeringForce;
	if (!target) return aSteeringForce;

	aSteeringForce.movementForce = this->kinematics->position - target->get_position();
	aSteeringForce.movementForce = aSteeringForce.movementForce.normalized() * this->kinematics->maxMovementForce;
	aSteeringForce.angularForce = 0;

	return aSteeringForce;
}
