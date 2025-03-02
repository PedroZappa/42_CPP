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
	for (; jacobsthalNum < pendLen; ++jacobsthalIdx) {
		jacobsthalSequence.push_back(jacobsthalNum);
		jacobsthalNum = jacobsthalGenerator(jacobsthalIdx);
	}
	showContainer(__func__, "jacobsthalSequence", jacobsthalSequence);

	return (jacobsthalSequence);
}

/* ************************************************************************** */
/*                                   Vector                                   */
/* ************************************************************************** */

void PmergeMe::mergeInsertVector(void) {
	bool isUneven = ((_vector.size() % 2) != 0);
	int lastIdx = -1;

	createVectorPairs();
	maxValueSortVector(_vectorPair, _vectorPair.size());
	mergeInsertVectorPairs(createPendVector(), isUneven, lastIdx);
}

/// @brief Create a Vector of pairs and sort them (smaller number first)
void PmergeMe::createVectorPairs(void) {
	Logger::info("PmergeMe::createVectorPairs");
	_vectorPair.clear();
	std::vector<int>::iterator it;
	for (it = _vector.begin(); it < _vector.end(); it += 2) {
		std::vector<int> pair;
		pair.push_back(*it);
		pair.push_back(*(it + 1));
		_vectorPair.push_back(pair);
	}
}

void PmergeMe::maxValueSortVector(std::vector<std::vector<int> > &pair, int n) {
	(void)n;
	(void)pair;
}

void PmergeMe::mergeInsertVectorPairs(std::vector<int> pend,
									  bool isUneven,
									  int lastIdx) {
	(void)pend;
	(void)isUneven;
	(void)lastIdx;
}

/// @brief Create a Vector of pending numbers
/// @return Vector of pending numbers
std::vector<int> PmergeMe::createPendVector(void) {
	_vector.clear();
	std::vector<int> &vector = _vector;
	std::vector<int> pend;

	for (std::size_t i = 0; i < _vectorPair.size(); ++i) {
		vector.push_back(_vectorPair[i][0]);
		pend.push_back(_vectorPair[i][1]);
	}
	return (pend);
}

/* ************************************************************************** */
/*                                   Logger                                   */
/* ************************************************************************** */

/// @brief Log Sequences
void PmergeMe::logSequences(void) {
	showContainer(__func__, "PmergeMe::_vector", _vector);
	showContainer(__func__, "PmergeMe::_list", _list);
}

/// @brief Log Vector Pairs
void PmergeMe::logVecPair(void) {
	std::cout << "_vectorPairs: " << _vectorPair.size() << " pairs: ";
	for (std::size_t i = 0; i < _vectorPair.size(); ++i) {
		std::cout << "[" << _vectorPair[i][0] << ", " << _vectorPair[i][1] << "] ";
	}
	std::cout << std::endl;
}
