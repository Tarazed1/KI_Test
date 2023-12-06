#include "flocking.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include "knowledgeposition.h"
#include <sstream>

Flocking::Flocking() : SteeringBehaviour()
{
	buddies = new KnowledgeKinematicGroup();
	cohesion = nullptr;
	separation = nullptr;
	velocityMatching = nullptr;
}

Flocking::Flocking(Kinematics* inKin) : SteeringBehaviour(inKin)
{
	buddies = new KnowledgeKinematicGroup();
	cohesion = nullptr;
	separation = nullptr;
	velocityMatching = nullptr;
}

Flocking::Flocking(Kinematics* inKin, KnowledgeKinematicGroup* group) : SteeringBehaviour(inKin)
{
	buddies = group;
	cohesion = nullptr;
	separation = nullptr;
	velocityMatching = nullptr;
	wander = new Wander(inKin);

	if (buddies) {
		cohesion = new Cohesion(inKin, buddies);
		separation = new Separation(inKin, buddies);
		velocityMatching = new VelocityMatching(inKin, buddies);
	}
	else {
		UtilityFunctions::print("Your buddies are empty. (Location: Flocking Constructor)");
	}
}

Flocking::~Flocking()
{
	buddies = nullptr;
}

KnowledgeKinematicGroup* Flocking::get_buddies()
{
	return buddies;
}

SteeringForce Flocking::get_force()
{
	SteeringForce aSteeringForce;

	if (!buddies) {
		UtilityFunctions::printerr("Your Buddies are empty. (Location: Flocking get_force())");
		return aSteeringForce;
	}

	if (wanderWeight != 0) aSteeringForce += wander->get_force() * wanderWeight;
	if(cohesionWeight != 0) aSteeringForce += cohesion->get_force() * cohesionWeight;
	if(separationWeight != 0) aSteeringForce += separation->get_force() * separationWeight;
	if(velocityMatchingWeight != 0) aSteeringForce += velocityMatching->get_force() * velocityMatchingWeight;

	return aSteeringForce;
}
