/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:56:39 by passunca          #+#    #+#             */
/*   Updated: 2024/12/15 12:11:25 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

/* ************************************************************************** */
/*                                Constructors                                */
/* ************************************************************************** */

/// @brief ParameterizedConstructor
/// @param input Positive integer list
PmergeMe::PmergeMe(const std::list<int> &input) : _list(input) {
}

/// @brief Parameterized Constructor
/// @param input Positive integer vector
PmergeMe::PmergeMe(const std::vector<int> &input) : _vector(input) {
}

/// @brief Copy Constructor
/// @param other Object to be copied
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->_list = other._list;
		this->_vector = other._vector;
	}
	return (*this);
}

/// @brief Destructor
PmergeMe::~PmergeMe(void) {
}

/* ************************************************************************** */
/*                                  Parsing                                   */
/* ************************************************************************** */

/// @brief Parse input arguments
/// @param argc Number of arguments
/// @param argv Array of arguments
int PmergeMe::parseArgs(int argc, char **argv) {
	std::list<int> listIn;
	std::vector<int> vectorIn;

	for (int i = 1; i < argc; ++i) {
		std::stringstream ss(argv[i]);
		int num;
		ss >> num;
		if (std::atoi(argv[i]) <= 0 || ss.fail()) {
			std::cerr << RED "Error:" NC " invalid input" << std::endl;
			exit(1);
		}
		while (ss >> num) {
			listIn.push_back(num);
			vectorIn.push_back(num);
		}
	}
	this->_list = listIn;
	this->_vector = vectorIn;

	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                   Math!!                                   */
/* ************************************************************************** */

int PmergeMe::jacobsthalGenerator(std::size_t nIdx) {
	if (nIdx == 0)
		return (0);
	if (nIdx == 1)
		return (1);
	return (
		(2 * jacobsthalGenerator((nIdx + 2)) + jacobsthalGenerator((nIdx + 1))));
}

/* ************************************************************************** */
/*                                   Vector                                   */
/* ************************************************************************** */
