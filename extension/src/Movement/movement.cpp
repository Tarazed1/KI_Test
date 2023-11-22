//#include "movement.h"
//#include <godot_cpp/core/class_db.hpp>
//
//using namespace godot;
//
//void Movement::_bind_methods() {
//	ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &Movement::set_amplitude);
//	ClassDB::bind_method(D_METHOD("get_amplitude"), &Movement::get_amplitude);
//	ClassDB::bind_method(D_METHOD("get_speed"), &Movement::get_speed);
//	ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &Movement::set_speed);
//	ClassDB::add_property("Movement", PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "0,20,0.01"), "set_speed", "get_speed");
//	ClassDB::add_property("Movement", PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");
//}
//
//Movement::Movement() {
//	time_passed = 0.0;
//	amplitude = 10.0;
//	speed = 10.0;
//}
//
//Movement::~Movement() {
//
//}
//
//void Movement::set_amplitude(const double p_amplitude) {
//	this->amplitude = p_amplitude;
//}
//
//double Movement::get_amplitude() const {
//	return amplitude;
//}
//
//void Movement::set_speed(const double p_speed) {
//	this->speed = p_speed;
//}
//
//double Movement::get_speed() const {
//	return speed;
//}
//
//void Movement::_process(double delta) {
//	time_passed += delta * speed;
//
//	Vector3 new_position = Vector3(
//		amplitude + (amplitude * sin(time_passed * 2.0)),
//		amplitude + (amplitude * cos(time_passed * 1.5)),
//		0.0);
//
//	set_position(new_position);
//}