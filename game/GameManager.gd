extends Node3D
 
var npc = NPC.new();
var currentBehaviour = 0;

var numberNPCs = 10;
# Called when the node enters the scene tree for the first time.
func _ready():
	npc.set_target(Vector3(10, 0, 10));
	#npc.set_position(Vector3(10, 0, 10))
	add_child(npc);
	pass


func _input(event):
	if event.is_action_pressed("switchbehaviour"):
		currentBehaviour = currentBehaviour + 1;
		currentBehaviour = currentBehaviour % 3;
		npc.change_behaviour(currentBehaviour);

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	print(npc.position);
	pass;
