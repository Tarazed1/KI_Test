#ifndef PATHGRAPPLINGHOOK_CLASS
#define PATHGRAPPLINGHOOK_CLASS

#include <godot_cpp/variant/vector3.hpp>
#include "steeringbehaviour.h"

using namespace godot;

class Pathgrapplinghook : public SteeringBehaviour {
private:
	const float activationDistance = 2.0f;
protected:
public:
	Pathgrapplinghook();
	Pathgrapplinghook(Kinematics* inKin);
	~Pathgrapplinghook();

	SteeringForce get_force() override;
	List<Vector3> path;
	Vector3 target;
	int indexCurrentTarget;
	bool loop = true;
};

#endif // !SEPARATION_CLASS
