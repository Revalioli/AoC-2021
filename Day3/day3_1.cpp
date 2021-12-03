#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void day3_1(const string& input){
	istringstream iss(input);

	string line;
	iss >> line;
	int s = line.length();
	vector<int> count(s);

	do {
		for(int i = 0; i < s; i++)
			count[i] += (line[i] == '0') ? 1 : -1;
	} while (iss >> line);

	unsigned short gamma = 0;
	for(int i = 0; i < s; i++)
		gamma = (gamma << 1) + (count[i] > 0 ? 0 : 1);

	cout << (unsigned short)((0xffff << s) ^ (~gamma)) * gamma << endl;
}