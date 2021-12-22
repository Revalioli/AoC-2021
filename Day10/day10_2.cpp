#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <string>
#include <iterator>
#include "AoC.h"

using namespace std;

long computeLine(const string& line){
	static map<char, char> delimiters = { {'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'} };
	static map<char, int> scores = { {')', 1}, {']', 2}, {'}', 3}, {'>', 4}};

	deque<char> chunks_stack;

	for(const char& c : line) {

		if (c == ')' || c == ']' || c == '}' || c == '>') {
			if (chunks_stack.back() != c)	// Corrupted line, skip it you fool
				return 0;

			chunks_stack.pop_back();
		} else
			chunks_stack.push_back(delimiters[c]);

	}

	long score = 0;

	while(!chunks_stack.empty()){
		score = (score * 5) + scores[chunks_stack.back()];
		chunks_stack.pop_back();
	}

	return score;
}

void day10_2(const string& input){
	vector<string> lines = AoC::split(input, '\n');
	lines.pop_back();	// Remove last empty line because of newline

	list<long> autocomplete_tools_scores;

	for(const auto& l : lines){
		long score = computeLine(l);
		if(score > 0)
			autocomplete_tools_scores.push_back(score);
	}

	autocomplete_tools_scores.sort();

	cout << *next(autocomplete_tools_scores.begin(), autocomplete_tools_scores.size()/2) << endl;
}