extends KnowledgeKinematicGroup

@export var numberNPCS = 5;
var array = []
var rng = RandomNumberGenerator.new()

# Called when the node enters the scene tree for the first time.
func _ready():
	for n in numberNPCS:
		var npc = NPC.new();
		array.append(npc);
		add_child(npc);
		npc.set_position(Vector3(rng.randf_range(-20, 20), 0, rng.randf_range(-20, 20)));
		subscribe(npc.get_kinematics());
	for n in array:
		n.init_flocking(self);
		n.change_behaviour(3);


# Called every frame. 'delta' is the elapsed time since the previous frame.
@warning_ignore("unused_parameter")
func _process(delta):
	pass
