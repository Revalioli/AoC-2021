#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

void increaseTile(int x, int y, vector<vector<int>>& grid, int& result){
	// x check
	if(x >= grid.size())
		grid.resize(x+1);
	// y check
	if(y >= grid[x].size())
		grid[x].resize(y+1);

	int& point = grid[x][y];
	point++;
	if(point == 2)
		result++;
}

void day5_1(const string& input){

	int x1 = 0, y1 = 0, x2= 0, y2 = 0;

	int result = 0;

	/* ===[Map version ~13ms]=== */
//	map<int, map<int, int>> grid;	// [x][y]
	/* ===[Array version ~3.2ms]=== */
	vector<vector<int>> grid;

	// With std::find --> It is more work to write this, but in release mode it is much faster than sscanf

    auto pos = input.begin();
    auto end = input.end();

    while(pos != end){

		// Parsing line
        auto sub_str_end = find(pos, end, ',');
        x1 = stoi(std::string(pos, sub_str_end));
        pos = sub_str_end+1;

        sub_str_end = find(pos, end, ' ');
        y1 = stoi(std::string(pos, sub_str_end));
        pos = sub_str_end + 4;

        sub_str_end = find(pos, end, ',');
        x2 = stoi(std::string(pos, sub_str_end));
        pos = sub_str_end+1;

        sub_str_end = find(pos, end, '\n');
        y2 = stoi(std::string(pos, sub_str_end));
        pos = sub_str_end+1;

//		cout << "Parsed line : p1 = (" << x1 << "," << y1 << ", p2 = (" << x2 << "," << y2 << ")" << endl;

		/* ===[Map version ~13ms]=== */
		// Horizontal
//		if(y1 == y2){
//			int x_max = max(x1, x2);
//			int x_min = min(x1, x2);
//
//			for(int i = x_min; i <= x_max; i++){
//				int& co = grid[i][y1];
//				co++;
//				if(co == 2)
//					result++;
//			}
//		}
//		// Vertical
//		if(x1 == x2){
//			int y_max = max(y1, y2);
//			int y_min = min(y1, y2);
//
//			for(int i = y_min; i <= y_max; i++){
//				int& co = grid[x1][i];
//				co++;
//				if(co == 2)
//					result++;
//			}
//		}

		/* ===[Array version ~3.2ms]=== */
		if(y1 == y2){
			int x_max = max(x1, x2);
			int x_min = min(x1, x2);

			for(int i = x_min; i <= x_max; i++)
				increaseTile(i, y1, grid, result);
		}
		// Vertical
		if(x1 == x2){
			int y_max = max(y1, y2);
			int y_min = min(y1, y2);

			for(int i = y_min; i <= y_max; i++)
				increaseTile(x1, i, grid, result);
		}
    }

	cout << result << endl;


	// Parsing with sscanf

//	vector<string> lines = AoC::split(input, '\n');
//
//	for(const string& s : lines){
//		sscanf(s.c_str(), "%i,%i -> %i,%i", &x1, &y1, &x2, &y2);
//
//		cout << "Parsed line : p1 = (" << x1 << "," << y1 << ", p2 = (" << x2 << "," << y2 << ")" << endl;
//	}

}