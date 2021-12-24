#include <string>
#include <iostream>
#include <vector>
	#include <set>
	#include <numeric>
	#include <climits>

#include "AoC.h"

using namespace std;
using point = pair<int, int>;

void day13_1(const string& input){
	vector<string> lines = AoC::split(input, '\n');
	set<point> sheet;

	auto it = lines.begin();
	for(; !(*it).empty(); it++){
		vector<string> temp = AoC::split(*it, ',');

		sheet.emplace(stoi(temp[0]), stoi(temp[1]));	// x,y
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
			}

		}

		break;	// Because part 1
	}

	cout << sheet.size() << endl;
}