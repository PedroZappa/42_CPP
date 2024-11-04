/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:43:28 by passunca          #+#    #+#             */
/*   Updated: 2024/10/19 22:09:21 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

static void headerPrinter(void);
static void sepPrinter(void);
static void usage(void);

/**
 * @brief Zombie and Chump creation test
 */
int main(int argc, char **argv) {
	int size;
	(void)argc;

	headerPrinter();
	if (argc > 3) {
		std::cout << RED << "Error: Too many arguments\n";
		usage();
		return (EXIT_FAILURE);
	}
	if (argc <= 2)
	{
		std::cout << RED << "Error: Too few arguments\n";
		usage();
		return (EXIT_FAILURE);
	}
	try {
		size = std::atoi(argv[1]);
		if (size <= 0) {
			throw std::out_of_range("N must be a positive integer");
		}
		if (size > std::numeric_limits<int>::max()) {
			throw std::out_of_range("N is too big");
		}
	} catch (std::out_of_range &e) {
		std::cout << RED << "Error: " << e.what() << "\n";
		usage();
		return (EXIT_FAILURE);
	}

	Zombie *horde = zombieHorde(size, argv[2]);
	for (int i = 0; i < size; i++)
		horde[i].announce();
	sepPrinter();

	delete[] horde;
	return (EXIT_SUCCESS);
}

static void headerPrinter(void) {
	std::cout << GRN;
	std::cout << "=========================" << "\n";
	std::cout << BWHT;
	std::cout << " Zedro's Horde o'Zombies " << "\n";
	std::cout << GRN;
	std::cout << "=========================" << NC << "\n";
}

static void sepPrinter(void) {
	std::cout << GRN;
	std::cout << "=========================" << "\n";
	std::cout << "=========================" << NC << "\n";
}

static void usage(void) {
	std::cout << BYEL "Usage: ";
	std::cout << BWHT "./moarBrainz.out <N> <name>\n" NC;
}
