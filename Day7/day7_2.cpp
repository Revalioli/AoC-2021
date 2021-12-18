#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <climits>
#include "AoC.h"

using namespace std;

void day7_2(const string& input){

	// Parsing
	vector<int> counters;
	counters.reserve(500);

	int max_coord = 0;
	int min_coord = INT_MAX;

	size_t pos = 0;
	for(size_t sub = input.find(',', pos); sub != string::npos ;sub = input.find(',', pos)){	// Fastest way I found to parse the input
		int num = stoi(input.substr(pos, sub-pos));

		if(num > max_coord)
			max_coord = num;
		else if(num < min_coord)
			min_coord = num;

		if(max_coord >= counters.size())	// Resize vector if needed
			counters.resize(max_coord+1);

		counters[num]++;

		pos = sub+1;
	}

	int num = stoi(input.substr(pos));

	max_coord = max(max_coord, num);
	min_coord = min(min_coord, num);

	if(max_coord >= counters.size())	// Resize vector if needed
		counters.resize(max_coord+1);

	counters[num]++;


	vector<int> coord;
	vector<int> quantity;

	for(int i = min_coord; i <= max_coord; i++){
		if(counters[i] > 0){
			coord.push_back(i);
			quantity.push_back(counters[i]);
		}
	}

	int best_fuel = INT_MAX;

	for(int candidate = min_coord; candidate <= max_coord; candidate++){
		// Computes every possible solutions, stop them if the current total is above the best_fuel total

		int fuel = 0;
		for(int j = 0; fuel < best_fuel && j < coord.size(); j++){
			int d = abs(candidate - coord[j]);
			fuel += quantity[j] * d * (d + 1) / 2;
		}

		if(fuel < best_fuel)
			best_fuel = fuel;
	}

	cout << best_fuel << endl;

}