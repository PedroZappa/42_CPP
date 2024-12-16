/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:56:33 by passunca          #+#    #+#             */
/*   Updated: 2024/12/15 11:56:36 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cctype>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <exception>
#include <sstream>
#include <stdexcept>
#include <vector>

class PmergeMe {
  public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &copy);
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
	std::deque<int> _deque;
};

#endif

