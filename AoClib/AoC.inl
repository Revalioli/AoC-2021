#ifndef AOCLIB_AOC_INL
#define AOCLIB_AOC_INL

#include <iostream>
#include <chrono>

using clk = std::chrono::steady_clock;
using timePoint = std::chrono::time_point<clk>;

namespace AoC{

	// Vector operations

	template<class ReturnType, class InType, class Functor>
	std::vector<ReturnType> map(std::vector<InType>& vect, Functor func){
		std::vector<ReturnType> results;

		results.reserve(vect.size());	// Allocation of all the needed memory

		for(auto& elem : vect)
			results.push_back(func(elem));

		return results;
	}

	template<class ReturnType, class InType, class Functor>
	std::vector<ReturnType> map(std::vector<InType>&& vect, Functor func){
		return map<ReturnType>(vect, func);
	}

	// Benchmark

	template<class DurationType>
	int timeBenchmark(func f, const std::string& input, int samples, const std::string& unitName){
		timePoint start, end;

		start = clk::now();
		f(input);
		end = clk::now();

		int elapsed_time = std::chrono::duration_cast<DurationType>(end - start).count();
		std::cout << "=== Elapsed time : " << elapsed_time << " " << unitName << std::endl;

		return elapsed_time;
	}
}


#endif