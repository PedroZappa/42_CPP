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
	_vector.clear();
	_list.clear();

	for (int i = 1; i < argc; ++i) {
		std::stringstream ss(argv[i]);
		int num;

		// Extract integers from the argument
		while (ss >> num) {
			if (num <= 0) {
				std::cerr << RED "Error:" NC " invalid input (" << num << ")"
						  << std::endl;
				exit(1);
			}
			_list.push_back(num);
			_vector.push_back(num);
		}

		// Check for invalid characters after the numbers
		if (!ss.eof()) {
			std::cerr << RED "Error:" NC " invalid input (non-integer "
							 "characters detected)"
					  << std::endl;
			exit(1);
		}
	}

	return EXIT_SUCCESS;
}

/* ************************************************************************** */
/*                                   Math!!                                   */
/* ************************************************************************** */

/// @brief Generate the nth Jacobsthal number
/// @param nIdx Index of Jacobsthal number
/// @return nth Jacobsthal number
/// Generates the nth Jacobsthal number using memoization.
int PmergeMe::jacobsthalGenerator(std::size_t nIdx) {
	static std::vector<int> memo; // Memoization to store computed Jacobsthal numbers
	if (memo.empty()) {
		memo.push_back(0); // J(0) = 0
		memo.push_back(1); // J(1) = 1
		memo.push_back(1); // J(2) = 1
	}

	while (memo.size() <= nIdx) {
		int nextVal = memo[memo.size() - 1] + 2 * memo[memo.size() - 2];
		memo.push_back(nextVal); // J(n) = J(n-1) * 2 + J(n-2)
	}

	return memo[nIdx];
}

/// @brief Generate a sequence of Jacobsthal numbers
/// @param pend Vector of pending numbers
/// @return Vector of Jacobsthal numbers
/// Generates a sequence of Jacobsthal numbers up to the size of the pending vector.
std::vector<int> PmergeMe::generateJacobsthalSequence(const std::vector<int> &pend) {
	Logger::info("PmergeMe::generateJacobsthalSequence");
	std::vector<int> jacobsthalSequence;

	int pendLen = pend.size();

	// In the Ford–Johnson algorithm the first insertion index we care about is J(3)=3.
	// For pend arrays too small (pend.size() <= 2), we want to force a 3.
	if (pendLen <= 2)
		jacobsthalSequence.push_back(3);
	else {
		std::size_t jacobIdx = 3; // Start w/ J(3)
		int jacobValue =
			jacobsthalGenerator(jacobIdx); // should be 3 for jacobIdx==3
		// We add Jacobsthal numbers that are strictly less than pendLen.
		while (jacobValue < pendLen) {
			jacobsthalSequence.push_back(jacobValue);
			++jacobIdx;
			jacobValue = jacobsthalGenerator(jacobIdx);
		}
	}
	// Print sequence
	std::cout << "Jacobsthal Sequence: ";
	for (std::size_t i = 0; i < jacobsthalSequence.size(); ++i)
		std::cout << jacobsthalSequence[i] << " ";
	std::cout << std::endl;

	return (jacobsthalSequence);
}

/* ************************************************************************** */
/*                                  Getters */
/* ************************************************************************** */

/// @brief Get the size of the internal vector
/// @return Size of the internal vector
int PmergeMe::getSize(void) const {
	return (_vector.size());
}
/* ************************************************************************** */
/*                                   Vector */
/* ************************************************************************** */

/// @brief Perform merge-insert sort on the vector
/// Sorts the internal vector using a merge-insert algorithm.
void PmergeMe::mergeInsertVector(void) {
	bool isUneven = ((_vector.size() % 2) != 0);
	int lastIdx = -1;

	if (isUneven) {
		lastIdx = _vector.back(); // store last element explicitly
		_vector.pop_back();       // remove it temporarily from vector
	}

	createVectorPairs(); // split vector into pairs & sort pairs in ascending order
	maxValueSortVector(_vectorPair, _vectorPair.size());
	mergeInsertVectorPairs(createPendVector(), isUneven, lastIdx);
}

