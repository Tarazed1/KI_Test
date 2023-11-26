#include "npc.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/sphere_mesh.hpp>
#include "Movement/flee.h"
#include "Movement/knowledgeposition.h"
#include <godot_cpp/variant/utility_functions.hpp>

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
	nose->translate(Vector3(-1.8, 0.2, 0.0));
	nose->set_mesh(noseMesh);
	material = new Material();
	model->set_material_override(material);
	//--------------

	kinematics = new Kinematics();
	kinematics->position = this->position;
	fleeBehaviour = new Flee(kinematics);
	seekBehaviour = new Seek(kinematics);
	arriveBehaviour = new Arrive(kinematics);
	steeringBehaviour = fleeBehaviour;
}

NPC::~NPC() {

}

void NPC::_ready() {
	this->add_child(model);
	this->model->add_child(nose);
	//set_position(position);
}

void NPC::_process(double delta) {
	localTime += 0.1 * delta;
	steeringBehaviour->update(delta);
	this->set_position(steeringBehaviour->get_kinematics()->velocity);
}

void NPC::set_position(const Vector3 pos) {
	this->translate(pos);
	this->position = pos;
	kinematics->position = position;
}

void NPC::change_behaviour(int index)
{
	switch (index) {
	case 1:
		steeringBehaviour = seekBehaviour;
		break;
	case 2:
		steeringBehaviour = arriveBehaviour;
		break;
	default:
		steeringBehaviour = fleeBehaviour;
		break;
	}
}

Vector3 NPC::get_position() const {
	return position;
}

void NPC::set_color(const Color c)
{
	material->set("Color", c);
}

void NPC::set_target(Vector3 targetPos)
{
	KnowledgePosition* kp = new KnowledgePosition("targetName", targetPos);
	fleeBehaviour->SetTarget(kp);
	seekBehaviour->SetTarget(kp);
	arriveBehaviour->SetTarget(kp);
}

void NPC::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_position", "pos"), &NPC::set_position);
	ClassDB::bind_method(D_METHOD("get_position"), &NPC::get_position);
	ClassDB::bind_method(D_METHOD("set_color", "c"), &NPC::set_color);
	ClassDB::bind_method(D_METHOD("set_target", "targetPos"), &NPC::set_target);
	ClassDB::bind_method(D_METHOD("change_behaviour", "index"), &NPC::change_behaviour);
}