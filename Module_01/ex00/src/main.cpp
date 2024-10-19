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

static void	headerPrinter(void);
static void	sepPrinter(void);

/**
 * @brief Zombie and Chump creation test
*/
int main(void) {
	std::string zombieName;
	std::string chumpName;
	Zombie *zombie;

	headerPrinter();
	std::cout << YEL << "Name a new Zombie: " << NC;
	std::getline(std::cin, zombieName);
	std::cout << YEL << "Name a new Chump: " << NC;
	std::getline(std::cin, chumpName);
	
	sepPrinter();
	zombie = newZombie(zombieName);
	zombie->announce();
	randomChump(chumpName);

	sepPrinter();
	delete zombie;
	return (EXIT_SUCCESS);
}

static void	headerPrinter(void) {
	std::cout << GRN;
	std::cout << "=========================" << std::endl;
	std::cout << BWHT;
	std::cout << "     Zedro's Zombies     " << std::endl;
	std::cout << GRN;
	std::cout << "=========================" << std::endl;
	std::cout << NC;
}

static void	sepPrinter(void) {
	std::cout << GRN;
	std::cout << "=========================" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << NC;
}
