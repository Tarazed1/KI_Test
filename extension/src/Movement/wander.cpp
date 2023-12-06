#include "wander.h"

using namespace godot;

Wander::Wander()
{
}

Wander::~Wander()
{
}

Wander::Wander(Kinematics* inKin) : SteeringBehaviour(inKin)
{
}

SteeringForce Wander::get_force()
{
	SteeringForce aSteeringForce;
	positionOnCircleBorder = Vector3();

	Vector3 positionCenterPoint = angle_to_directionvector(this->kinematics->orientation) * offset;
	float percent = randomGenerator.randf_range(-0.1, 0.1);

	currentAngle += percent * maxAngleChange;
	positionOnCircleBorder = positionCenterPoint + angle_to_directionvector(currentAngle) * radius;

	aSteeringForce.movementForce = positionOnCircleBorder.normalized() * this->kinematics->maxMovementForce;
	return aSteeringForce;
}
