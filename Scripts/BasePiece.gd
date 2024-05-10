extends Node
class_name BasePiece

var color = "white"
var piece_type: PieceType

func initialize(_color, _piece_type):
	color = _color
	piece_type = _piece_type
	piece_type.connect("movements_updated", self, "_on_piece_type_updated")

func _on_piece_type_updated(updated_piece_type):
	if piece_type == updated_piece_type:
		update_from_piece_type()

func update_from_piece_type():
	pass

