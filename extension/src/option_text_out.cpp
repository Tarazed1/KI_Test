#include "option_text_out.h"
#include <string>
#include <godot_cpp/variant/utility_functions.hpp>

OptionTextOut::OptionTextOut() {
	this->time = 0.0;

}

OptionTextOut::~OptionTextOut()
{

}

void OptionTextOut::_process(double delta) {
	//Option::_process(delta);
	time += delta;
	cooldown -= delta;
	if (static_cast<int>(time) % 30 == 29) {
		//std::string out = std::to_string(time) + " seconds have passed since start.";
		UtilityFunctions::print(time, " seconds have passed since start.");
	}
}

void OptionTextOut::pause_game() {
	if (cooldown > 0) {
		//std::cout << "Paausing on CD.\n";
		UtilityFunctions::print("Pausing on CD.", cooldown);
		return;
	}
	Option::pause_game();
	UtilityFunctions::print("Pausing Game", cooldown);
	//std::cout << "Pausing game.\n";
}

void OptionTextOut::continue_game() {
	if (cooldown > 0) {
		UtilityFunctions::print("Pausing on CD.");
		//std::cout << "Paausing on CD.\n";
		return;
	}
	Option::continue_game();
	UtilityFunctions::print("Resuming Game.");
	//std::cout << "Resuming game.\n";
}

void OptionTextOut::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("pause_game"), &OptionTextOut::pause_game);
	ClassDB::bind_method(D_METHOD("continue_game"), &OptionTextOut::continue_game);
}