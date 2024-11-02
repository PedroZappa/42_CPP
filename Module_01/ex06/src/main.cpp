/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:12:59 by passunca          #+#    #+#             */
/*   Updated: 2024/10/22 14:38:18 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"
#include <cstdlib>

static int checkArg(int argc, char **argv);

int main(int argc, char **argv) {
	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	headerPrinter("Harl 2.0 Filter", 50, '-', BRED);

	if (checkArg(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	std::string level = argv[1];
	int index = -1;
	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			index = i;

	switch (index) {
	default:
		std::cout << BWHT "[ Who knows, probably complaining about stuff "
						  "]\n" NC;
		break;
	case DEBUG:
		harl.complain(levels[index++]);
		// fall through
	case INFO:
		harl.complain(levels[index++]);
		// fall through
	case WARNING:
		harl.complain(levels[index++]);
		// fall through
	case ERROR:
		harl.complain(levels[index]);
		// fall through
	}

	return (0);
}

/**
 *	@brief Checks if arg is a valid identifier
 *	@param argc Number of arguments
 *	@param argv Array of arguments
 *	@return EXIT_SUCCESS if arg is valid, EXIT_FAILURE otherwise
 * */
static int checkArg(int argc, char **argv) {
	if (argc != 2) {
		std::cout << RED "Error: " BWHT "Usage: " YEL "./HarlFilter "
						 "<lvl>\n" NC;
		sepPrinter(WIDTH, '-', RED, 2);
		return (EXIT_FAILURE);
	}
	std::string arg = argv[1];
	if (arg != "DEBUG" && arg != "INFO" && arg != "WARNING" && arg != "ERROR") {
		std::cout << BWHT "[ Who knows, probably complaining about stuff "
						  "]\n" NC;
		sepPrinter(WIDTH, '-', RED, 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
