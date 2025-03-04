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
	if (argc != 2) {
		std::cerr << BRED "Usage: ./PmergeMe <positive int sequence>" NC
				  << std::endl;
		return (EXIT_FAILURE);
	}
	PmergeMe insertMerger;
	if (insertMerger.parseArgs(argc, argv)) {
		std::cerr << BRED "Error: Invalid input sequence." NC << std::endl;
	}
	// Print Sequences before sorting
	insertMerger.logSequences();

	insertMerger.mergeInsertVector();

	
	return (EXIT_SUCCESS);
}
