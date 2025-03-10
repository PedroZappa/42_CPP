/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:43:28 by passunca          #+#    #+#             */
/*   Updated: 2024/10/19 12:43:42 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

static void headerPrinter(void);
static void sepPrinter(void);

/**
 * @brief Entry point of the program.
 *
 * This function initializes the program, prompts the user for zombie names,
 * creates a zombie on the heap, and a chump on the stack, then cleans up
 * resources before exiting.
 *
 * @return int Returns EXIT_SUCCESS upon successful execution.
 */
int main(void) {
	std::string zombieName;
	std::string chumpName;
	Zombie *zombie;

	headerPrinter();
	std::cout << YEL "Name a new Zombie: " NC;
	std::getline(std::cin, zombieName);
	std::cout << YEL "Name a new Chump: " NC;
	std::getline(std::cin, chumpName);

	sepPrinter();
	// Allocating in the Heap
	zombie = newZombie(zombieName);
	zombie->announce();
	// Allocating in the Stack
	randomChump(chumpName);

	sepPrinter();
	delete zombie;
	return (EXIT_SUCCESS);
}

/**
 * @brief Prints the header for the program.
 * 
 * This function outputs a decorative header to the console.
 */
static void headerPrinter(void) {
	std::cout << GRN;
	std::cout << "=========================" << std::endl;
	std::cout << BWHT;
	std::cout << "     Zedro's Zombies     " << std::endl;
	std::cout << GRN;
	std::cout << "=========================" << std::endl;
	std::cout << NC;
}

/**
 * @brief Prints a separator line.
 * 
 * This function outputs a decorative separator line to the console.
 */
static void sepPrinter(void) {
	std::cout << GRN;
	std::cout << "=========================" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << NC;
}
