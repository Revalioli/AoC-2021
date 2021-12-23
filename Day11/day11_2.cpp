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
int FLASH(int x, int y, vector<string>& grid);	// From part 1

void day11_2(const string& input){
	vector<string> grid = AoC::split(input, '\n', true);	// [line][column]	[y][x]

	int simulation_time = 1000;
	int flashs_count = 0;
	int h = grid.size();
	int w = grid[0].size();
	bool has_not_flashed = true;

	for(int turn = 1; turn <= simulation_time; turn++){

		has_not_flashed = true;

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
				else {
					grid[y][x]++;
					has_not_flashed = false;
				}
			}
		}

//		cout << "Printing turn " << turn << endl;
//		for(const auto& l : grid)
//			cout << l << endl;
//		cout << "Score : " << flashs_count << endl;

		if(has_not_flashed){
			cout << turn << endl;
			break;
		}
	}
}