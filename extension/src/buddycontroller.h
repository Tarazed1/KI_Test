#ifndef BUDDYCONTROLLER_CLASS
#define BUDDYCONTROLLER_CLASS

#include <godot_cpp/classes/ref.hpp>
#include "Movement/kinematics.h"
#include "Utility/knowledgekinematicgroup.h"

using namespace godot;

class BuddyController : public RefCounted {
private :
	GDCLASS(BuddyController, RefCounted);
 	KnowledgeKinematicGroup* group;
protected:
	static void _bind_methods();
public:
	BuddyController();
	~BuddyController();

	KnowledgeKinematicGroup* get_knowledge();
	void set_knowledge(KnowledgeKinematicGroup* inGroup);
};

#endif // !BUDDYCONTROLLER_CLASS
