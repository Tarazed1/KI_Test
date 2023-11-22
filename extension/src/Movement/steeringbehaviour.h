#ifndef STEERINGBEHAVIOUR_CLASS
#define STEERINGBEHAVIOUR_CLASS

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include "steeringforce.h"
#include "knowledgeposition.h"
#include "kinematics.h"

using namespace godot;

class SteeringBehaviour {
private:

protected:
	//FaceingMode faceMode;
	//KnowledgeCollisionVector knowledgeCollisionWithFloor

	SteeringForce force;
	Kinematics* kinematics;
	Vector3 standartForce;

	virtual bool in_fov();
	virtual Vector3 limit();
	virtual float directionvector_to_angle(Vector3 inVec, bool degrees);
	virtual Vector3 angle_to_directionvector(float inAngle);
public:
	SteeringBehaviour();
	SteeringBehaviour(Kinematics* inKin);
	~SteeringBehaviour();

	void update(double time);

	virtual SteeringForce get_force();
	virtual void set_standart_force();
	virtual void set_facing_mode();
	Kinematics* get_kinematics();
};

#endif