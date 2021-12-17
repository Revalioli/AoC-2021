#ifndef DAY4_TILE_H
#define DAY4_TILE_H


class Tile {
	bool checked;
	int num;
public:

	Tile(int num);

	bool check(int to_check);
	void reset();

	friend class Grid;
};


#endif //DAY4_TILE_H
