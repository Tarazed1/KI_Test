#ifndef KINEMATICS_CLASS
#define KINEMATICS_CLASS

#include "knowledgeposition.h"
#include <godot_cpp/variant/vector3.hpp>

using namespace godot;

class Kinematics : public Object {
	GDCLASS(Kinematics, Object);
protected:
	static void _bind_methods();
public:
	Kinematics();
	~Kinematics();

	Vector3 position;
	float orientation;
	Vector3 velocity;
	float angularVelocity;

	float maxMovementForce;
	float maxMovementVelocity;

	float maxAngularForce;
	float maxAngularVelocity;
};

#endif // !KINEMATICS_CLASS