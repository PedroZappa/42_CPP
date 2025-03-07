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
    }

    while (memo.size() <= nIdx) {
        int nextVal = memo[memo.size() - 1] * 2 + memo[memo.size() - 2];
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
    std::size_t jacobIdx = 0; // Start from J(0)
    int pendLen = pend.size();

    int jacobValue = jacobsthalGenerator(jacobIdx);
    while (jacobValue < pendLen) {
        jacobsthalSequence.push_back(jacobValue);
        ++jacobIdx;
        jacobValue = jacobsthalGenerator(jacobIdx);
    }

    // Properly print the Jacobsthal sequence
    std::cout << "Jacobsthal Sequence: ";
    for (std::size_t i = 0; i < jacobsthalSequence.size(); ++i)
        std::cout << jacobsthalSequence[i] << " ";
    std::cout << std::endl;

    return jacobsthalSequence;
}

/* ************************************************************************** */
/*                                  Getters                                   */
/* ************************************************************************** */

/// @brief Get the size of the internal vector
/// @return Size of the internal vector
int PmergeMe::getSize(void) const {
	return (_vector.size());
}
/* ************************************************************************** */
/*                                   Vector                                   */
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
	std::vector<int>::iterator it;

	for (it = _vector.begin(); it < _vector.end(); it += 2) {
		std::vector<int> pairs;

		if ((it + 1) == _vector.end()) {
			pairs.push_back(*it); // Single leftover (odd nuumber of elements)
		} else if (*it < *(it + 1)) {
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
/// @param pend Vector of pending numbers
/// @param isUneven Boolean to check if the vector is uneven
/// @param lastIdx The value at the last index
/// Performs merge-insertion sort on the vector of pairs.
void PmergeMe::mergeInsertVectorPairs(std::vector<int> pend,
									  bool isUneven,
									  int straggler) {
	std::vector<int> & S = _vector;
	
	S.insert(S.begin(), pend[0]); // insert first element from pend into S
	std::vector<int> jacobInsertionSequence = generateJacobsthalSequence(pend);
	std::vector<int> indexSequence;
	indexSequence.push_back(1); // first pend element was already added
	bool jacobTurn = true;
	int lastJacob = 0;

	for (size_t insertions = 1; insertions <= pend.size(); insertions++)
	{
		int item = 0;
		if (!jacobInsertionSequence.empty() && jacobTurn)
		{
			indexSequence.push_back(jacobInsertionSequence[0]);
			item = pend[jacobInsertionSequence[0] - 1];
			lastJacob = jacobInsertionSequence[0];
			jacobInsertionSequence.erase(jacobInsertionSequence.begin());
			jacobTurn = false;
		}
		else
		{
			if (std::find(indexSequence.begin(), indexSequence.end(), insertions) != indexSequence.end())
				insertions++;
			if (insertions > pend.size())
				break ;
			item = pend[insertions - 1];
			indexSequence.push_back(insertions);
			if (lastJacob == (static_cast<int>(insertions) + 1))
				jacobTurn = true;
		}
		// std::cout << "Inserting index: " << indexSequence.back() << "\n";
		std::vector<int>::iterator insertionPoint = std::upper_bound(S.begin(), S.end(), item);
		S.insert(insertionPoint, item);
	}
	if (isUneven)
	{
		std::vector<int>::iterator insertionPoint = std::upper_bound(S.begin(), S.end(), straggler);
		S.insert(insertionPoint, straggler);
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
/*                                  Loggers                                   */
/* ************************************************************************** */

/// @brief Log the internal vector
void PmergeMe::logVec(void) {
	for (std::size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::logSequences(void) {
}
