#include "wander.h"

using namespace godot;

Wander::Wander()
{
}

Wander::~Wander()
{
}

SteeringForce Wander::get_force()
{
	SteeringForce aSteeringForce;
	positionOnCircleBorder = Vector3();

	Vector3 positionCenterPoint = angle_to_directionvector(this->kinematics->orientation) * offset;
	float percent = randomGenerator.get_random_float(true, -1, 1);

	currentAngle += percent * maxAngleChange;
	positionOnCircleBorder = positionCenterPoint + angle_to_directionvector(currentAngle) * radius;

	aSteeringForce.movementForce = positionOnCircleBorder.normalized() * this->kinematics->maxMovementForce;
	return aSteeringForce;
}
