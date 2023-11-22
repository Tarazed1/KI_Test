#ifndef	RANDOM_CLASS
#define RANDOM_CLASS

#include <godot_cpp/classes/ref.hpp>

using namespace godot;

class Random : public RefCounted {
	GDCLASS(Random, RefCounted);
	float get_random_float_basic(float max);

protected:
	static void _bind_methods();

public:
	int get_random_int(bool equalliyDistributed, int min, int max);
	float get_random_float(bool equallyDistributed, float min, float max);
	float get_float_perlin(float x, float a = 0.3, float b = -3.2, float c = -1.3, float d = -1.2, float e = -1.7, float f = 1.9, float g = 0.7);
	void create_file(int identifier, int numberOfTries, bool equally, float min, float max, bool useBreak);
};

#endif // !RANDOM_CLASS