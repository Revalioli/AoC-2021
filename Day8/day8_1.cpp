#include <string>
#include <iostream>

#include "AoC.h"

using namespace std;

void day8_1(const string& input){

	vector<string> lines = AoC::split(input, '\n', true);

	vector<int> buff(8);

	for(const auto& l : lines){
		vector<string> output = AoC::split(l.substr(l.rfind('|')+2), ' ');
		for(const auto& o : output)
			buff[o.size()]++;
	}

	cout << buff[2] + buff[3] + buff[4] + buff[7] << endl;
}