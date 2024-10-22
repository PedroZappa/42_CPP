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

void errExit(const std::string &msg);

int main(int argc, char **argv)
{
	Harl harl;
	std::string level;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
		errExit("Wrong number of arguments");
	headerPrinter("Harl 2.0 Filter", 50, '-', BRED);

	return (0);
}

/**
 * @brief Print error message and exit
 * @param msg Error message
*/
void errExit(const std::string &msg)
{
	std::cerr << RED << msg << "\n" NC;
	exit(EXIT_FAILURE);
}
