#include "AoC.h"

#include <iostream>
#include <sstream>

namespace AoC{

	std::vector<std::string> split(const std::string &str, char delimiter) {
		std::istringstream iss(str);
		std::string buff;
		std::vector<std::string> result;

		while(getline(iss, buff, delimiter))
			result.push_back(buff);

		return result;
	}

}
