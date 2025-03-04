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

/// @brief Default constructor
/// Initializes an empty PmergeMe object.
PmergeMe::PmergeMe(void) {
}

/// @brief Parameterized constructor
/// @param input Positive integer list
/// Initializes a PmergeMe object with a list of integers.
PmergeMe::PmergeMe(const std::list<int> &input) : _list(input) {
	Logger::info("PmergeMe::PmergeMe(const std::list<int> &input)");
}

/// @brief Parameterized constructor
/// @param input Positive integer vector
/// Initializes a PmergeMe object with a vector of integers.
PmergeMe::PmergeMe(const std::vector<int> &input) : _vector(input) {
	Logger::info("PmergeMe::PmergeMe(const std::vector<int> &input)");
}

/// @brief Copy assignment operator
/// @param other Object to be copied
/// Copies the contents of another PmergeMe object.
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->_list = other._list;
		this->_vector = other._vector;
	}
	return (*this);
}

/// @brief Destructor
/// Cleans up resources used by the PmergeMe object.
PmergeMe::~PmergeMe(void) {
	Logger::info("PmergeMe::~PmergeMe()");
}

/* ************************************************************************** */
/*                                  Parsing                                   */
/* ************************************************************************** */

/// @brief Parse input arguments
/// @param argc Number of arguments
/// @param argv Array of arguments
/// Parses command-line arguments and fills the internal list and vector.
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

/// @brief Generate the nth Jacobsthal number
/// @param nIdx Index of Jacobsthal number
/// @return nth Jacobsthal number
/// Recursively calculates the Jacobsthal number at a given index.
/// J(n) = 2 * J(n-1) + J(n-2)
int PmergeMe::jacobsthalGenerator(std::size_t nIdx) {
	if (nIdx == 0)
		return (0);
	if (nIdx == 1)
		return (1);
	return (
		(2 * jacobsthalGenerator((nIdx - 1)) + jacobsthalGenerator((nIdx - 2))));
}

/// @brief Generate a sequence of Jacobsthal numbers
/// @param pend Vector of pending numbers
/// @return Vector of Jacobsthal numbers
/// Generates a sequence of Jacobsthal numbers up to the size of the pending vector.
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

/// @brief Perform merge-insert sort on the vector
/// Sorts the internal vector using a merge-insert algorithm.
void PmergeMe::mergeInsertVector(void) {
	bool isUneven = ((_vector.size() % 2) != 0);
	int lastIdx = -1;

	createVectorPairs(); // split vector into pairs & sort pairs in ascending order
	maxValueSortVector(_vectorPair, _vectorPair.size());
	mergeInsertVectorPairs(createPendVector(), isUneven, lastIdx);
	
	showContainer(__func__, "vector", _vector);
}

/// @brief Create a vector of pairs and sort them (smaller number first)
/// Creates pairs from the internal vector and sorts them by the smaller number.
void PmergeMe::createVectorPairs(void) {
	Logger::info("PmergeMe::createVectorPairs");
	_vectorPair.clear();
	std::vector<int>::iterator it;
	for (it = _vector.begin(); it < _vector.end(); it += 2) {
		std::vector<int> pairs;
		if (*it < *(it + 1)) {
			pairs.push_back(*it);
			pairs.push_back(*(it + 1));
		} else {
			pairs.push_back(*(it + 1));
			pairs.push_back(*it);
		}
		_vectorPair.push_back(pairs);
	}
}

/// @brief Sort a vector of pairs by their highest value
/// @param pairs Vector of pairs
/// @param n Number of pairs
/// Sorts the vector of pairs by the highest value in each pairs.
void PmergeMe::maxValueSortVector(std::vector<std::vector<int> > &pairs, int n) {
	if (n <= 1)
		return;
	else {
		maxValueSortVector(pairs, n - 1);
		insertInSequenceVector(pairs, pairs[n - 1], (n - 2));
	}
}

/// @brief Recursively insert sort by highest value in pairs
/// @param pairs Vector of pairs
/// @param currPair Pair to be inserted
/// @param n Index
/// Inserts a pairs into the sorted sequence based on the highest value.
void PmergeMe::insertInSequenceVector(std::vector<std::vector<int> > &pairs,
									  const std::vector<int> currPair,
									  int n) {
	if ((n >= 0) && (pairs[n][1] > currPair[1])) {
		pairs[n + 1] = pairs[n];
		insertInSequenceVector(pairs, currPair, (n - 1));
	} else
		pairs[n + 1] = currPair;
}

/// @brief Merge insertion sort on vector of pairs
/// @param pend Vector of pending numbers
/// @param isUneven Boolean to check if the vector is uneven
/// @param lastIdx The value at the last index
/// Performs merge-insertion sort on the vector of pairs.
void PmergeMe::mergeInsertVectorPairs(std::vector<int> pend,
									  bool isUneven,
									  int lastIdx) {
	std::vector<int> &vector = _vector;

	// Insert 1st element from pend into vector
	vector.insert(vector.begin(), pend[0]);

	std::vector<int> jacobsthalSequence = generateJacobsthalSequence(pend);
	std::vector<int> seqIdx;
	seqIdx.push_back(1);          // 1 because pend element was already added
	bool jacobsthalToggle = true; // Use index from Jacobsthal toggle
	int lastJacobsthal = 0;

	for (std::size_t insert = 1; insert <= pend.size(); ++insert) {
		int elem = 0;
		// Alternate between inserting an element at a Jacobstal-indexed
		// position and the next sequential pending element
		if (!jacobsthalSequence.empty() && jacobsthalToggle) {
			seqIdx.push_back(jacobsthalSequence[0]);
			elem = jacobsthalSequence[0 - 1];
			lastJacobsthal = jacobsthalSequence[0];
			jacobsthalSequence.erase(jacobsthalSequence.begin());
			jacobsthalToggle = false;
		} else {
			if (std::find(seqIdx.begin(), seqIdx.end(), insert) != seqIdx.end())
				++insert;
			if (insert > pend.size())
				break;
			elem = pend[insert - 1];
			seqIdx.push_back(insert);
			if (lastJacobsthal == (static_cast<int>(insert) + 1))
				jacobsthalToggle = true;
		}
		// Ensure correct insertion point
		std::vector<int>::iterator insertLoci =
			std::upper_bound(vector.begin(), vector.end(), elem);
		vector.insert(insertLoci, elem);
	}
	if (isUneven) { // Handle last element if vector is uneven
		std::vector<int>::iterator insertLoci =
			std::upper_bound(vector.begin(), vector.end(), lastIdx);
		vector.insert(insertLoci, lastIdx);
	}
}

/// @brief Create a vector of pending numbers
/// @return Vector of pending numbers
/// Creates a vector of pending numbers from the internal vector pairs.
std::vector<int> PmergeMe::createPendVector(void) {
	_vector.clear();
	std::vector<int> &vector = _vector;
	std::vector<int> pend;

	for (std::size_t i = 0; i < _vectorPair.size(); ++i) {
		vector.push_back(_vectorPair[i][0]);
		pend.push_back(_vectorPair[i][1]);
	}
	showContainer(__func__, "vector", vector);
	showContainer(__func__, "pend", pend);
	return (pend);
}

/* ************************************************************************** */
/*                                  Loggers                                   */
/* ************************************************************************** */

void PmergeMe::logSequences(void) {
	// Logger::info("PmergeMe::logSequences");
	// showContainer(__func__, "vectorPair", _vectorPair);
}
