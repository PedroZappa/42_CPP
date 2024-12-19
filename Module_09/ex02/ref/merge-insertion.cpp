/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge-insertion.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:38:50 by passunca          #+#    #+#             */
/*   Updated: 2024/12/18 16:56:29 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/** SAUCE :: https://github.com/jlbernardo/cpp/blob/main/09-module/ex02/README.md **/

#include "../inc/Ansi.h"
#include "../inc/PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

#define WIDTH 50

template <typename T>
void printVector(const std::vector<T> &vec, const std::string &label = "Vector");
template <typename T1, typename T2>
void printVector(const std::vector<std::pair<T1, T2>> &vec,
				 const std::string &label = "Vector of Pairs");

int main(int argc, char **argv) {
	headerPrinter("Merge-(Jacobsthal)-Insertion", WIDTH, '=', GRN);
	/** 1. Divide & Conquer **/
	std::vector<int> input = {3, 1, 4, 11, 8, 5, 9, 2, 6, 10, 12, 7, 13};
	int odd = -1;
	printVector(input, "Unsorted vector");

	// Check if vector size is odd or even
	if (input.size() % 2) {
		odd = input.back(); // Store last element (13)
		input.pop_back();   // Pop last element (Remove)
		printf("Vector is Odd, last element popped (%d)\n", odd);
		sepPrinter(WIDTH, '-', GRN, 1);
	}

	// Create a vector of pairs
	std::vector<std::pair<int, int>> pairs;
	typedef std::vector<int>::iterator vectorIter;

	for (vectorIter it = input.begin(); it < input.end(); it += 2) {
		pairs.push_back(std::make_pair(*it, *(it + 1)));
		// pairs = [(3, 1), (4, 11), (8, 5), (9, 2), (6, 10), (12, 7)];
	}
	printVector(pairs, "Vector of Pairs");

	// Sort the vector of pairs, placing the larger number in the first position
	typedef std::vector<std::pair<int, int>>::iterator pairVectorIter;

	printf("Swapping pairs...\n");
	for (pairVectorIter it = pairs.begin(); it < pairs.end(); it++) {
		if (it->first < it->second) {
			std::swap(it->first, it->second);
			printf("Swapping %d with %d\n", it->first, it->second);
		}
	}
	// pairs = [(3, 1), (11, 4), (8, 5), (9, 2), (10, 6), (12, 7)];

	printVector(pairs, "Vector of Pairs after swapping");

	// Sort the vector of pairs be the first element of each pair in ascending order
	printf("Sorting vector of pairs...\n");
	std::sort(pairs.begin(), pairs.end());
	// pairs = [(3, 1), (8, 5), (9, 2), (10, 6), (11, 4), (12, 7)];

	printVector(pairs, "Vector of Pairs after sorting");

	// Create "vector splits", and split the vector of pairs into two vectors
	std::vector<int> main;
	std::vector<int> pend;

	printf("Creating vector splits:\n");
	for (pairVectorIter it = pairs.begin(); it < pairs.end(); it++) {
		main.push_back(it->first);
		pend.push_back(it->second);
	}
	// main = [3, 8, 9, 10, 11, 12];
	// pend = [1, 5, 2, 6, 4, 7];

	printVector(main, "Main vector");

	printVector(pend, "Pend vector");
	sepPrinter(WIDTH, '-', GRN, 1);

	// if input  vector was odd, add the last element to the pend vector
	if (odd != -1)
		pend.push_back(odd);
	else
		printf("Vector is Even, no last element added\n");
	// pend = [1, 5, 2, 6, 4, 7, 13];

	printVector(pend, "Pend vector w/ last element added");

	/** 2. Jacobsthal I choose yoou! **/
	// Generate list of indexes to inform insertion sorting pend into main
	std::vector<int> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	printf("Generating Jacobsthal vector...\n");
	// nextNumber = secondToLast * 2 + last;
	int nextNumber = *(jacobsthal.rbegin() + 1) * 2 + jacobsthal.back();

	while (nextNumber < pend.size()) {
		jacobsthal.push_back(nextNumber);
		nextNumber = *(jacobsthal.rbegin() + 1) * 2 + jacobsthal.back();
	}
	// delete the duplicated 1 from the sequence, as we only need unique indexes
	jacobsthal.erase(jacobsthal.begin() + 1);
	// jacobsthal = [0, 1, 3, 5];

	printVector(jacobsthal, "Jacobsthal vector");

	// Create vector of ints to store the insertion order list
	std::vector<int> insertion;

	// Get the first Jacobsthal number (0) into the insertion vector
	insertion.push_back(jacobsthal.front());

	// Loop for the length of pend
	printf("Inserting order list into insertion vector...\n");
	while (insertion.size() < pend.size()) {
		// Delete the first Jacobsthal number in the vector
		jacobsthal.erase(jacobsthal.begin());

		if (!jacobsthal.empty()) {
			int last = insertion.back(); // Last elem added to insertion vector
			int jacob = jacobsthal.front(); // curr Jacobsthal n being evaluated

			// Add the Jacobsthal number to the insertion vector
			// and decrement to check for missing values
			insertion.push_back(jacob--);

			// while the value of the last index added to insertion vector hasn't been reached
			// AND insertion vector is smaller the pend vector
			while ((jacob > last) && (insertion.size() < pend.size())) {
				std::vector<int>::iterator begin = insertion.begin();
				std::vector<int>::iterator end = insertion.end();

				// Push to insertion vector if curr index wasn't added yet
				if (std::find(begin, end, jacob) == end)
					insertion.push_back(jacob);
				jacob--; // iterate missing numbers in descending order
			}
		}
		// if there are no more jacobsthal numbers left to add
		// AND insertion vector is smaller the pend vector
		// start from the end of the pend vector
		else {
			int missing = (pend.size() - 1);

			while (insertion.size() < pend.size())
				insertion.push_back(missing--);
		}
	}
	// insertion = [0, 1, 3, 2, 5, 4]

	printVector(insertion, "Insertion vector");

	/** 3. Final Insertion Sort **/
	for (std::vector<int>::iterator it = insertion.begin(); it != insertion.end();
		 it++) {
		int value;
		std::vector<int>::iterator position;

		value = pend[*it]; // get the value at the index in the pend vector
		// pend.erase(pend.begin()); // erase the value from the pend vector
		// position: the first element greater then the value in main vector
		position = std::upper_bound(main.begin(), main.end(), value);
		// insert the value before the position found
		main.insert(position, value);
	}
	// main = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13];

	printVector(main, "Sorted Main vector");

	return (0);
}

// Template to print a vector
template <typename T>
void printVector(const std::vector<T> &vec, const std::string &label) {
	std::cout << label << ":\n[";
	for (typename std::vector<T>::const_iterator it = vec.begin();
		 it != vec.end();
		 ++it) {
		std::cout << *it << (it != vec.end() - 1 ? "," : "");
	}
	std::cout << "]\n";
	sepPrinter(WIDTH, '-', GRN, 1);
}

// Specialization to print a vector of pairs
template <typename T1, typename T2>
void printVector(const std::vector<std::pair<T1, T2>> &vec,
				 const std::string &label) {
	std::cout << label << ":\n[";
	for (typename std::vector<std::pair<T1, T2>>::const_iterator it = vec.begin();
		 it != vec.end();
		 ++it) {
		std::cout << "(" << it->first << ", " << it->second << ")"
				  << (it != vec.end() - 1 ? "," : "");
	}
	std::cout << "]\n";
	sepPrinter(WIDTH, '-', GRN, 1);
}
