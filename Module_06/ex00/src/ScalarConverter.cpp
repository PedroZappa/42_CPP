/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:29:25 by passunca          #+#    #+#             */
/*   Updated: 2024/12/10 11:30:22 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

/** Default Constructor */
ScalarConverter::ScalarConverter(void) {
#ifdef DEBUG
	std::cout << "ScalarConverter Default Constructor" << std::endl;
#endif
}

/** Copy Constructor */
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
#ifdef DEBUG
	std::cout << "ScalarConverter Copy Constructor" << std::endl;
#endif
	*this = other;
}

/** Destructor */
ScalarConverter::~ScalarConverter(void) {
#ifdef DEBUG
	std::cout << "ScalarConverter Destructor" << std::endl;
#endif
}

/** Assignment Operator */
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this == &other)
		return (*this);
	*this = other;
	return (*this);
}

/** Check Types **/
t_types ScalarConverter::getType(const std::string &param) {
	if (isChar(param) == 1)
		return (CHAR);
	else if (isInt(param) == 1)
		return (INT);
	else if (isFloat(param) == 1)
		return (FLOAT);
	else if (isDouble(param) == 1)
		return (DOUBLE);
	else
		return (ERR);
}

bool ScalarConverter::isChar(const std::string &param) {
	if (param.size() != 1) // String size must be 1
		return (false);
	if (!std::isprint(param[0])) // Check if char is printable
		return (false);
	if (std::isdigit(param[0])) // Check if char is a digit
		return (false);
	return (true);
}
