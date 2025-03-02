/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:56:33 by passunca          #+#    #+#             */
/*   Updated: 2025/03/02 11:13:14 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cctype>
#include "Ansi.h"
#include "Logger.hpp"
#include <cstdlib>
#include <ctime>
#include <list>
#include <vector>
#include <iostream>
#include <sstream>

class PmergeMe {
  public:
	PmergeMe(void);
	PmergeMe(const std::list<int> &input);
	PmergeMe(const std::vector<int> &input);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe(void);

	// Public Functions
	int parseArgs(int argc, char **argv);
	void computeExecTime(std::string &container);
	double execTime(std::string &container);

	// Printers
	void logSequences(void);

	// Vector
	void createVectorPairs(void);

  private:
	std::vector<int> _vector;
	std::vector<std::pair<int, int> > _vectorPairs;
	std::list<int> _list;

	// Logging Functions
	void logVec(void);
	void logAuxVec(void);
	void logList(void);
	// Math Stuff
	int jacobsthalGenerator(std::size_t nIdx);
};


/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

#endif

