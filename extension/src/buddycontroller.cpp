#include "buddycontroller.h"

void BuddyController::_bind_methods()
{
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

KnowledgeKinematicGroup* BuddyController::get_knowledge()
{
	return group;
}

void BuddyController::set_knowledge(KnowledgeKinematicGroup* inGroup)
{
	if (!group) group = inGroup;
}
