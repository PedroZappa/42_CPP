/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:45:30 by passunca          #+#    #+#             */
/*   Updated: 2025/03/08 17:45:32 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.cpp
 * @brief This file contains the main function to demonstrate the usage of the easyfind function.
 * 
 * The program fills a vector and a list with integers and attempts to find specific values using the easyfind function.
 * It demonstrates exception handling when a value is not found.
 * 
 * @author passunca
 * @date 2024-12-14
 */

#include "../inc/easyfind.hpp"
#include <vector>
#include <list>

#define WIDTH 50

/**
 * @brief Main function to demonstrate the easyfind function.
 * 
 * This function fills a vector and a list with integers from 0 to 9.
 * It then attempts to find a specific value in each container and prints the result.
 * If the value is not found, an exception is caught and an error message is displayed.
 * 
 * @return int Returns 0 on successful execution.
 */
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

/**
 * @brief Exception message for when a value is not found.
 * 
 * This function overrides the what() method to provide a custom error message
 * when a value is not found in the container.
 * 
 * @return const char* The error message.
 */
const char *NotFound::what() const throw() {
	return (RED "Value not found" NC);
}

