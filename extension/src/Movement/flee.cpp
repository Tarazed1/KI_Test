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
	SteeringForce aSteeringForce;
	if (!target) {
		UtilityFunctions::printerr("Your Target is empty. (Location: Arrive get_force()");
		return aSteeringForce;
	}
	aSteeringForce.movementForce = this->kinematics->position - target->get_position();
	aSteeringForce.movementForce = aSteeringForce.movementForce.normalized() * this->kinematics->maxMovementForce;
	aSteeringForce.angularForce = 0;

	return aSteeringForce;
}

void Flee::set_target(KnowledgePosition* inNewTarget)
{
	this->target = inNewTarget;
}