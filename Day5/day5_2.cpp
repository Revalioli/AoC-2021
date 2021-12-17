#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "AoC.h"

using namespace std;

void increaseTile(int x, int y, vector<vector<int>>& grid, int& result);
// Function of part 1

void day5_2(const string& input){

	int x1 = 0, y1 = 0, x2= 0, y2 = 0;

	int result = 0;

	vector<vector<int>> grid;

	// With std::find --> It is more work to write this, but in release mode it is much faster than sscanf

	auto pos = input.begin();
	auto end = input.end();

	while(pos != end){

		// Parsing line
		auto sub_str_end = find(pos, end, ',');
		x1 = stoi(std::string(pos, sub_str_end));
		pos = sub_str_end+1;

		sub_str_end = find(pos, end, ' ');
		y1 = stoi(std::string(pos, sub_str_end));
		pos = sub_str_end + 4;

		sub_str_end = find(pos, end, ',');
		x2 = stoi(std::string(pos, sub_str_end));
		pos = sub_str_end+1;

		sub_str_end = find(pos, end, '\n');
		y2 = stoi(std::string(pos, sub_str_end));
		pos = sub_str_end+1;

//		cout << "Parsed line : p1 = (" << x1 << "," << y1 << ", p2 = (" << x2 << "," << y2 << ")" << endl;

		if(y1 == y2){
			int x_max = max(x1, x2);
			int x_min = min(x1, x2);

			for(int i = x_min; i <= x_max; i++)
				increaseTile(i, y1, grid, result);

			continue;
		}
		// Vertical
		if(x1 == x2){
			int y_max = max(y1, y2);
			int y_min = min(y1, y2);

			for(int i = y_min; i <= y_max; i++)
				increaseTile(x1, i, grid, result);

			continue;
		}

		int x_max = max(x1, x2);
		int x_min = min(x1, x2);
		int y_max = max(y1, y2);
		int y_min = min(y1, y2);
		int length = x_max - x_min + 1;

		// Diagonal up-left -> down-right
		if( x_min == x1 && y_min == y1 || x_min == x2 && y_min == y2){
			for(int i = 0; i < length; i++)
				increaseTile(x_min + i, y_min + i, grid, result);
		}
		// Diagonal down-left -> up-right
		else{
			for(int i = 0; i < length; i++)
				increaseTile(x_min + i, y_max - i, grid, result);
		}
	}

	cout << result << endl;
}