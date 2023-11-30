#ifndef FLOCKING_CLASS
#define FLOCKING_CLASS

#include <godot_cpp/variant/vector3.hpp>
#include "Movement/steeringbehaviour.h"
#include "../Utility/knowledgekinematicgroup.h"
#include "cohesion.h"
#include "separation.h"
#include "Movement/velocitymatching.h"

using namespace godot;

class Flocking : public SteeringBehaviour {
private:
 	const float cohesionWeight = 1.0f;
    const float separationWeight = 1.0f;
    const float velocityMatchingWeight = 1.0f;

    KnowledgeKinematicGroup* buddies;

    Cohesion* cohesion;
    Separation* separation;
    VelocityMatching* velocityMatching;
protected:
public:
    Flocking();
    Flocking(Kinematics* inKin);
    Flocking(Kinematics* inKin, KnowledgeKinematicGroup* group);
    ~Flocking();

    KnowledgeKinematicGroup* get_buddies();
    SteeringForce get_force() override;
};

#endif // !FLOCKING_CLASS
