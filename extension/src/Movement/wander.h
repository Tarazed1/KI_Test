#ifndef WANDER_CLASS
#define WANDER_CLASS

#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>
#include "steeringbehaviour.h"
#include "../random.h"
#include "../Utility/macros.h"

using namespace godot;

class Wander : public SteeringBehaviour {
private:
	float currentAngle = 0.0f;
	//faceMode = afaceMode;
	float offset = 10.0f;
	float radius = 5.0f;
	float maxAngleChange = DEGREES_TO_RADIANS(10);
	Vector3 positionOnCircleBorder;
	RandomNumberGenerator randomGenerator;

protected:

public:
	Wander();
	Wander(Kinematics* inKin);
	~Wander();

	SteeringForce get_force() override;
};

#endif // !WANDER_CLASS
