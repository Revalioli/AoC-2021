#include <string>
#include <vector>
#include "AoC.h"

using namespace std;

void day6_2(const string& input){
	string cpy(input);

	long fish[7] = {0, 0, 0, 0, 0, 0, 0};
	long fish_7 = 0, fish_8 = 0;

	vector<string> nums = AoC::split(AoC::chomp(cpy), ',');
	for(const string& s : nums)
		fish[stoi(s)]++;

	int start = 0;
	bool toggle = true;

	for(int i = 0; i < 256; i++){
		long new_fish = fish[start];
		if(toggle){
			fish[start] += fish_7;
			fish_7 = new_fish;
		}
		else{
			fish[start] += fish_8;
			fish_8 = new_fish;
		}
		toggle = !toggle;

		start = (start + 1) % 7;
	}

	long accu = 0;
	for(long x : fish)
		accu += x;

	cout << accu + fish_7 + fish_8 << endl;
}