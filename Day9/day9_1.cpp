#include <string>
#include <iostream>
#include <vector>

#include "AoC.h"

using namespace std;

void day9_1(const string& input){
	vector<string> grid = AoC::split(input, '\n', true);	// [line][column]	[y][x]

	int risk_lvl = 0;

	int w = grid[0].size();
	int h = grid.size();

	for(int x = 0; x < w; x++){
		for(int y = 0; y < h; y++){

			char tile = grid[y][x];

			if(!(y > 0 && grid[y-1][x] <= tile		// Has up neighbor
				|| y < h-1 && grid[y+1][x] <= tile 	// Has down neighbor
				|| x > 0 && grid[y][x-1] <= tile		// Has left neighbor
				|| x < w-1 && grid[y][x+1] <= tile	// Has right neighbor
			))
				risk_lvl += tile - '0' + 1;

		}
	}

	cout << risk_lvl << endl;
}