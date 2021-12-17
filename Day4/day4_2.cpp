#include <string>
#include <sstream>
#include <iostream>
#include "AoC.h"
#include "Grid.h"

using namespace std;

void day4_2(const string& input){
	istringstream iss(input);

	string line;
	getline(iss, line);

	vector<string> numbers_str = AoC::split(line, ',');
	vector<int> numbers = AoC::map<int>(numbers_str, [](string s) -> int {return stoi(s); });

	getline(iss, line);	// Empty line
	vector<Grid> grids;

	while(getline(iss, line)){
		vector<string> grid_numbers;

		// While the line contains a new row
		while(!line.empty()){
			grid_numbers.push_back(line);	// Saves line
			getline(iss, line);		// Fetches next line
		}

		// Empty line was fetched

		grids.emplace_back(grid_numbers);
	}

	for(int i : numbers){

		for(int g = 0; g < grids.size(); g++){
			grids[g].check(i);
			if(grids[g].is_finished){
				if(grids.size() == 1){	// Last grid
					cout << grids[g].sum_unchecked() * i << endl;
					return;
				}
				grids.erase(grids.begin()+g);
				g--;
			}
		}

	}
}
