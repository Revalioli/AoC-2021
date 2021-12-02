#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ifstream input_f("input.txt");
	string instruction;
	int delta, x = 0, y = 0, aim = 0;

	while(input_f >> instruction){
		input_f >> delta;
		if(instruction == "forward"){
			x += delta;
			y += aim*delta;
		}
		else if(instruction == "down")
			aim += delta;
		else	// up
			aim -= delta;
	}

	input_f.close();

	cout << x*y << endl;
}