/// @brief Create a vector of pairs and sort them (smaller number first)
/// Creates pairs from the internal vector and sorts them by the smaller number.
void PmergeMe::createVectorPairs(void) {
	Logger::info("PmergeMe::createVectorPairs");
	_vectorPair.clear();

	for (std::size_t i = 0; i < _vector.size(); i += 2) {
		std::vector<int> pair;

		if (i + 1 < _vector.size()) { // If there are two elements
			if (_vector[i] < _vector[i + 1]) {
				pair.push_back(_vector[i]);
				pair.push_back(_vector[i + 1]);
			} else {
				pair.push_back(_vector[i + 1]);
				pair.push_back(_vector[i]);
			}
		} else { // If there’s only one element left (odd case)
			pair.push_back(_vector[i]);
		}

		_vectorPair.push_back(pair);
	}
}

/// @brief Sort a vector of pairs by their highest value
/// @param pairs Vector of pairs
/// @param n Number of pairs
/// Sorts the vector of pairs by the highest value in each pairs.
void PmergeMe::maxValueSortVector(std::vector<std::vector<int> > &pairs, int n) {
	if (n <= 1)
		return;
	maxValueSortVector(pairs, (n - 1));
	insertInSequenceVector(pairs, pairs[n - 1], (n - 2));
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
		pairs[n + 1] = pairs[n]; // Shift pair to the right
		insertInSequenceVector(
			pairs, currPair, (n - 1)); // Check pair to the left
	} else
		pairs[n + 1] = currPair; // Insert currPair in its right place
}

/// @brief Merge insertion sort on vector of pairs

std::vector<int> PmergeMe::computeInsertionOrder(const std::vector<int> &pend) {
	std::vector<int> order;
	int p = pend.size();
	if (p < 3) {
		for (int i = 0; i < p; i++)
			order.push_back(i);
	} else {
		std::vector<int> jacobSeq = generateJacobsthalSequence(pend);
		int prev = 0;
		for (std::size_t j = 0; j < jacobSeq.size(); ++j) {
			int curr = jacobSeq[j];
			// Add indices in reverse order: from curr down to prev+1.
			for (int i = curr; i > prev; --i) {
				order.push_back(i);
			}
			prev = curr;
		}
		// Append any remaining indices
		for (int i = prev; i < p; i++) {
			order.push_back(i);
		}
	}
	return order;
}

/// @param pend Vector of pending numbers
/// @param isUneven Boolean to check if the vector is uneven
/// @param lastIdx The value at the last index
/// Performs merge-insertion sort on the vector of pairs.
void PmergeMe::mergeInsertVectorPairs(std::vector<int> pend,
									  bool isUneven,
									  int straggler) {
	std::vector<int> &S = _vector;
	// Assume the main chain S (the "vector") is already built (from the pairs)
	// Insert pending elements into S in the computed order.
	std::vector<int> insertionOrder = computeInsertionOrder(pend);
	for (std::size_t k = 0; k < insertionOrder.size(); ++k) {
		int idx = insertionOrder[k];
		if ((size_t)idx >= pend.size())
			continue;
		int elem = pend[idx];
		std::vector<int>::iterator pos =
			std::upper_bound(S.begin(), S.end(), elem);
		S.insert(pos, elem);
	}
	// If there is a "straggler" element from an odd-sized array, insert it last.
	if (isUneven) {
		std::vector<int>::iterator pos =
			std::upper_bound(S.begin(), S.end(), straggler);
		S.insert(pos, straggler);
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
		vector.push_back(_vectorPair[i][0]); // Always safe to push first element
		// Check if there's a second element before accessing it!
		if (_vectorPair[i].size() == 2 && _vectorPair[i][1] > 0)
			pend.push_back(_vectorPair[i][1]);
	}

	// Print Created Vector
	std::cout << "Vector\t: ";
	for (std::size_t i = 0; i < vector.size(); ++i)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
	// Print Created Pend Vector
	std::cout << "Pend\t: ";
	for (std::size_t i = 0; i < pend.size(); ++i)
		std::cout << pend[i] << " ";
	std::cout << std::endl;

	return (pend);
}

/* ************************************************************************** */
/*                                  Loggers */
/* ************************************************************************** */

/// @brief Log the internal vector
void PmergeMe::logVec(void) {
	for (std::size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::logSequences(void) {
}
