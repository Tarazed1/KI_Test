#include "kinematics.h"

using namespace godot;

void Kinematics::_bind_methods()
{

}

Kinematics::Kinematics()
{
	position = Vector3();
	orientation = 0.0f;
	velocity = Vector3();
	angularVelocity = 0.0f;

	maxAngularForce = 2.0f;
	maxAngularVelocity = 2.0f;
	maxMovementForce = 15.0f;
	maxMovementVelocity = 15.0f;
}

Kinematics::~Kinematics()
{

}
