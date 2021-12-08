#ifndef AOCLIB_AOC_H
#define AOCLIB_AOC_H

#include <vector>
#include <string>

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

}

#include "AoC.inl"

#endif //AOCLIB_AOC_H
