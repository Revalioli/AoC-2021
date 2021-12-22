#include <string>
#include <iostream>
#include <utility>

#include "AoC.h"

using namespace std;
using Point = std::pair<int, int>;

/**
 * \brief Computes the size of the basin of the low point p
 * \param x the x coordinate of p
 * \param y the y coordinate of p
 * \param w width of the grid
 * \param h height of the grid
 * \param grid the vector<string> grid
 * \param visited the mirror grid holding the visited state of every tile
 * \return the size of the basin
 */
int computeBasinSize(const int x, const int y, const int h, const int w, vector<string>& grid, vector<vector<bool>>& visited){
	const char& tile = grid[y][x];
	int size = 0;

	// Recursively calls the function for its neighbors
	if(y > 0 && !visited[y-1][x] && grid[y-1][x] != '9' && grid[y-1][x] > tile){	// Has up neighbor
		size += computeBasinSize(x, y-1, h, w, grid, visited);
		visited[y-1][x] = true;
	}
	if(y < h-1 && !visited[y+1][x] && grid[y+1][x] != '9' && grid[y+1][x] > tile){	// Has down neighbor
		size += computeBasinSize(x, y+1, h, w, grid, visited);
		visited[y+1][x] = true;
	}
	if(x > 0 && !visited[y][x-1] && grid[y][x-1] != '9' && grid[y][x-1] > tile){	// Has left neighbor
		size += computeBasinSize(x-1, y, h, w, grid, visited);
		visited[y][x-1] = true;
	}
	if(x < w-1 && !visited[y][x+1] && grid[y][x+1] != '9' && grid[y][x+1] > tile){	// Has right neighbor
		size += computeBasinSize(x+1, y, h, w, grid, visited);
		visited[y][x+1] = true;
	}

	return size + 1;		// Add current point and return
}


void day9_2(const string& input){
	vector<string> grid = AoC::split(input, '\n', true);	// [line][column]	[y][x]
	int w = grid[0].size();
	int h = grid.size();
	vector<vector<bool>> visited(h, vector<bool>(w, false));

	vector<Point> low_points;

	vector<int> largest(3);

	// Finding all low points
	for(int x = 0; x < w; x++){
		for(int y = 0; y < h; y++){

			char tile = grid[y][x];

			if(!(y > 0 && grid[y-1][x] <= tile			// Has up neighbor
				 || y < h-1 && grid[y+1][x] <= tile 	// Has down neighbor
				 || x > 0 && grid[y][x-1] <= tile		// Has left neighbor
				 || x < w-1 && grid[y][x+1] <= tile		// Has right neighbor
			)){
//				cout << "Bassin at (" << x << ',' << y << "), tile = " << tile << endl;
				int basin_size = computeBasinSize(x, y, h, w, grid, visited);
//				cout << "Its size is " << basin_size << endl;

				for(int i = 0; i <  3; i++){
					if(basin_size > largest[i]){
						largest.pop_back();
						largest.insert(largest.begin()+i, basin_size);
						break;
					}
				}
			}

		}
	}

	cout << (largest[0] * largest[1] * largest[2]) << endl;

}