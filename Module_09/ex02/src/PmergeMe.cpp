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

PmergeMe::PmergeMe(const std::list<int> &input) : _list(input) {
}

PmergeMe::PmergeMe(const std::vector<int> &input) : _vector(input) {
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->_list = other._list;
		this->_vector = other._vector;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void) {
}

/* ************************************************************************** */
/*                                  Parsing                                   */
/* ************************************************************************** */

void PmergeMe::parseArgs(int argc, char **argv) {
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
}

/* ************************************************************************** */
/*                                   Vector                                   */
/* ************************************************************************** */


