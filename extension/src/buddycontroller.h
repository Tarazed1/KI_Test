#ifndef BUDDYCONTROLLER_CLASS
#define BUDDYCONTROLLER_CLASS

#include <godot_cpp/classes/node3d.hpp>
#include "npc.h"
#include "Movement/kinematics.h"
#include "Utility/knowledgekinematicgroup.h"

using namespace godot;

class BuddyController : public Node3D {
private :
	GDCLASS(BuddyController, Node3D);
 	KnowledgeKinematicGroup* group;
	int numberOfNPCs;
	List<NPC*> npcs;
protected:
	static void _bind_methods();
public:
	BuddyController();
	~BuddyController();

	void init_group();
	void set_npcs_count(int count);
	int get_npcs_count();
	KnowledgeKinematicGroup* get_knowledge();
	void set_knowledge(KnowledgeKinematicGroup* inGroup);
};

#endif // !BUDDYCONTROLLER_CLASS
