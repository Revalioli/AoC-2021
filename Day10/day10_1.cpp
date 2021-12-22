#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>

#include "AoC.h"

using namespace std;

void day10_1(const string& input){
	vector<string> lines = AoC::split(input, '\n');
	lines.pop_back();	// Remove last empty line because of newline

	map<char, int> scores = { {')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
	map<char, char> delimiters = { {'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'} };
	deque<char> chunks_stack;
	int syntax_error_score = 0;

	for(const auto& l : lines){

		for(const char& c : l){

			if(c == ')' || c == ']' || c == '}' || c == '>'){
				if(chunks_stack.back() != c){	// Not the expected end-of-chunk-delimiter
					syntax_error_score += scores[c];
					break;
				}

				chunks_stack.pop_back();
			}
			else
				chunks_stack.push_back(delimiters[c]);

		}

		chunks_stack.clear();
	}

	cout << syntax_error_score << endl;
}