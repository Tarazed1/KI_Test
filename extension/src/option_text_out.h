#ifndef OPTION_TEXT_OUT_CLASS
#define	OPTION_TEXT_OUT_CLASS

#include "option.h"

using namespace godot;

class OptionTextOut : public Option {
	GDCLASS(OptionTextOut, Option);

protected:
	static void _bind_methods();

public:
	OptionTextOut();
	~OptionTextOut();

	void _process(double delta) override;
	void pause_game() override;
	void continue_game() override;
};

#endif // !OPTION_TEXT_OUT_CLASS
