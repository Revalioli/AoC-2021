#ifndef DAY4_GRID_H
#define DAY4_GRID_H

#include <vector>
#include <string>
#include "Tile.h"

using namespace std;

class Grid {

	int w,h;
	vector<vector<Tile>> tiles;	// [row][column]
	vector<int> row_counters;
	vector<int> column_counters;

	bool is_finished;

public:
	Grid(const vector<string>& grid_rows);

	void check(int num);
	void reset();

	void reload(const vector<string>& grid_rows);

	void display();
	int sum_unchecked();

	friend void day4_1(const string& input);
	friend void day4_2(const string& input);
};

#endif //DAY4_GRID_H
