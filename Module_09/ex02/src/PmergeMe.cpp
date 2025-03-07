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
std::vector<int> PmergeMe::generateJacobsthalSequence(const std::vector<int>& pend) {
    std::vector<int> jacobsthalSequence;
    int pendLen = pend.size();

    // Only generate numbers for pend.size() ≥ 3
    if (pendLen >= 3) {
        std::size_t jacobIdx = 3;
        int jacobValue = jacobsthalGenerator(jacobIdx);
        while (jacobValue < pendLen) {
            jacobsthalSequence.push_back(jacobValue);
            ++jacobIdx;
            jacobValue = jacobsthalGenerator(jacobIdx);
        }
    }

    return jacobsthalSequence;
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

/// @brief Compute the insertion order for a vector of pending numbers
/// @param pend Vector of pending numbers
/// @return Vector of insertion order
std::vector<int> PmergeMe::computeInsertionOrder(const std::vector<int>& pend) {
    std::vector<int> order;
    int p = pend.size();

    if (p <= 2) {
        // Insert all indices sequentially for small pend
        for (int i = 0; i < p; ++i)
            order.push_back(i);
    } else {
        // Generate Jacobsthal sequence
        std::vector<int> jacobSeq = generateJacobsthalSequence(pend);
        int prev = -1; // Start before index 0

        // Insert first element (index 0) explicitly
        order.push_back(0);

        for (size_t j = 0; j < jacobSeq.size(); ++j) {
            int curr = jacobSeq[j];
            // Insert indices in reverse from curr down to prev + 1
            for (int i = curr; i > prev; --i) {
                if (i < p && i != 0) // Avoid re-adding index 0
                    order.push_back(i);
            }
            prev = curr;
        }

        // Add remaining indices (prev + 1 to p-1)
        for (int i = prev + 1; i < p; ++i) {
            if (std::find(order.begin(), order.end(), i) == order.end())
                order.push_back(i);
        }
    }

    return order;
}

/// @brief Merge insertion sort on vector of pairs
/// @param pend Vector of pending numbers
/// @param isUneven Boolean to check if the vector is uneven
/// @param lastIdx The value at the last index
/// Performs merge-insertion sort on the vector of pairs.
void PmergeMe::mergeInsertVectorPairs(std::vector<int> pend,
									  bool isUneven,
									  int straggler) {
	std::vector<int> &S = _vector;

	// Compute insertion order using Jacobsthal sequence
	std::vector<int> insertionOrder = computeInsertionOrder(pend);

	// Insert pending elements into S in the computed order
	for (std::size_t k = 0; k < insertionOrder.size(); ++k) {
		int idx = insertionOrder[k];
		if ((size_t)idx >= pend.size())
			continue;

		int elem = pend[idx];
		std::vector<int>::iterator pos =
			std::upper_bound(S.begin(), S.end(), elem);
		S.insert(pos, elem);
	}

	// Handle straggler element from odd-sized array
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
    std::vector<int> &S = _vector;
    std::vector<int> pend;

    for (std::size_t i = 0; i < _vectorPair.size(); ++i) {
        if (_vectorPair[i].size() >= 2) {
            // S gets the larger element (second in sorted pair)
            S.push_back(_vectorPair[i][1]);
            // Pend gets the smaller element (first in sorted pair)
            pend.push_back(_vectorPair[i][0]);
        } else // Handle odd element (straggler)
            S.push_back(_vectorPair[i][0]);
    }

    return pend;
}

/* ************************************************************************** */
/*                                   List                                     */
/* ************************************************************************** */

/// @brief Perform merge-insert sort on the list
/// Sorts the internal list using a merge-insert algorithm.
void PmergeMe::mergeInsertList(void) {
    bool isUneven = ((_list.size() % 2) != 0);
    int lastIdx = -1;

    if (isUneven) {
        lastIdx = _list.back();
        _list.pop_back();
    }

    createListPairs();
    maxValueSortList(_listPair, _listPair.size());
    mergeInsertListPairs(createPendList(), isUneven, lastIdx);
}

/// @brief Create a list of pairs and sort them
void PmergeMe::createListPairs(void) {
    Logger::info("PmergeMe::createListPairs");
    _listPair.clear();

    std::list<int>::iterator it = _list.begin();
    while (it != _list.end()) {
        std::list<int> pair;
        int first = *it;
        ++it;
        
        if (it != _list.end()) {
            int second = *it;
            if (first < second) {
                pair.push_back(first);
                pair.push_back(second);
            } else {
                pair.push_back(second);
                pair.push_back(first);
            }
            ++it;
        } else {
            pair.push_back(first);
        }
        _listPair.push_back(pair);
    }
}

/// @brief Sort list pairs by their highest value
void PmergeMe::maxValueSortList(std::list<std::list<int> > &pairs, int n) {
    if (n <= 1)
        return;
    maxValueSortList(pairs, n - 1);
    insertInSequenceList(pairs, getListIter(pairs, n - 1), n - 2);
}

/// @brief Insert sort helper for list pairs
void PmergeMe::insertInSequenceList(std::list<std::list<int> > &pairs,
                                   std::list<std::list<int> >::iterator currPair,
                                   int n) {
    if (n >= 0) {
        std::list<std::list<int> >::iterator prevPair = getListIter(pairs, n);
        if ((*prevPair).back() > (*currPair).back()) {
            std::swap(*prevPair, *currPair);
            insertInSequenceList(pairs, prevPair, n - 1);
        }
    }
}

/// @brief Create pend list for merging
std::list<int> PmergeMe::createPendList(void) {
    _list.clear();
    std::list<int> pend;

    for (std::list<std::list<int> >::iterator it = _listPair.begin(); 
        it != _listPair.end(); ++it) {
        
        if (it->size() >= 2) {
            _list.push_back(it->back());
            pend.push_back(it->front());
        } else {
            _list.push_back(it->front());
        }
    }
    return pend;
}

/// @brief Merge-insert list pairs
void PmergeMe::mergeInsertListPairs(std::list<int> pend,
                                   bool isUneven,
                                   int straggler) {
    std::vector<int> insertionOrder = computeInsertionOrder(
        std::vector<int>(pend.begin(), pend.end()));

    for (std::size_t k = 0; k < insertionOrder.size(); ++k) {
        int idx = insertionOrder[k];
        std::list<int>::iterator pendIt = pend.begin();
        std::advance(pendIt, idx);
        
        if (pendIt != pend.end()) {
            std::list<int>::iterator pos = 
                std::upper_bound(_list.begin(), _list.end(), *pendIt);
            _list.insert(pos, *pendIt);
        }
    }

    if (isUneven) {
        std::list<int>::iterator pos = 
            std::upper_bound(_list.begin(), _list.end(), straggler);
        _list.insert(pos, straggler);
    }
}

/// @brief Helper to get iterator at specific position
std::list<std::list<int> >::iterator PmergeMe::getListIter(
    std::list<std::list<int> > &pairs, int index) {
    std::list<std::list<int> >::iterator it = pairs.begin();
    std::advance(it, index);
    return it;
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

void PmergeMe::logList(void) {
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::logSequences(void) {
}
