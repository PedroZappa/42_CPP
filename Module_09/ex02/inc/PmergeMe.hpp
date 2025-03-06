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
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <sstream>
#include <algorithm>
#include <vector>

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

	// Printers
	void logSequences(void);
	void logVec(void);
	void logPairs(void);

	// Vector
	void mergeInsertVector(void);

  private:
	std::vector<int> _vector;
	std::vector<std::vector<int> > _vectorPair;
	std::list<int> _list;
	std::list<std::list<int> > _listPair;

	// Logging Functions
	void logVecPair(void);
	void logList(void);
	// Math Stuff
	int jacobsthalGenerator(std::size_t nIdx);
	std::vector<int> generateJacobsthalSequence(const std::vector<int> &pend);
	// Vector
	void createVectorPairs(void);
	void maxValueSortVector(std::vector<std::vector<int> > &pair, int n);
	void insertInSequenceVector(std::vector<std::vector<int> > &pair,
								const std::vector<int> currPair,
								int n);
	void mergeInsertVectorPairs(std::vector<int> pend, bool isUneven, int lastIdx);
	std::vector<int> createPendVector(void);
};

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

#endif
