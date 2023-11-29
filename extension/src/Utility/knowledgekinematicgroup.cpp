#include "knowledgekinematicgroup.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <sstream>
#include <string>

void KnowledgeKinematicGroup::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("get_kinematic", "index"), &KnowledgeKinematicGroup::get_kinematic);
	ClassDB::bind_method(D_METHOD("get_size"), &KnowledgeKinematicGroup::get_size);
	ClassDB::bind_method(D_METHOD("subscribe", "inKin"), &KnowledgeKinematicGroup::subscribe);
	ClassDB::bind_method(D_METHOD("unsubscribe", "outKin"), &KnowledgeKinematicGroup::unsubscribe);
}

KnowledgeKinematicGroup::KnowledgeKinematicGroup()
{
}

KnowledgeKinematicGroup::~KnowledgeKinematicGroup()
{

}

Kinematics* KnowledgeKinematicGroup::get_kinematic(int index) const
{
	if (index >= kinematics.size()) {
		return nullptr;
	}
	else return kinematics[index];
}

int KnowledgeKinematicGroup::get_size() const
{
	return kinematics.size();
}

void KnowledgeKinematicGroup::subscribe(Kinematics* inKin)
{
	kinematics.push_back(inKin);
}

void KnowledgeKinematicGroup::unsubscribe(Kinematics* outKin)
{
	kinematics.erase(outKin);
}
