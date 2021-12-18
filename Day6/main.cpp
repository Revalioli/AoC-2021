#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include "AoC.h"

using namespace std;

using timeUnit = std::chrono::microseconds;

void day6_1(const string& input);
void day6_2(const string& input);

int main(int argc, char* argv[]) {
	ifstream input_f("input.txt");
	string input;
	ostringstream ss;
	ss << input_f.rdbuf();
	input = ss.str();

	// Specific day
	if(argc > 1){
		switch(stoi(argv[1])){
			case 1:
				day6_1(input);
				break;
			case 2:
				day6_2(input);
				break;
			default:
				cout << "Part number should be 1 or 2" << endl;
		}
	}
	else{
		// ===[ Time benchmarks ]===

		int samples = 500;

		// Part 1 and 2
		cout << "=== Part 1" << endl;
		AoC::timeBenchmark<timeUnit>(day6_1, input, samples, "microseconds");

		cout << "=== Part 2" << endl;
		AoC::timeBenchmark<timeUnit>(day6_2, input, samples, "microseconds");
	}
}