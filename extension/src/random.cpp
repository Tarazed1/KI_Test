#include "random.h"
#include "Math.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

float Random::get_random_float_basic(float max) {
	return (static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX / max));
}

int Random::get_random_int(bool equallyDistributed, int min, int max) {
	int random = 0;

	if (equallyDistributed) {
		random = std::rand() % (max - min) + min; 
	}
	else {
		random =
			(std::rand() % (max - min) + min +
			std::rand() % (max - min) + min +
			std::rand() % (max - min) + min) / 3;
	}

	return random;
}

float Random::get_random_float(bool equallyDistributed, float min, float max) {
	float random = 0;

	if (equallyDistributed) {
		random = (get_random_float_basic(max + min)) + min;
	}
	else {
		random =
			((get_random_float_basic(max + min)) + min +
			(get_random_float_basic(max + min)) + min +
			(get_random_float_basic(max + min)) + min) / 3.0;
	}

	return random;
}

//Function: a * (b * sin(c * x) + d * sin(e * ex) + f * sin(g * pi * x))
float Random::get_float_perlin(float x, float a, float b, float c, float d, float e, float f, float g) {
	float value, clampValue = a + b + d + f;

	clampValue = Math::abs(clampValue);
	if (clampValue < 1.0) clampValue = 1.0;
	value = a * (b * Math::sin(c * x) + d * Math::sin(e * 2.71 * x) + f * sin(g * 3.14 * x)) / clampValue;
	value = (value + 1.0f) / 2.0f;

	return value;
}

void Random::create_file(int identifier, int numberOfTries, bool equally, float min, float max, bool useBreak) {
	std::ofstream myfile;
	myfile.open("C:/GodotProjects/KI_Test/test.txt");
	myfile.clear();

	switch (identifier)
	{
	case 1:
		for (int i = 0; i < numberOfTries; i++) {
			myfile << std::to_string(get_random_float(equally, min, max)) + "\n";
		}
		if (useBreak) break;
	case 2:
		for (int i = 0; i < numberOfTries; i++) {
			myfile << std::to_string(get_random_int(equally, static_cast<int>(min), static_cast<int>(max))) + "\n";
		}
		if (useBreak) break;
	default:
		float noiseX, perlin;
		for (int i = 0; i < numberOfTries; i++) {
			noiseX = (float)i / (float)numberOfTries * 3.0f;
			perlin = get_float_perlin(noiseX, 0.3, -3.2, -1.3, -1.2, 1.7, 1.9, 0.7);
			myfile << std::to_string(perlin) + "\n";
		}
		if (useBreak) break;
	}

	myfile.close();
}

void Random::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_random_int", "equallyDistributed", "min", "max"), &Random::get_random_int);
	ClassDB::bind_method(D_METHOD("get_random_float", "equallyDistributed", "min", "max"), &Random::get_random_float);
	ClassDB::bind_method(D_METHOD("get_float_perlin", "x", "a", "b", "c", "d", "e", "f", "g"), &Random::get_float_perlin, 
		DEFVAL(0.5), DEFVAL(0.3), DEFVAL(-3.2), DEFVAL(-1.3), DEFVAL(-1.2), DEFVAL(1.7), DEFVAL(1.9), DEFVAL(0.7));
	ClassDB::bind_method(D_METHOD("create_file", "identifier", "numberOfTries", "equally", "min", "max", "useBreak"), &Random::create_file);
}