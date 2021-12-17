#include "Tile.h"

Tile::Tile(int num) : num(num), checked(false) {}

bool Tile::check(int to_check) {
	if(num == to_check && !checked) {
		checked = true;
		return true;
	}

	return false;
}

void Tile::reset() {
	checked = false;
}

