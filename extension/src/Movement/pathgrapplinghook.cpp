#include "pathgrapplinghook.h"

Pathgrapplinghook::Pathgrapplinghook()
{
	path.push_back(Vector3(0, 0, 0));
	path.push_back(Vector3(8, 0, 8));
	path.push_back(Vector3(8, 0, 16));
	path.push_back(Vector3(0, 0, 24));
	path.push_back(Vector3(-8, 0, 24));
	path.push_back(Vector3(-16, 0, 16));
	path.push_back(Vector3(-16, 0, 16));
	path.push_back(Vector3(-8, 0, 0));
}

Pathgrapplinghook::Pathgrapplinghook(Kinematics* inKin)
{
	path.push_back(Vector3(0, 0, 0));
	path.push_back(Vector3(8, 0, 8));
	path.push_back(Vector3(8, 0, 16));
	path.push_back(Vector3(0, 0, 24));
	path.push_back(Vector3(-8, 0, 24));
	path.push_back(Vector3(-16, 0, 16));
	path.push_back(Vector3(-16, 0, 16));
	path.push_back(Vector3(-8, 0, 0));
}

Pathgrapplinghook::~Pathgrapplinghook()
{
}

SteeringForce Pathgrapplinghook::get_force()
{
	SteeringForce aSteeringForce;

	if (path.is_empty()) return aSteeringForce;

	float distanceToCurrentTarget = (kinematics->position - target).length();

	if (distanceToCurrentTarget < activationDistance)
	{
		if (indexCurrentTarget < path.size() - 1)
		{
			indexCurrentTarget++;
		}
		else
		{
			if (loop)
			{
				indexCurrentTarget = 0;
			}
		}
	}

	target = path[indexCurrentTarget];
	aSteeringForce.movementForce = target - kinematics->position;
	aSteeringForce.movementForce = aSteeringForce.movementForce.normalized() * kinematics->maxMovementForce;

	return aSteeringForce;
}
