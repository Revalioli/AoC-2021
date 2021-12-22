#include "AoC.h"

#include <iostream>
#include <sstream>
#include <algorithm>

namespace AoC{

	std::vector<std::string> split(const std::string &str, char delimiter, bool remove_empty) {
//		==== Old implementation with istringstream ===

//		std::istringstream iss(str);
//		std::string buff;
//		std::vector<std::string> result;
//
//		while(getline(iss, buff, delimiter))
//			result.push_back(buff);

//		return result;


//		=== Faster implementation in release mode ===
		std::vector<std::string> result;

		auto stop = str.end();

		for(auto pos = str.begin();; pos++){
			auto start = pos;
			pos = std::find(pos, stop, delimiter);
			if(!remove_empty || start != pos)
				result.emplace_back(start, pos);
			if(pos == stop)
				return result;
		}

	}

	std::vector<std::string> split(const std::string &&str, char delimiter, bool remove_empty) {
		return split(str, delimiter);
	}

	std::string& chomp(std::string &str) {
		if(!str.empty()){
			while (str.back() == '\n' || str.back() == '\r')
				str.erase(str.end()-1);
		}

		return str;
	}
}
