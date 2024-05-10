# Defines the types of pieces, including image paths for visual representation
extends Resource
class_name PieceType

export var name_hash: String = ""
export(Array, String) var movement_hashes = []
export(String) var image_path = ""  # Path or procedural generation parameters
signal movements_updated

func update_movements(new_movements):
	movement_hashes = new_movements
	name_hash = generate_hash_from_movements(movement_hashes)
	emit_signal("movements_updated", self)

func generate_hash_from_movements(movements):
	var data_string = str(movements)
	return hash_to_base64(data_string)

func hash_to_base64(data):
	var hash = hash_sha256(data)
	return Marshalls.utf8_to_base64(hash)
