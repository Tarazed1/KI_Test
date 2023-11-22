extends Node

# Called when the node enters the scene tree for the first time.
func _ready():
	var o = Option.new();
	var r = Random.new();
	var random = r.get_float_perlin();
	r.create_file(0, 200, true, 0, 10, true);
	print(random);


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
