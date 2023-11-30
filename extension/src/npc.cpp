#include "npc.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/sphere_mesh.hpp>
#include "Movement/flee.h"
#include "Movement/knowledgeposition.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include "Utility/knowledgekinematicgroup.h"
#include <godot_cpp/classes/engine.hpp>

NPC::NPC() {
	position = Vector3(1.0, 0.0, 1.0);
	localTime = 0.0;

	//Draw Model
	this->model = new MeshInstance3D();
	this->mesh = new SphereMesh();
	model->set_mesh(mesh);
	this->nose = new MeshInstance3D();
	this->noseMesh = new SphereMesh();
	nose->scale_object_local(Vector3(0.4, 0.4, 0.4));
	nose->translate(Vector3(0, 0.2, 1.3));
	nose->set_mesh(noseMesh);
	material = new Material();
	model->set_material_override(material);
	//--------------

	kinematics = new Kinematics();
	kinematics->position = this->position;
	fleeBehaviour = new Flee(this->kinematics);
	seekBehaviour = new Seek(this->kinematics);
	arriveBehaviour = new Arrive(this->kinematics);
	steeringBehaviour = fleeBehaviour;
}

NPC::~NPC() {
	UtilityFunctions::print("i dont feel so good");
}

void NPC::_ready() {
	this->add_child(model);
	this->model->add_child(nose);
} 


void NPC::_process(double delta) {
	if (Engine::get_singleton()->is_editor_hint()) return;
	if (changeingBehaviour) change_behaviour_intern();
	steeringBehaviour->update(delta, position);
	if(this->kinematics->velocity != Vector3(0,0,0)) look_at(this->kinematics->velocity);
	this->set_position(steeringBehaviour->get_kinematics()->position);
}



void NPC::change_behaviour_intern()
{
	switch (currentBehaviour) {
	case 1:
		if (seekBehaviour) {
			steeringBehaviour = seekBehaviour;
			break;
		}
		else currentBehaviour++;
	case 2:
		if (arriveBehaviour) {
			steeringBehaviour = arriveBehaviour;
			break;
		}
		else currentBehaviour++;
	case 3:
		if (flockingBehaviour) {
			steeringBehaviour = flockingBehaviour;
			break;
		}
		else {
			currentBehaviour = 0;
		}
	default:
		steeringBehaviour = fleeBehaviour;
		break;
	}
	changeingBehaviour = false;
}

void NPC::change_behaviour(int index)
{
	currentBehaviour = index;
	changeingBehaviour = true;
}

void NPC::set_color(const Color c)
{
	material->set("Color", c);
}

void NPC::set_target(Vector3 targetPos)
{
	KnowledgePosition* kp = new KnowledgePosition("targetName", targetPos);
	fleeBehaviour->set_target(kp);
	seekBehaviour->SetTarget(kp);
	arriveBehaviour->SetTarget(kp);
}

void NPC::set_position_intern(const Vector3 pos)
{
	this->kinematics->position = pos;
}

Kinematics* NPC::get_kinematics()
{
	return this->kinematics;
}

void NPC::init_flocking(KnowledgeKinematicGroup* group)
{
	flockingBehaviour = new Flocking(this->kinematics, group);
}

String NPC::debug_buddies()
{
	if (flockingBehaviour) {
		KnowledgeKinematicGroup* buddies = flockingBehaviour->get_buddies();
		if (buddies == nullptr) {
			return "Buddies are empty (Location: NPC debug_buddies.)";
		}
		godot::String in = buddies->get_kinematic(0, false)->velocity;
		in += "  ";
		in += buddies->get_kinematic(0, false)->position;

		return in;
	}
	return "aa";
}

void NPC::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_position_intern", "pos"), &NPC::set_position_intern);
	ClassDB::bind_method(D_METHOD("set_color", "c"), &NPC::set_color);
	ClassDB::bind_method(D_METHOD("set_target", "targetPos"), &NPC::set_target);
	ClassDB::bind_method(D_METHOD("change_behaviour", "index"), &NPC::change_behaviour);
	ClassDB::bind_method(D_METHOD("get_kinematics"), &NPC::get_kinematics);
	ClassDB::bind_method(D_METHOD("init_flocking", "group"), &NPC::init_flocking);
	ClassDB::bind_method(D_METHOD("debug_buddies"), &NPC::debug_buddies);
}