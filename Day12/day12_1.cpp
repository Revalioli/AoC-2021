#include <string>
#include <iostream>
#include <map>
#include "AoC.h"

#include "Cave.h"

using namespace std;

void day12_1(const string& input){
	vector<string> lines = AoC::split(input, '\n', true);

	map<string, Cave*> graph;

	for(const auto& l : lines){
		vector<string> edge = AoC::split(l, '-');
		if(graph.find(edge[0]) == graph.end()){	// Cave doesn't exist

			if(isupper(edge[0].front()))	// Big cave
				graph[edge[0]] = new Cave(edge[0]);
			else	// Smol cave
				graph[edge[0]] = new TinyCave(edge[0]);

		}

		if(graph.find(edge[1]) == graph.end()){	// Cave doesn't exist

			if(isupper(edge[1].front()))	// Big cave
				graph[edge[1]] = new Cave(edge[1]);
			else	// Smol cave
				graph[edge[1]] = new TinyCave(edge[1]);

		}

		graph[edge[0]]->connectCave(*graph[edge[1]]);
		graph[edge[1]]->connectCave(*graph[edge[0]]);

	}

	TinyCave& test = *((TinyCave*)graph["start"]);

	deque<string> call_stack;
	cout << graph["start"]->search_paths("end", call_stack) << endl;

	for(auto& p : graph)
		delete p.second;
}