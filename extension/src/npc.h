#ifndef NPC_CLASS
#define NPC_CLASS

#include "Movement/kinematics.h"
#include "Movement/steeringforce.h"
#include "Movement/steeringbehaviour.h"
#include "Movement/flee.h"
#include "Movement/arrive.h"
#include "Movement/seek.h"
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

	Kinematics* kinematics;
	SteeringBehaviour* steeringBehaviour;
	Flee* fleeBehaviour;
	Seek* seekBehaviour;
	Arrive* arriveBehaviour;

protected:
	static void _bind_methods();

public:
	NPC();
	~NPC();
	void _ready() override;
	void _process(double delta) override;
	void set_position(const Vector3 pos);
	void change_behaviour(int index);
	Vector3 get_position() const;
	void set_color(const Color c);
	void set_target(Vector3 targetPos);
};

#endif // !NPC_CLASS
