/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:43:28 by passunca          #+#    #+#             */
/*   Updated: 2024/10/19 21:46:37 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

static void	headerPrinter(void);
static void	sepPrinter(void);
static void	exitErr(std::string msg);
static void usage(void);

/**
 * @brief Zombie and Chump creation test
*/
int main(int argc, char **argv) {
	(void)argv;
	int	size;

	headerPrinter();
	if (argc > 3)
		exitErr("Too many arguments");
	else if (argc <= 2)
		exitErr("Too few arguments");
	try
	{
		size = std::atoi(argv[1]);
	}
	catch (std::out_of_range &e)
	{
		exitErr("N value is  out of range");
	}
	
	Zombie *horde = zombieHorde(size, argv[2]);
	for (int i = 0; i < size; i++)
		horde[i].announce();
	sepPrinter();

	delete [] horde;
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

static void	exitErr(std::string msg) {
	std::cout << RED;
	std::cout << "Error: "<< msg << std::endl;
	usage();
	exit(EXIT_FAILURE);
}

static void usage(void) {
	std::cout << BYEL << "Usage: ";
	std::cout << BWHT << "./moarBrainz.out <N> <name>" << NC << std::endl;
}
