/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:14:46 by passunca          #+#    #+#             */
/*   Updated: 2024/10/20 18:30:22 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Replace.hpp"
#include <stdexcept>

static void checkArgs(int argc, char **argv);

int main(int argc, char **argv)
{
	try
	{
		checkArgs(argc, argv);
		std::string toReplace = argv[2];
		std::string replaceWith = argv[3];
		std::string in = readFile(argv[1]);
		std::string out  = replace(in, toReplace, replaceWith);
		writeToFile(argv[1], out);
		return (EXIT_SUCCESS);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED "Error: " << e.what() << "\n" NC;
		return (EXIT_FAILURE);
	}
}

static void checkArgs(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << RED "Error: Wrong number of arguments\n" NC;
		throw std::invalid_argument("Wrong number of arguments");
	}
	std::string toCheck = argv[2];
	if (toCheck.empty())
	{
		std::cerr << RED "Error: Empty string\n" NC;
		throw std::invalid_argument("Empty string");
	}
}
