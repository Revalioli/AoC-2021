#ifndef AOCLIB_AOC_H
#define AOCLIB_AOC_H

#include <vector>
#include <string>
#include <chrono>

namespace AoC{

	// String operations
	/**
	 * \brief Split a string into substring using a specified char delimiter
	 * \param str the string to be split
	 * \param delimiter
	 * \return a vector<string> containing all substrings
	 */
	std::vector<std::string> split(const std::string& str, char delimiter);

	/**
	 * \brief Split a string into substring using a specified char delimiter
	 * \param str the rvalue string to be split
	 * \param delimiter
	 * \return a vector<string> containing all substrings
	 */
	std::vector<std::string> split(const std::string&& str, char delimiter);

	/**
	 * \brief Removes newline characters from the end of a string
	 * \param str the string to be modified
	 * \return the string str
	 */
	std::string& chomp(std::string& str);

	// Vector operations
	/**
	 * \brief Applies a function on all the elements of a vector, and creates a new vector from the results
	 * \tparam ReturnType the return type of the function
	 * \tparam InType the type of the objects in the vector to be mapped
	 * \tparam Functor the type of the Functor object, must have the following operator : ReturnType operator()(InType& obj)
	 * \param vect the vector to be mapped
	 * \param func the functor object with the function to be applied
	 * \return a vector<ReturnType> with the results
	 */
	template<class ReturnType, class InType, class Functor>
	std::vector<ReturnType> map(std::vector<InType>& vect, Functor func);

	/**
	 * \brief Applies a function on all the elements of a vector, and creates a new vector from the results
	 * \tparam ReturnType the return type of the function
	 * \tparam InType the type of the objects in the vector to be mapped
	 * \tparam Functor the type of the Functor object, must have the following operator : ReturnType operator()(InType& obj)
	 * \param vect the rvalue vector to be mapped
	 * \param func the functor object with the function to be applied
	 * \return a vector<ReturnType> with the results
	 */
	template<class ReturnType, class InType, class Functor>
	std::vector<ReturnType> map(std::vector<InType>&& vect, Functor func);

	using func = void(*)(const std::string& input);

	// Benchmark

	/**
	 * \brief Run a time benchmark on a given AoC day part
	 * \tparam DurationType	the time of the duration used (derived from std::chrono::duration)
	 * \param f the function to test, its signature must be void(*)(const std::string& input)
	 * \param input the const string& input to be used
	 * \param samples number of samples to perform
	 * \param unitName the name of the time unit (for text output)
	 * \return the mean execution time of the function
	 */
	template<class DurationType>
	int timeBenchmark(func f, const std::string& input, int samples, const std::string& unitName);


}

#include "AoC.inl"

#endif //AOCLIB_AOC_H
