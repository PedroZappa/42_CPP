/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:48:49 by passunca          #+#    #+#             */
/*   Updated: 2024/09/14 13:51:01 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @defgroup CPP_MODULE_00_EX00 megaphone
* @{
*
* @brief		Exercise 00 - megaphone 
* @version		1.0
***/

#include <iostream>	// std::cout, std::endl

std::string ft_capitalize(const std::string &str);
std::string ft_trim(const std::string &str, char c);

/**
* @brief Broadcast the message in all CAPS
* @param str string to be converted to uppercase
* @return SUCCESS(0)
**/
int main(int argc, char **argv)
{
	std::string out;

	if (argc == 1)
		out += "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int word_i = 1; (word_i < argc); word_i++)
			out.append(ft_capitalize(argv[word_i])).append(" ");

	std::cout << out << std::endl;
	return (0);
}

/**
* @brief Capitalize a string
* @param str string to be converted to uppercase
* @return uppercase string
**/
std::string ft_capitalize(const std::string &str)
{
    std::string ret;
    std::string trim = ft_trim(str, ' ');

    for (unsigned int i = 0; i < trim.length(); i++)
		ret += std::toupper(trim[i]);

    return (ret);
}

/**
* @brief Trim a string
* @param str string to be trimmed
* @param c character to trim
* @return trimmed string
**/
std::string ft_trim(const std::string &str, char c)
{
	size_t str_start = str.find_first_not_of(c);
	size_t str_end = str.find_last_not_of(c);

	// if the string is all spaces, return an empty string
	if (str_start == std::string::npos || str_end == std::string::npos)
		return "";

	return (str.substr(str_start, (str_end - str_start + 1)));
}

/** @} */
