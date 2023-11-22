#include "steeringforce.h"

using namespace godot;

SteeringForce::SteeringForce(Vector3 movementForce, float angularForce)
{
	this->movementForce = movementForce;
	this->angularForce = angularForce;
}

SteeringForce::SteeringForce()
{
	this->movementForce = Vector3(0,0,0);
	this->angularForce = 0.0f;
}

SteeringForce SteeringForce::operator+=(const SteeringForce& rhs)
{
	return SteeringForce();
}

SteeringForce SteeringForce::operator*(float rhs)
{
	return SteeringForce();
}

SteeringForce SteeringForce::operator+(SteeringForce& rhs)
{
	return SteeringForce();
}

SteeringForce SteeringForce::operator=(const SteeringForce& rhs)
{
	SteeringForce aSteeringForce;
	aSteeringForce.angularForce = rhs.angularForce;
	aSteeringForce.movementForce = rhs.movementForce;
	return aSteeringForce;
}
