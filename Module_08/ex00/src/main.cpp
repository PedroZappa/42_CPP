/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:57:01 by passunca          #+#    #+#             */
/*   Updated: 2024/12/14 08:57:02 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <vector>
#include <list>

#define WIDTH 50

int main(void) {
	std::vector<int> vec;
	std::list<int> lst;
	int toSearch = 7;
	int outOfRange = 42;
	int idx = 0;

	headerPrinter("EASYFIND", 50, '-', GRN);
	// Fill containers
	for (int i = 0; i < 10; i++) {
		vec.push_back(i);
		lst.push_back(i);
	}

	// Try Vector
	try {
		std::cout << "Searching for " BBLU << toSearch << NC " on vector" << std::endl;
		idx = easyfind(vec, toSearch);
		std::cout << "Value found at index: " YEL << idx << NC << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	sepPrinter(WIDTH, '-', GRN, 1);
	
	// Try List
	try {
		std::cout << "Searching for " BBLU << outOfRange << NC " on list" << std::endl;
		idx = easyfind(lst, outOfRange);
		std::cout << "Value found at index: " << YEL << idx << NC << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	sepPrinter(WIDTH, '-', GRN, 1);
}

const char *NotFound::what() const throw() {
	return (RED "Value not found" NC);
}

