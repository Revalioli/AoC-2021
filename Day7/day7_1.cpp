#include <iostream>
#include <string>
#include <sstream>
#include <numeric>
#include <algorithm>
#include "AoC.h"

using namespace std;

void day7_1(const string& input){
	// The result coordinate is the median one

	// Parsing
	vector<int> nums;
	int axis_size = 0;
	nums.reserve(3000);
	size_t pos = 0;
	for(size_t sub = input.find(',', pos); sub != string::npos ;sub = input.find(',', pos)){	// Fastest way I found to parse the input
		int num = stoi(input.substr(pos, sub-pos));
		axis_size = max(axis_size, num);
		nums.push_back(num);
		pos = sub+1;
	}
	nums.push_back(stoi(input.substr(pos)));
	sort(nums.begin(), nums.end());

	int max_coord = nums[nums.size()/2];

	int result = 0;
	for(const int& i : nums)
		result += abs(i-max_coord);

	cout << result << endl;
}