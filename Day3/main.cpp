#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;

void day3_1(const string& input);
void day3_2(const string& input);

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
				day3_1(input);
				break;
			case 2:
				// Part 2
				day3_2(input);
				break;
			default:
				cout << "Part number should be 1 or 2" << endl;
		}
	}
	else{
		// Part 1 and 2
		cout << "Part 1" << endl;
		std::chrono::time_point<std::chrono::steady_clock> start, end;

		start = std::chrono::steady_clock::now();
		day3_1(input);
		end = std::chrono::steady_clock::now();

		std::chrono::microseconds elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		cout << "Elapsed time : " << elapsed_time.count() << " mircoseconds" << endl;

		cout << "Part 2" << endl;
		start = std::chrono::steady_clock::now();
		day3_2(input);
		end = std::chrono::steady_clock::now();

		elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		cout << "Elapsed time : " << elapsed_time.count() << " mircoseconds" << endl;
	}
}
