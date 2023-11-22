#include "steeringbehaviour.h"
#include <cmath>
#include "../Utility/macros.h"

bool SteeringBehaviour::in_fov()
{
    return false;
}

Vector3 SteeringBehaviour::limit()
{
    return Vector3();
}

float SteeringBehaviour::directionvector_to_angle(Vector3 inVec, bool degrees)
{
    if (degrees) {
        return Math::atan2(inVec.z, inVec.x);
    }
    else {
        return Math::atan2(inVec.z, inVec.x) * 180.0f / PI;
    }
}

Vector3 SteeringBehaviour::angle_to_directionvector(float inAngle)
{
    float angleInRadians = DEGREES_TO_RADIANS(inAngle);
    return Vector3((float)Math::cos(angleInRadians), 0, (float)Math::sin(angleInRadians));
}

SteeringBehaviour::SteeringBehaviour()
{
    force = SteeringForce();
    standartForce = Vector3();
    kinematics = new Kinematics();
}

SteeringBehaviour::SteeringBehaviour(Kinematics* inKin)
{
    force = SteeringForce();
    standartForce = Vector3();
    kinematics = inKin;
}

SteeringBehaviour::~SteeringBehaviour()
{
}

SteeringForce SteeringBehaviour::get_force()
{
    return SteeringForce();
}

void SteeringBehaviour::set_standart_force()
{
}

void SteeringBehaviour::update(double time)
{
    force = get_force();
    kinematics->velocity += force.movementForce * time;
    if (kinematics->velocity.length() > kinematics->maxMovementVelocity) {
        kinematics->velocity = kinematics->velocity.normalized() * kinematics->maxMovementVelocity;
    }
    kinematics->position += kinematics->velocity * time;
}

void SteeringBehaviour::set_facing_mode()
{
}

Kinematics* SteeringBehaviour::get_kinematics()
{
    return kinematics;
}
