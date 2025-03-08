/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:56:33 by passunca          #+#    #+#             */
/*   Updated: 2025/03/02 11:28:49 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "Ansi.h"
#include "Logger.hpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <set>
#include <sstream>
#include <vector>

#define WIDTH 50

class PmergeMe {
  public:
	PmergeMe(void);
	PmergeMe(const std::list<int> &input);
	PmergeMe(const std::vector<int> &input);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe(void);

	// Public Functions
	int parseArgs(int argc, char **argv);

	// time
	void computeExecTime(std::string &container);
	double execTime(std::string &container);

	// getters
	int getSize(void) const;

	// Vector
	void mergeInsertVector(void);

	// List
	void mergeInsertList(void);

	// Logging Functions
	//
	void logSequences(void) const;
	void logVec(bool crop) const;
	void logList(bool crop) const;

  private:
	std::vector<int> _vector;
	std::vector<std::vector<int> > _vectorPair;
	std::list<int> _list;
	std::list<std::list<int> > _listPair;

	// Math Stuff
	int jacobsthalGenerator(std::size_t nIdx);
	std::vector<int> generateJacobsthalSequence(const std::vector<int> &pend);
	// Vector
	void createVectorPairs(void);
	void maxValueSortVector(std::vector<std::vector<int> > &pair, int n);
	void insertInSequenceVector(std::vector<std::vector<int> > &pair,
								const std::vector<int> currPair,
								int n);
	std::vector<int> computeInsertionOrder(const std::vector<int> &pend);
	void mergeInsertVectorPairs(std::vector<int> pend, bool isUneven, int lastIdx);
	std::vector<int> createPendVector(void);

	// List
	void createListPairs(void);
	void maxValueSortList(std::list<std::list<int> > &pairs, int n);
	void insertInSequenceList(std::list<std::list<int> > &pairs,
							  std::list<std::list<int> >::iterator currPair,
							  int n);
	std::list<int> createPendList(void);
	void mergeInsertListPairs(std::list<int> pend, bool isUneven, int straggler);
	std::list<std::list<int> >::iterator
	getListIter(std::list<std::list<int> > &pairs, int index);
};

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

#endif
