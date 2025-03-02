/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:56:39 by passunca          #+#    #+#             */
/*   Updated: 2025/03/02 11:39:27 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

/* ************************************************************************** */
/*                                Constructors                                */
/* ************************************************************************** */

PmergeMe::PmergeMe(void) {
}

/// @brief ParameterizedConstructor
/// @param input Positive integer list
PmergeMe::PmergeMe(const std::list<int> &input) : _list(input) {
	Logger::info("PmergeMe::PmergeMe(const std::list<int> &input)");
}

/// @brief Parameterized Constructor
/// @param input Positive integer vector
PmergeMe::PmergeMe(const std::vector<int> &input) : _vector(input) {
	Logger::info("PmergeMe::PmergeMe(const std::vector<int> &input)");
}

/// @brief Copy Constructor
/// @param other Object to be copied
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->_list = other._list;
		this->_vector = other._vector;
	}
	return (*this);
}

/// @brief Destructor
PmergeMe::~PmergeMe(void) {
	Logger::info("PmergeMe::~PmergeMe()");
}

/* ************************************************************************** */
/*                                  Parsing                                   */
/* ************************************************************************** */

/// @brief Parse input arguments
/// @param argc Number of arguments
/// @param argv Array of arguments
int PmergeMe::parseArgs(int argc, char **argv) {
	Logger::info("PmergeMe::parseArgs()");
	_vector.clear(); // Ensure containers are empty
	_list.clear();   // Before filling

	for (int i = 1; i < argc; ++i) {
		std::stringstream ss(argv[i]);
		if (std::atoi(argv[i]) <= 0 || ss.fail()) {
			std::cerr << RED "Error:" NC " invalid input" << std::endl;
			exit(1);
		}
		int num;
		while (ss >> num) { // Extract number from stringstream
			_list.push_back(num);
			_vector.push_back(num);
		}
	}

	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                   Math!!                                   */
/* ************************************************************************** */

/// @brief Generate the nth jacobsthal number
/// @param nIdx Index of jacobsthal number
/// @return nth jacobsthal number
int PmergeMe::jacobsthalGenerator(std::size_t nIdx) {
	if (nIdx == 0)
		return (0);
	if (nIdx == 1)
		return (1);
	return (
		(2 * jacobsthalGenerator((nIdx + 2)) + jacobsthalGenerator((nIdx + 1))));
}

std::vector<int> PmergeMe::generateJacobsthalSequence(const std::vector<int> &pend) {
	Logger::info("PmergeMe::generateJacobsthalSequence");

	int pendLen = pend.size();
	std::vector<int> jacobsthalSequence;
	std::size_t jacobsthalIdx = 3; // First useful index
	int jacobsthalNum = jacobsthalGenerator(jacobsthalIdx);
	for ( ; jacobsthalNum < pendLen; ++jacobsthalIdx) {
		jacobsthalSequence.push_back(jacobsthalNum);
		jacobsthalNum = jacobsthalGenerator(jacobsthalIdx);
	}
	showContainer(__func__, "jacobsthalSequence", jacobsthalSequence);

	return (jacobsthalSequence);
}


/* ************************************************************************** */
/*                                   Vector                                   */
/* ************************************************************************** */

/// @brief Create a Vector of pairs and sort them (smaller number first)
void PmergeMe::createVectorPairs(void) {
	Logger::info("PmergeMe::createVectorPairs");
	_vectorPairs.clear();

	std::vector<int>::iterator vecIt = _vector.begin();

	while ((vecIt + 1) < _vector.end()) {
		_vectorPairs.push_back(std::make_pair(*vecIt, *(vecIt + 1)));
		if (_vectorPairs.back().first > _vectorPairs.back().second)
			std::swap(_vectorPairs.back().first, _vectorPairs.back().second);
		vecIt += 2;
	}
	if ((_vector.size() % 2) != 0)
		_vectorPairs.push_back(std::make_pair(_vector.back(), -1));
}

/* ************************************************************************** */
/*                                   Logger                                   */
/* ************************************************************************** */

void PmergeMe::logSequences(void) {
	showContainer(__func__, "PmergeMe::_vector", _vector);
	showContainer(__func__, "PmergeMe::_list", _list);
}

void PmergeMe::logPairs(void) {
	showContainer(__func__, "PmergeMe::_vectorPairs", _vectorPairs);
	// showContainer(__func__, "PmergeMe::_listPairs", _listPairs);
}
