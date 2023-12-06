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

/// <summary>
/// Initializes the buddy group for Flocking
/// </summary>
void BuddyController::init_group()
{
	//RNG for the position - changeable for own random?
	RandomNumberGenerator rng = RandomNumberGenerator();

	//iterate throuh all direct children to get your buddies
	for (int i = 0; i < get_child_count(false); i++) {
		//try to cast child into NPC*
		NPC* n = dynamic_cast<NPC*>(get_child(i));
		//if child is a npc push it into the nps-list, set its position random and initialize the flocking behaviour
		if (n) {
			npcs.push_back(n);
			n->set_position_intern(Vector3(rng.randf_range(-20, 20), 0, rng.randf_range(-30, 30)));
			group->subscribe(n->get_kinematics());
			n->init_flocking(group);
			n->change_behaviour(3);
		}
		else {
			UtilityFunctions::printerr("Found a child that is not a NPC class. (Location: BuddyController, init_group())");
		}
	}

	//take one NPC and give it a other beaviour, so that the others can work correctly
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
