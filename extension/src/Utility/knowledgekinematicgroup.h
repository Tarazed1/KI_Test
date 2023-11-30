#ifndef KNOWLEDGEKINEMATICGROUP_CLASS
#define KNOWLEDGEKINEMATICGROUP_CLASS

#include "knowledge.h"
#include "../Movement/kinematics.h"
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/classes/node3d.hpp>

using namespace godot;

class KnowledgeKinematicGroup : public Knowledge, public Node3D {
private:
	GDCLASS(KnowledgeKinematicGroup, Node3D);
	
	List<Kinematics*> kinematics;
	int size;
protected:
	static void _bind_methods();
public:
	KnowledgeKinematicGroup();
	~KnowledgeKinematicGroup();
	Kinematics* get_kinematic(int index, bool debug); 
	int get_size();
	void subscribe(Kinematics* inKin);
	void unsubscribe(Kinematics* outKin);
	void debug();
};

#endif // !KNOWLEDGEKINEMATICGROUP_CLASS
