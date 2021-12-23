#include <iostream>
#include <string>

#include "AoC.h"

using namespace std;

/**
 * \brief Flash one octopus, and update adjacent octopus (in a pre turn increment context)
 * \param x x coordinate of the octopus
 * \param y t coordinate of the octopus
 * \param grid the grid
 * \return the total of octopus that cascade-flashed
 */
int FLASH(int x, int y, vector<string>& grid){
	static vector<pair<int, int>> moves = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

	int h = grid.size();
	int w = grid[0].size();
	int score = 0;

	grid[y][x]++;

	for(const auto& m : moves){
		int new_x = x+m.first;
		int new_y = y+m.second;
		if(new_x < 0 || new_x >= w || new_y < 0 || new_y >= h)	// Out of bounds
			continue;

		if(grid[new_y][new_x] < '9')
			grid[new_y][new_x]++;
		if(grid[new_y][new_x] == '9')
			score += FLASH(new_x, new_y, grid);
	}

	return score+1;

}

void day11_1(const string& input){
	vector<string> grid = AoC::split(input, '\n', true);	// [line][column]	[y][x]

	int simulation_time = 100;
	int flashs_count = 0;
	int h = grid.size();
	int w = grid[0].size();

	for(int turn = 1; turn <= simulation_time; turn++){

		for(int x = 0; x < w; x++){
			for(int y = 0; y < h; y++){

				if(grid[y][x] == '9')
					flashs_count += FLASH(x, y, grid);

			}
		}

		for(int x = 0; x < w; x++){
			for(int y = 0; y < h; y++){
				if(grid[y][x] >= '9')
					grid[y][x] = '0';
				else
					grid[y][x]++;
			}
		}

//		cout << "Printing turn " << turn << endl;
//		for(const auto& l : grid)
//			cout << l << endl;
//		cout << "Score : " << flashs_count << endl;

	}

	cout << flashs_count << endl;
}