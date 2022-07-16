#include <string>
#include <iostream>
#include <cstdio>
#include <list>
#include <map>
#include <algorithm>
#include "AoC.h"

using namespace std;
void day14_1(const string& input){
	vector<string> lines = AoC::split(input, '\n', true);	// Line 1 : initial template, lines 2.. rules

	list<char> polymer(lines[0].begin(), lines[0].end());
	map<string, char> rules;

	map<char, int> counters;
	for(auto c : polymer)
		counters[c]++;


	for(auto it = lines.begin()+1; it < lines.end(); it++){
		char rule[3];
		char add;

		sscanf(it->c_str(), "%s -> %c", rule, &add);

		rules[rule] = add;
	}

	int steps = 10;

	for(int i = 0; i < steps; i++){
		for(auto it = polymer.begin(); it != polymer.end()--; it++){

			auto it2 = it;
			it2++;

			auto to_add_it = rules.find({*it, *it2});

			if(to_add_it != rules.end()){
				polymer.insert(it2, to_add_it->second);
				it++;
				counters[to_add_it->second]++;
			}

		}
	}

//	for(const auto& c : polymer)
//		cout << c;
//	cout << endl;

	// Searching most and least common
	auto min_max = minmax_element(counters.begin(), counters.end(),
			  [](const pair<char, int>& a, const pair<char, int>& b) -> bool {return a.second < b.second;} );

	cout << ((*min_max.second).second - (*min_max.first).second) << endl;
}