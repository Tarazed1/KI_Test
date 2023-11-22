extends Node3D

var model;

# Called when the node enters the scene tree for the first time.
func _ready():
	model = MeshInstance3D.new();
	model.mesh = SphereMesh.new();
	add_child(model);
	


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
