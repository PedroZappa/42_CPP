/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:42:59 by passunca          #+#    #+#             */
/*   Updated: 2025/03/02 11:29:04 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int argc, char **argv) {
	// Parse input arguments
	if (argc < 2) {
		std::cerr << BRED "Usage: ./PmergeMe <positive int sequence>" NC
				  << std::endl;
		return (EXIT_FAILURE);
	}
	PmergeMe insertMerger;
	if (insertMerger.parseArgs(argc, argv)) {
		std::cerr << BRED "Error: Invalid input sequence." NC << std::endl;
	}
	// Print Sequences before sorting
	std::cout << YEL "Vector Before\t: " NC;
	insertMerger.logVec();

	std::cout << YEL "List Before\t: " NC;
	insertMerger.logList();

	// Time merge sort
	std::clock_t start = std::clock();
	insertMerger.mergeInsertVector();
	std::clock_t end = std::clock();
	double elapsedVector =
		(static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000);
	// Time list sort
	start = std::clock();
	insertMerger.mergeInsertList();
	end = std::clock();
	double elapsedList =
		(static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000);
	
	sepPrinter(WIDTH, '=', BBLU, 1);
	
	// Print results
	std::cout << YEL "Vector After\t: " NC;
	insertMerger.logVec();

	std::cout << YEL "List After\t: " NC;
	insertMerger.logList();

	std::cout << "Range of " BRED << insertMerger.getSize() << NC;
	std::cout << " elements in" BBLU " std::vector" NC << " sorted in: ";
	std::cout << BGRN << elapsedVector << "µs" NC << std::endl;
	
	std::cout << "Range of " BRED << insertMerger.getSize() << NC;
	std::cout << " elements in" BBLU " std::list" NC << " sorted in: ";
	std::cout << BGRN << elapsedList << "µs" NC << std::endl;

	return (EXIT_SUCCESS);
}
