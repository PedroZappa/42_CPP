/**
 * @defgroup MegaphoneModule Megaphone Application
 * @{
 *
 * This module contains the implementation of a simple command-line application
 * that converts input strings to uppercase, simulating a megaphone effect.
 * It includes functions for capitalizing strings and trimming unwanted characters.
 *
 * @version 1.0
 */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:48:49 by passunca          #+#    #+#             */
/*   Updated: 2024/09/14 14:42:42 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string ft_capitalize(const std::string &str);
std::string ft_trim(const std::string &str, char c);

/**
 * @brief Main function of the Megaphone application.
 * 
 * This function processes command-line arguments, converts them to uppercase,
 * and prints the result. If no arguments are provided, it outputs a default message.
 * 
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return Exit status code.
 */
int main(int argc, char **argv)
{
	std::string out;

	if (argc == 1)
		out += "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int arg = 1; (arg < argc); arg++)
			out.append(ft_capitalize(argv[arg])).append(" ");

	std::cout << out << std::endl;
	return (0);
}

/**
 * @brief Capitalizes all characters in a string after trimming spaces.
 * 
 * This function first trims the input string of leading and trailing spaces
 * and then converts all characters to uppercase.
 * 
 * @param str The input string to be capitalized.
 * @return A new string with all characters in uppercase.
 */
std::string ft_capitalize(const std::string &str)
{
    std::string ret;
    std::string trim = ft_trim(str, ' ');

    for (unsigned int i = 0; i < trim.length(); i++)
		ret += std::toupper(trim[i]);

    return (ret);
}

/**
 * @brief Trims leading and trailing characters from a string.
 * 
 * This function removes specified leading and trailing characters from the input string.
 * 
 * @param str The input string to be trimmed.
 * @param c The character to be trimmed from the string.
 * @return A new string with specified characters trimmed from both ends.
 */
std::string ft_trim(const std::string &str, char c)
{
	size_t str_start = str.find_first_not_of(c);
	size_t str_end = str.find_last_not_of(c);

	// if the string is all spaces, return an empty string
	if (str_start == std::string::npos || str_end == std::string::npos)
		return ("");

	return (str.substr(str_start, (str_end - str_start + 1)));
}

/** @} */

