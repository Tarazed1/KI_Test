#include "flocking.h"
#include <godot_cpp/variant/utility_functions.hpp>

Flocking::Flocking() : SteeringBehaviour()
{
	buddies = new KnowledgeKinematicGroup();
	cohesion = nullptr;
	separation = nullptr;
	velocityMatching = nullptr;
}

Flocking::Flocking(Kinematics& inKin) : SteeringBehaviour(inKin)
{
	buddies = new KnowledgeKinematicGroup();
	cohesion = nullptr;
	separation = nullptr;
	velocityMatching = nullptr;
}

Flocking::Flocking(Kinematics& inKin, KnowledgeKinematicGroup& group) : SteeringBehaviour(inKin)
{
	buddies = &group;
	cohesion = nullptr;
	separation = nullptr;
	velocityMatching = nullptr;

	if (buddies) {
		cohesion = new Cohesion(inKin, *buddies);
		separation = new Separation(inKin, *buddies);
		velocityMatching = new VelocityMatching(inKin, *buddies);
	}
	else {
		UtilityFunctions::print("Your buddies are empty.");
	}
}

Flocking::~Flocking()
{
	buddies = nullptr;
}

SteeringForce Flocking::get_force()
{
	SteeringForce aSteeringForce;
	if (!buddies) return aSteeringForce;

	aSteeringForce += cohesion->get_force() * cohesionWeight;
	aSteeringForce += separation->get_force() * separationWeight;
	aSteeringForce += velocityMatching->get_force() * velocityMatchingWeight;

	return aSteeringForce;
}
