#ifndef STEERINGFORCE_CLASS
#define STEERINGFORCE_CLASS

#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/classes/ref.hpp>

using namespace godot;

//namespace movement {
	class SteeringForce : RefCounted {
	private:
	
	protected:

	public:
		SteeringForce();
		SteeringForce(Vector3 movementForce, float angularForce);

		Vector3 movementForce;
		float angularForce;

		SteeringForce operator+= (const SteeringForce& rhs);
		SteeringForce operator* (float rhs);
		SteeringForce operator+ (SteeringForce& rhs);
		SteeringForce operator= (const SteeringForce& rhs);
	};
//}

#endif // !STEERINGFORCE_CLASS
