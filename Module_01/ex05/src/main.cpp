/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:51:04 by passunca          #+#    #+#             */
/*   Updated: 2024/10/22 12:20:05 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

static int checkArg(int argc, char **argv);

/**
*	@brief Harl 2.0
*	@param argc Number of arguments
*	@param argv Array of arguments
*	@return EXIT_SUCCESS if all goes well, EXIT_FAILURE otherwise
* */
int main(int argc, char **argv)
{
	Harl harl;

	headerPrinter("HarlFilter", WIDTH, '-', RED);
	
	if (checkArg(argc, argv) == 1)
		return (EXIT_FAILURE);

	harl.complain(argv[1]);
	sepPrinter(WIDTH, '-', GRN, 2);

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
													  "<level>\n" NC;
		sepPrinter(WIDTH, '-', RED, 2);
		return (EXIT_FAILURE);
	}
	std::string arg = argv[1];
	if (arg != "DEBUG" && arg != "INFO" && arg != "WARNING" && arg != "ERROR")
	{
		std::cout << RED "Filter Error: " BWHT "Invalid level. Use:\n" 
					BYEL "DEBUG || INFO || WARNING || ERROR\n" NC;
		sepPrinter(WIDTH, '-', RED, 2);
		return (FAILURE);
	}
	return (SUCCESS);
}
