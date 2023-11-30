#ifndef NPC_CLASS
#define NPC_CLASS

#include "Movement/kinematics.h"
#include "Movement/steeringforce.h"
#include "Movement/steeringbehaviour.h"
#include "Movement/flee.h"
#include "Movement/arrive.h"
#include "Movement/seek.h"
#include "Utility/knowledgekinematicgroup.h"
#include "Movement/flocking.h"
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/classes/geometry_instance3d.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/material.hpp>

using namespace godot;

class NPC : public Node3D {
	GDCLASS(NPC, Node3D);

	Vector3 position;
	MeshInstance3D* model;
	Mesh* mesh;
	MeshInstance3D* nose;
	Mesh* noseMesh;
	Material* material;
	double localTime;
	int currentBehaviour;
	bool changeingBehaviour = false;

	Kinematics* kinematics;
	SteeringBehaviour* steeringBehaviour;
	Flee* fleeBehaviour;
	Seek* seekBehaviour;
	Arrive* arriveBehaviour;
	Flocking* flockingBehaviour;

	void change_behaviour_intern();

protected:
	static void _bind_methods();

public:
	NPC();
	~NPC();
	void _ready() override;
	void _process(double delta) override;
	void change_behaviour(int index);
	void set_color(const Color c);
	void set_target(Vector3 targetPos);
	void set_position_intern(const Vector3 pos);
	Kinematics* get_kinematics();
	void init_flocking(KnowledgeKinematicGroup* group);
	String debug_buddies();
};

#endif // !NPC_CLASS
