#include "flocking.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <string>
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

	if (buddies) {
		cohesion = new Cohesion(inKin, buddies);
		separation = new Separation(inKin, buddies);
		velocityMatching = new VelocityMatching(inKin, buddies);

		std::ostringstream address, address2;
		address << (void const*)buddies;
		address2 << (void const*)group;
		godot::String in = address.str().c_str();
		in += " ";
		in += address2.str().c_str();
		UtilityFunctions::print("flocking init :", in);
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

	if (subTimer > 6.0f) {
		subTimer = 0.0f;
		UtilityFunctions::print("flocking: ", buddies->get_kinematic(0)->position, aSteeringForce.movementForce);
		std::ostringstream address;
		address << (void const*)cohesion;
		godot::String in = address.str().c_str();
		UtilityFunctions::print("test pointer: ", in);
		//Kinematics kin = *buddies->get_kinematic(0);
		//Kinematics kan = *buddies->get_kinematic(4);
		//UtilityFunctions::print("kin 1:", kin.velocity, kin.position, kin.maxMovementForce, kin.maxMovementVelocity);
		//UtilityFunctions::print("kin 2:", kan.velocity, kan.position, kan.maxMovementForce, kan.maxMovementVelocity);
	}

	return aSteeringForce;
}
