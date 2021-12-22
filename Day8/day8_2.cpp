#include <string>
#include <iostream>
#include <algorithm>

#include "AoC.h"

using namespace std;

/**
 * \brief Finds the commons characters in two digits strings
 * \param s1 digit one
 * \param s2 digit two
 * \return a string of the common chars
 */
string searchCommonChars(const string& s1, const string& s2){
	string commons;
	commons.reserve(7);

	for(const auto& c1 : s1){
		if(s2.find(c1) != string::npos)
			commons.push_back(c1);
	}

	return commons;
}

/**
 * \brief Returns if two digits are the same
 * \param s1 digit one
 * \param s2 digit two
 * \return a boolean
 */
bool equalsDigits(const string& s1, const string& s2){
	if(s1.size() == s2.size())
		return searchCommonChars(s1, s2).size() == s1.size();

	return false;
}

void day8_2(const string& input){

		vector<string> lines = AoC::split(input, '\n', true);
		int accu = 0;

		for(const auto& l : lines){
			vector<string> patterns = AoC::split(l, ' ');	// [0-9] : digits, [11 - 14] : output
			vector<string*> results(10);

			for(int i = 0; i < 10; i++){
				string& digit = patterns[i];
				switch (digit.size()) {
					case 2:		// 1
						results[1] = &digit;
						break;
					case 3:		// 7
						results[7] = &digit;
						break;
					case 4:		// 4
						results[4] = &digit;
						break;
					case 5:		// 2, 3, 5
						if(results[2] == nullptr)
							results[2] = &digit;
						else if(results[3] == nullptr)
							results[3] = &digit;
						else
							results[5] = &digit;
						break;
					case 6:		// 0, 6, 9
						if(results[0] == nullptr)
							results[0] = &digit;
						else if(results[6] == nullptr)
							results[6] = &digit;
						else
							results[9] = &digit;
						break;
					case 7:		// 8
						results[8] = &digit;
						break;
					default:
						cout << "ERROR" << endl;
						exit(EXIT_FAILURE);
				}
			}

			// Searching segment f and digit 6
			string idx_0 = searchCommonChars(*results[1], *results[0]);
			string idx_6 = searchCommonChars(*results[1], *results[6]);
			string idx_9 = searchCommonChars(*results[1], *results[9]);
			char segment_f;

			if(idx_0.size() == 1){
				segment_f = idx_0[0];
				swap(results[0], results[6]);
			} else if (idx_6.size() == 1){
				segment_f = idx_6[0];
			} else {
				segment_f = idx_9[0];
				swap(results[9], results[6]);
			}

			// Searching digit 2

			// Digit 2 has no segment f
			// If there is a match, digit 2 is wrong
			if(results[2]->find(segment_f) != string::npos){
				if(results[3]->find(segment_f) == string::npos)
					swap(results[3], results[2]);
				else
					swap(results[5], results[2]);
			}

			// Sorting digits 3 and 5
			if(searchCommonChars(*results[1], *results[3]).size() != 2)
				swap(results[3], results[5]);

			// Sorting digits 0 and 9
			if(searchCommonChars(*results[4], *results[9]).size() == 3)
				swap(results[0], results[9]);

			// Results
			int result = 0;
			for(auto it = patterns.cbegin()+11; it != patterns.cend(); it++){

				// Searching in results
				result = result * 10
						+ distance(results.begin(), find_if(results.begin(), results.end(), [&it](string* s) -> bool { return equalsDigits(*it, *s); }));

			}
			accu += result;
		}
		cout << accu << endl;
}