extends KnowledgeKinematicGroup

@export var numberNPCS = 5;
var leader;
var array = []
var rng = RandomNumberGenerator.new()
var t = 0;

# Called when the node enters the scene tree for the first time.
func _ready():
	leader = NPC.new();
	add_child(leader);
	leader.set_position_intern(Vector3(1, 0, 1));
	leader.change_behaviour(0);
	leader.set_target(Vector3(10, 0, 10));
	subscribe(leader.get_kinematics());
	for n in numberNPCS:
		#var npc = await NPC.new();
		array.append(NPC.new());
		add_child(array[n]);
		array[n].set_position_intern(Vector3(rng.randf_range(-10, 10), 0, rng.randf_range(-2, 2)));
		if(array[n].get_kinematics() == null):
			print("mama mia");
		subscribe(array[n].get_kinematics());
	for n in array:
		n.init_flocking(self);
		n.set_target(Vector3(10, 0, 10));
		n.change_behaviour(2);


# Called every frame. 'delta' is the elapsed time since the previous frame.
@warning_ignore("unused_parameter")
func _process(delta):
	t = t + delta;
	if(t > 3): 
		#var string = array[2].debug_buddies();
		#rint(string);
		for n in array:
			n.change_behaviour(3);
		#debug();
		#for n in array:
		#	print(n.position);
		t = 0;
	pass
