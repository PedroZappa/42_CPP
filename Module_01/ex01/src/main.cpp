/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:43:28 by passunca          #+#    #+#             */
/*   Updated: 2024/10/19 20:43:20 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

static void	headerPrinter(void);
static void	sepPrinter(void);

/**
 * @brief Zombie and Chump creation test
*/
int main(int argc, char **argv) {
	(void)argc;
	(void)argv;

	headerPrinter();

	sepPrinter();

	return (EXIT_SUCCESS);
}

static void	headerPrinter(void) {
	std::cout << GRN;
	std::cout << "=========================" << std::endl;
	std::cout << BWHT;
	std::cout << " Zedro's Horde o'Zombies " << std::endl;
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

