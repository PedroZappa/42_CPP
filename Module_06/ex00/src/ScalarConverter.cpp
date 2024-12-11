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
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
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

bool ScalarConverter::isInt(const std::string &param) {
	size_t i = 0;
	if (param[0] == '-' || param[0] == '+') // Support for signednumbers
		++i;
	while (param[i]) // Check for digits
		if (!std::isdigit(param[i++]))
			return (false);
	return (true);
}

bool ScalarConverter::isFloat(const std::string &param) {
	size_t i = 0;
	if (param[0] == '-' || param[0] == '+') // Support for signed numbers
		++i;

	size_t dot_i = param.find('.'); // Find dot index
	size_t f_i = param.find('f');   // Find 'f' index
	if ((dot_i == std::string::npos) || (f_i != std::string::npos) ||
		(f_i != param.length() - 1)) // No dot
		return (false);
	// Find decimal and floating parts
	std::string int_part = param.substr(i, dot_i - i);
	std::string frac_part = param.substr((dot_i + 1), (f_i - dot_i - 1));
	if (int_part.empty() || frac_part.empty()) // Empty parts
		return (false);
	// Check if integral and decimal parts are digits
	for (size_t idx = 0; idx < int_part.length(); ++idx)
		if (!std::isdigit(int_part[idx]))
			return (false);
	for (size_t idx = 0; idx < frac_part.length(); ++idx)
		if (!std::isdigit(frac_part[idx]))
			return (false);
	return (true);
}

bool ScalarConverter::isDouble(const std::string &param) {
	size_t i = 0;
	if (param[i] == '+' || param[i] == '-')
		++i;

	size_t dot_i = param.find('.');
	if (dot_i == std::string::npos)
		return (false);

	std::string int_part = param.substr(i, (dot_i - i));
	std::string frac_part =
		param.substr((dot_i + 1), (param.length() - dot_i - 1));
	if (int_part.empty() || frac_part.empty())
		return (false);

	for (size_t idx = 0; idx < int_part.length(); ++idx)
		if (!std::isdigit(int_part[idx]))
			return (false);
	for (size_t idx = 0; idx < frac_part.length(); ++idx)
		if (!std::isdigit(frac_part[idx]))
			return (false);
	return (true);
}

//** Convertion Functions **/
//
//
