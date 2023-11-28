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
	maxMovementForce = 0.4f;
	maxMovementVelocity = 0.4f;
}

Kinematics::~Kinematics()
{

}
