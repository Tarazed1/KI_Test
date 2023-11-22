#include "option.h"
#include <godot_cpp/core/class_db.hpp>


Option::Option() {
	this->cooldown = 1.0;
	this->time = 0.0;
	gameIsRunning = true;
}

Option::Option(float cooldownTime) {
	//if (instance != nullptr && instance != this) {
	//	std::cout << "There already is a Option-Instance. Destroying this one!" << std::endl;
	//	delete(this);
	//}
	//else {
	//	instance = this;
	//}
	this->cooldown = cooldownTime;
	this->time = 0;
}

Option::~Option() {

}

void Option::_process(double delta) {
	this->time += delta;
	this->cooldown -= delta;
}

//Option* Option::get_instance() {
//	return instance;
//}

void Option::pause_game() {
	cooldown = 1.0;
	gameIsRunning = false;
}

void Option::continue_game() {
	cooldown = 1.0;
	gameIsRunning = true;
}

bool Option::get_gamestate() {
	return gameIsRunning;
}

void Option::_bind_methods() {
	//ClassDB::bind_method(D_METHOD("get_instance"), &Option::get_instance);
	ClassDB::bind_method(D_METHOD("pause_game"), &Option::pause_game);
	ClassDB::bind_method(D_METHOD("continue_game"), &Option::continue_game);
	ClassDB::bind_method(D_METHOD("get_gamestate"), &Option::get_gamestate);
}