#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ifstream input_f("input.txt");
	string instruction;
	int delta, x = 0, y = 0;

	while(input_f >> instruction){
		input_f >> delta;
		if(instruction == "forward")
			x += delta;
		else if(instruction == "down")
			y += delta;
		else	// up
			y -= delta;
	}

	input_f.close();

	cout << x*y << endl;
}
