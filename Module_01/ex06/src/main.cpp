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

int main(int argc, char **argv)
{
	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	headerPrinter("Harl 2.0 Filter", 50, '-', BRED);

	if (checkArg(argc, argv) == EXIT_FAILURE)
		return(EXIT_FAILURE);
	
	std::string lvl = argv[1];
	harl.complain(lvl);

	return (0);
}

/**
*	@brief Checks if arg is a valid identifier
*	@param argc Number of arguments
*	@param argv Array of arguments
*	@return EXIT_SUCCESS if arg is valid, EXIT_FAILURE otherwise
* */
static int checkArg(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED "Error: " BWHT "Usage: " YEL "./HarlFilter "
													  "<lvl>\n" NC;
		sepPrinter(WIDTH, '-', RED, 2);
		return (EXIT_FAILURE);
	}
	std::string arg = argv[1];
	if (arg != "DEBUG" && arg != "INFO" && arg != "WARNING" && arg != "ERROR")
	{
		std::cout << RED "Filter Error: " BWHT "Invalid lvl. Use:\n" 
					BYEL "DEBUG || INFO || WARNING || ERROR\n" NC;
		sepPrinter(WIDTH, '-', RED, 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
