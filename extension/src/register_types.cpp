#include "register_types.h"
#include "summator.h"
#include "Movement/movement.h"
#include "Movement/steeringforce.h"
#include "npc.h"
#include "option.h"
#include "random.h"
#include "Movement/kinematics.h"
#include "buddycontroller.h"
#include "option_text_out.h"
#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_summator_types(ModuleInitializationLevel p_level)
{
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	ClassDB::register_class<Summator>();
	//ClassDB::register_class<SteeringForce>();
	//ClassDB::register_class<Movement>();
	ClassDB::register_class<NPC>();
	ClassDB::register_class<BuddyController>();
	ClassDB::register_class<KnowledgeKinematicGroup>();
	ClassDB::register_class<Kinematics>();
	ClassDB::register_class<Random>();
	ClassDB::register_class<Option>();
	ClassDB::register_class<OptionTextOut>();
}

void uninitialize_summator_types(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C"
{

	// Initialization.

	GDExtensionBool GDE_EXPORT summator_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
		GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(initialize_summator_types);
		init_obj.register_terminator(uninitialize_summator_types);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}
