#include "buddycontroller.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>
#include "random.h"

void BuddyController::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("init_group"), &BuddyController::init_group);
	ClassDB::bind_method(D_METHOD("set_npcs_count", "count"), &BuddyController::set_npcs_count);
	ClassDB::bind_method(D_METHOD("get_npcs_count"), &BuddyController::get_npcs_count);
	ClassDB::add_property("BuddyController", PropertyInfo(Variant::INT, "numberOfNPCs", PROPERTY_HINT_RANGE, "1,50,1"), "set_npcs_count", "get_npcs_count");
}

BuddyController::BuddyController()
{
	group = new KnowledgeKinematicGroup();
}

BuddyController::~BuddyController()
{
	delete(group);
	group = nullptr;
}

void BuddyController::_ready()
{
	//for (int i = 0; i < numberOfNPCs; i++) {
	//	NPC* n = new NPC();
	//	npcs.push_back(n);
	//	if (n == nullptr) UtilityFunctions::print("its a me malario");
	//	this->add_child(n);
	//	n->set_position_intern(Vector3(5, 0, 5));
	//	n->init_flocking(group);
	//	n->change_behaviour(3);
	//}
	//for (int i = 0; i < numberOfNPCs; i++) {
	//	group->subscribe(npcs[i]->get_kinematics());
	//}
}

void BuddyController::init_group()
{
	RandomNumberGenerator rng = RandomNumberGenerator();
	for (int i = 0; i < get_child_count(false); i++) {
		NPC* n = dynamic_cast<NPC*>(get_child(i));
		npcs.push_back(n);
		n->set_position_intern(Vector3(rng.randf_range(-5, 5), 0, rng.randf_range(-5, 5)));
		group->subscribe(n->get_kinematics());
		n->init_flocking(group);
		n->change_behaviour(3);
	}
	dynamic_cast<NPC*>(get_child(3))->change_behaviour(0);
	dynamic_cast<NPC*>(get_child(3))->set_target(Vector3(10, 0, 10));
}

void BuddyController::set_npcs_count(int count)
{
	numberOfNPCs = count;
}

int BuddyController::get_npcs_count()
{
	return numberOfNPCs;
}

KnowledgeKinematicGroup* BuddyController::get_knowledge()
{
	return group;
}

void BuddyController::set_knowledge(KnowledgeKinematicGroup* inGroup)
{
	if (!group) group = inGroup;
}
