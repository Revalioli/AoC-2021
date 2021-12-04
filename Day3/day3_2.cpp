#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void day3_2(const string& input){
	istringstream iss(input);

	auto * v_0 = new vector<string>();
	auto * v_1 = new vector<string>();
	vector<string> * v_oxy = v_0;
	vector<string> * v_co2 = v_1;

	string buff;
	while (iss >> buff){
		if(buff[0] == '0')
			v_0->push_back(buff);
		else
			v_1->push_back(buff);

		if(v_1->size() >= v_0->size()) {
			v_oxy = v_1;
			v_co2 = v_0;
		}
	}

	int i = 1;
	while(v_oxy->size() > 1){
		vector<string> v_temp_0;
		vector<string> v_temp_1;

		for(const string& elem : *v_oxy){
			if(elem[i] == '0')
				v_temp_0.push_back(elem);
			else
				v_temp_1.push_back(elem);
		}


		if(v_temp_1.size() >= v_temp_0.size()){
			v_oxy->assign(v_temp_1.begin(), v_temp_1.end());
		}
		else{
			v_oxy->assign(v_temp_0.begin(), v_temp_0.end());
		}

		i++;
	}


	i = 1;
	while(v_co2->size() > 1){
		vector<string> v_temp_0;
		vector<string> v_temp_1;

		for(const string& elem : *v_co2){
			if(elem[i] == '0')
				v_temp_0.push_back(elem);
			else
				v_temp_1.push_back(elem);
		}

		if(v_temp_1.size() < v_temp_0.size())
			v_co2->assign(v_temp_1.begin(), v_temp_1.end());
		else
			v_co2->assign(v_temp_0.begin(), v_temp_0.end());

		i++;
	}

	cout << (stoi((*v_co2)[0], nullptr, 2) * stoi((*v_oxy)[0], nullptr, 2)) << endl;
}