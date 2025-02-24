/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:56:33 by passunca          #+#    #+#             */
/*   Updated: 2024/12/18 16:47:31 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cctype>
#include "Ansi.h"
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
	void parseArgs(int argc, char **argv);
	void computeExecTime(std::string &container);
	double execTime(std::string &container);

	// Templates for Merging
	template <typename C>
	void mergeSort(C &container);
	template <typename C>
	void merge(C &left, C &right, C &og);

  private:
	std::vector<int> _vector;
	std::list<int> _list;

	// Logging Functions
	void logVec(void);
	void logAuxVec(void);
	void logList(void);
};


/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

#endif

