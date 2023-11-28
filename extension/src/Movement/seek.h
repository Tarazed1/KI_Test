#ifndef SEEK_CLASS
#define SEEK_CLASS

#include "steeringbehaviour.h"
#include "knowledgeposition.h"

class Seek : public SteeringBehaviour {
private:

protected:
	KnowledgePosition* target;

public:
	Seek();
	Seek(Kinematics& inKin);
	~Seek();

	void SetTarget(KnowledgePosition* inNewTarget);
	SteeringForce get_force() override;
};

#endif	