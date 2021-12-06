#ifndef AOCLIB_AOC_INL
#define AOCLIB_AOC_INL

namespace AoC{

	template<class ReturnType, class InType, class Functor>
	std::vector<ReturnType> map(std::vector<InType>& vect, Functor func){
		std::vector<ReturnType> results;
		results.reserve(vect.size());	// Allocation of all the needed memory

		for(auto& elem : vect)
			results.push_back(func(elem));

		return results;
	}

}


#endif