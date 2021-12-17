#include "Grid.h"
#include <string>
#include "AoC.h"
#include "Tile.h"

using namespace std;

Grid::Grid(const vector<string>& grid_rows) : is_finished(false) {
	reload(grid_rows);
}

void Grid::check(int num) {
	// tiles[row][column]
	for(int row = 0; row < h; row++){
		for(int col = 0; col < w; col++){
			if(tiles[row][col].check(num)){
				row_counters[row]++;
				column_counters[col]++;
				is_finished = (row_counters[row] == h || column_counters[col] == w);
			}
		}
	}
}

void Grid::reset() {
	for(auto& row : tiles){
		for(auto& t : row)
			t.reset();
	}

	row_counters.clear();
	column_counters.clear();
	row_counters.insert(row_counters.end(), w, 0);
	column_counters.insert(column_counters.end(), h, 0);

	is_finished = false;
}

void Grid::reload(const vector<string> &grid_rows) {
	for(vector<Tile>& row : tiles)
		row.clear();

	row_counters.clear();
	column_counters.clear();


	h = grid_rows.size();
	for(int i = 0; i < h; i++){
		const string &s = grid_rows[i];
		vector<string> temp = AoC::split(s, ' ');

		for(int j = 0; j < temp.size(); j++){
			// Removing all empty strings
			if(temp[j].empty()){
				temp.erase(temp.begin()+j);
				j--;
			}
		}

		vector<int> row = AoC::map<int>(temp, [](string s)->int{return stoi(s);});
		tiles.push_back(AoC::map<Tile>(row, [](int num)->Tile{return Tile(num);} ));
	}
	w = tiles[0].size();

	row_counters.insert(row_counters.end(), w, 0);
	column_counters.insert(column_counters.end(), h, 0);

}

void Grid::display() {
	cout << "Displaying grid :" << endl;
	for(auto& row : tiles){
		for(Tile& t : row){
			cout << t.num << ' ';
		}
		cout << endl;
	}
}

int Grid::sum_unchecked() {
	int result = 0;
	for(auto& row : tiles){
		for(auto& t : row)
			if(!t.checked)
				result += t.num;
	}

	return result;
}
