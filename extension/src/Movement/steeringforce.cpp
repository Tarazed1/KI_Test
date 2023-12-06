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

void SteeringForce::operator+=(const SteeringForce& rhs)
{
	this->angularForce = this->angularForce + rhs.angularForce;
	this->movementForce = this->movementForce + rhs.movementForce;
}

SteeringForce SteeringForce::operator*(float rhs)
{
	SteeringForce aSteeringForce;
	aSteeringForce.movementForce = this->movementForce * rhs;
	aSteeringForce.angularForce = this->angularForce * rhs;
	return aSteeringForce;
}

SteeringForce SteeringForce::operator+(SteeringForce& rhs)
{
	return SteeringForce();
}

void SteeringForce::operator=(const SteeringForce& rhs)
{
	this->movementForce = rhs.movementForce;
	this->angularForce = rhs.angularForce;
}
