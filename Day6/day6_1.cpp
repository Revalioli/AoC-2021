#include <string>
#include <vector>
#include "AoC.h"

using namespace std;

void day6_1(const string& input){
	string cpy(input);

	int fish[7] = {0, 0, 0, 0, 0, 0, 0};
	int fish_7 = 0, fish_8 = 0;

	vector<string> nums = AoC::split(AoC::chomp(cpy), ',');
	for(const string& s : nums)
		fish[stoi(s)]++;

	int start = 0;
	bool toggle = true;

	for(int i = 0; i < 80; i++){
		int new_fish = fish[start];
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

	int accu = 0;
	for(int x : fish)
		accu += x;

	cout << accu + fish_7 + fish_8 << endl;
}