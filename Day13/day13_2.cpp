#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <climits>

#include "AoC.h"

using namespace std;
using point = pair<int, int>;

void day13_2(const string& input){
	vector<string> lines = AoC::split(input, '\n');
	lines.pop_back();	// Remove last empty line

	set<point> sheet;
	int w = 0, h = 0;

	auto it = lines.begin();
	for(; !(*it).empty(); it++){
		vector<string> temp = AoC::split(*it, ',');

		int x = stoi(temp[0]);
		int y = stoi(temp[1]);

		w = max(w, x+1);
		h = max(h, y+1);

		sheet.emplace(x, y);	// x,y
	}

	for(it++ /* Skipping empty line */ ; it != lines.end(); it++){
		char axis;
		int coord;
		sscanf(it->c_str(), "fold along %c=%d", &axis, &coord);

		for(auto it_sheet = sheet.begin(); it_sheet != sheet.end();){

			point p = *it_sheet;

			if(axis == 'x'){
				if(p.first >= coord){	// Point is in the folded part
					it_sheet = sheet.erase(it_sheet);

					if(p.first > coord){	// Point isn't on the folding line
						p.first = coord - (p.first - coord);

						if(sheet.find(p) == sheet.end())	// New point does not exist
							sheet.insert(p);
					}

				}
				else
					it_sheet++;

				w = coord;
			}
			else{	// y
				if(p.second >= coord){	// Point is in the folded part
					it_sheet = sheet.erase(it_sheet);

					if(p.second > coord){	// Point isn't on the folding line
						p.second = coord - (p.second - coord);

						if(sheet.find(p) == sheet.end())	// New point does not exist
							sheet.insert(p);
					}

				}
				else
					it_sheet++;

				h = coord;
			}

		}

	}

	vector<vector<char>> grid(h, vector<char>(w, '.'));	// [y][x]
	for(const auto& p : sheet)
		grid[p.second][p.first] = '#';

	for(const auto& l : grid){
		for(const auto& c : l){
			cout << c;
		}
		cout << endl;
	}

}