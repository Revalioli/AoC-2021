#include "Cave.h"

#include <utility>
#include <deque>

Cave::Cave(string name) : _name(std::move(name)) {}

void Cave::connectCave(Cave &c) { neighbors.push_back(&c); }

bool Cave::canBeVisited() { return true; }

int Cave::search_paths(const string& destination, deque<string> call_stack) {
	call_stack.push_back(_name);

	if(_name == destination){	// End of path !

		// Print if end of path
//		cout << "Path : ";
//		for(auto it = call_stack.rbegin(); it != call_stack.rend(); it++)
//			cout << *it << ' ';
//
//		cout << endl;

		return 1;
	}

	// Not end of path, searching for end
	int num_paths = 0;
	for(auto c : neighbors){
		if(c->canBeVisited())
			num_paths += c->search_paths(destination, call_stack);
	}

	call_stack.pop_back();

	return num_paths;
}


TinyCave::TinyCave(const string &name) : Cave(name), wasVisited(false) {}

bool TinyCave::canBeVisited() { return !wasVisited; }

int TinyCave::search_paths(const string& destination, deque<string> call_stack) {
	wasVisited = true;
	int result = Cave::search_paths(destination, call_stack);
	wasVisited = false;

	return result;
}

// ===[ Part 2 ]===

bool TinyCave2::twice_cave = false;

TinyCave2::TinyCave2(const string &name) : Cave(name), visited_count(0), limit(1) {}

bool TinyCave2::canBeVisited() {
	if(visited_count == 1 && !TinyCave2::twice_cave){
		TinyCave2::twice_cave = true;
		return true;
	}

	return visited_count < limit;
}

int TinyCave2::search_paths(const string &destination, deque<string> call_stack) {
	visited_count += 1;
	int result = Cave::search_paths(destination, call_stack);
	visited_count -= 1;

	if(visited_count == 1)
		TinyCave2::twice_cave = false;

	return result;
}
