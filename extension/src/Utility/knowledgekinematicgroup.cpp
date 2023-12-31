#include "knowledgekinematicgroup.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <sstream>
#include <string>

void KnowledgeKinematicGroup::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("get_kinematic", "index", "debug"), &KnowledgeKinematicGroup::get_kinematic);
	ClassDB::bind_method(D_METHOD("get_size"), &KnowledgeKinematicGroup::get_size);
	ClassDB::bind_method(D_METHOD("subscribe", "inKin"), &KnowledgeKinematicGroup::subscribe);
	ClassDB::bind_method(D_METHOD("unsubscribe", "outKin"), &KnowledgeKinematicGroup::unsubscribe);
	ClassDB::bind_method(D_METHOD("debug"), &KnowledgeKinematicGroup::debug);
}

KnowledgeKinematicGroup::KnowledgeKinematicGroup()
{

}

KnowledgeKinematicGroup::~KnowledgeKinematicGroup()
{

}

Kinematics* KnowledgeKinematicGroup::get_kinematic(int index, bool debug)
{
	if (index >= kinematics.size()) {
		UtilityFunctions::printerr("Index out of bounds. (Location: KnowledgeKinemticGroup get_kinematic())");
		return nullptr;
	}
	else {
		if (kinematics[index] == nullptr) {
			UtilityFunctions::printerr("Kinematic is empty");
			return nullptr;
		}
		return kinematics[index];
	}
}

int KnowledgeKinematicGroup::get_size()
{
	return kinematics.size();
}

void KnowledgeKinematicGroup::subscribe(Kinematics* inKin)
{
	if (inKin == nullptr) {
		UtilityFunctions::printerr("Kinematics is null. (Location: KnowledgeKinemticGroup subscribe())");
		return;
	}
	kinematics.push_back(inKin);
}

void KnowledgeKinematicGroup::unsubscribe(Kinematics* outKin)
{
	kinematics.erase(outKin);
}

void KnowledgeKinematicGroup::debug()
{
	Kinematics* kin;
	for (int i = 0; i < get_size(); i++)
	{
		kin = get_kinematic(i, true);
		UtilityFunctions::print("KKG debug: ", kin->position, kin->velocity);
	}
}
