#ifndef OPTION_CLASS
#define OPTION_CLASS

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/input_event_action.hpp>

using namespace godot;

class Option : public Node3D {

	GDCLASS(Option, Node3D);

	//static Option* instance;

protected:
	bool gameIsRunning;
	double time;
	float cooldown;
	static void _bind_methods();

public:
	Option();
	Option(float cooldownTime);
	~Option();

	void _process(double delta) override;
	virtual void pause_game();
	virtual void continue_game();
	//static Option* get_instance();
	bool get_gamestate();
};

#endif // !OPTION_CLASS
