extends Node3D

var testNPC;

# Called when the node enters the scene tree for the first time.
func _ready():
	testNPC = NPC.new();
	add_child(testNPC);
	testNPC.set_color(Color.GREEN); 

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass;	
