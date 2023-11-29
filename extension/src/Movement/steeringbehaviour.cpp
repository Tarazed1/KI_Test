#include "steeringbehaviour.h"
#include <cmath>
#include "../Utility/macros.h"
#include <godot_cpp/variant/utility_functions.hpp>

void SteeringBehaviour::_bind_methods()
{
}

bool SteeringBehaviour::in_fov(Vector3& viewDir, Vector3& targetDir, float fov)
{
    float relativeAngle = Math::acos((viewDir.dot(targetDir) / (viewDir.length() * targetDir.length())));

    if (relativeAngle < 0.5f * fov) {
        return true;
    }
    else {
        return false;
    }
}

Vector3 SteeringBehaviour::limit()
{
    return Vector3();
}

float SteeringBehaviour::directionvector_to_angle(float currentAngle, Vector3 inVec, bool degrees)
{
    if (inVec.length() == 0) return currentAngle;
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

void SteeringBehaviour::update(double time, Vector3 pos)
{
    timer += static_cast<float>(time);
    subTimer += static_cast<float>(time);
    if (timer > 5.0f) {
        UtilityFunctions::print("Debug: ", kinematics->position, kinematics->velocity);
        timer = 0.0f;
    }
    kinematics->position = pos;
    force = get_force();
    kinematics->velocity = force.movementForce * time * 10.0f;
    if (kinematics->velocity.length() > kinematics->maxMovementVelocity) {
        kinematics->velocity = kinematics->velocity.normalized() * kinematics->maxMovementVelocity;
    }
    kinematics->position += kinematics->velocity * time * 10.0f;
}

void SteeringBehaviour::set_facing_mode()
{
}

Kinematics* SteeringBehaviour::get_kinematics()
{
    return kinematics;
}
