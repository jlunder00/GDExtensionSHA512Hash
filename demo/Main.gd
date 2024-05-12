extends Node


# Called when the node enters the scene tree for the first time.
func _ready():
	var hasher = GDSha512.new()
	var input_string = "Hello, World!"
	var hashed_output = hasher.hash(input_string)
	print("Original: ", input_string)
	print("Hashed: ", hashed_output)


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
