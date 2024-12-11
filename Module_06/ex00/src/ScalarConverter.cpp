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

//** Convert Types **/
void ScalarConverter::convert(const std::string &input) {
	switch (getType(input)) {
	case CHAR:
		return convertData(input, input[0]);
	case INT:
		return convertData(input, std::atoi(input.c_str()));
	case FLOAT:
		return convertData(input, std::atof(input.c_str()));
	case DOUBLE:
		return convertData(input, std::strtold(input.c_str(), NULL));
	default:
		std::cout << "Invalid input" << std::endl;
		break;
	}
}

void ScalarConverter::convertData(const std::string &param, long double nbr) {
	convertChar(param, static_cast<char>(nbr));
	convertInt(param, static_cast<int>(nbr));
	convertFloat(param, static_cast<float>(nbr));
	convertDouble(param, static_cast<double>(nbr));
}

void ScalarConverter::convertChar(const std::string &param, char c) {
	std::cout << "char: ";
	if (isOverflow(param, CHAR))
		std::cout << "overflow" << std::endl;
	else if (!std::isprint(c))
		std::cout << "non-printable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void ScalarConverter::convertInt(const std::string &param, int i) {
	std::cout << "int: ";
	if (isOverflow(param, INT))
		std::cout << "overflow" << std::endl;
	else
		std::cout << i << std::endl;
}

void ScalarConverter::convertFloat(const std::string &param, float f) {
	std::cout << "float: ";
	if (isOverflow(param, FLOAT))
		std::cout << "overflow" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}

void ScalarConverter::convertDouble(const std::string &param, double d) {
	std::cout << "double: ";
	if (isOverflow(param, DOUBLE))
		std::cout << "overflow" << std::endl;
	else
		std::cout << d << std::endl;
}

/** Check Limits **/
bool ScalarConverter::isOverflow(const std::string &param, t_types type) {
	long double nbr = std::strtold(param.c_str(), NULL);

	switch (type) {
	case CHAR:
		return (nbr < std::numeric_limits<char>::min() ||
				nbr > std::numeric_limits<char>::max());
	case INT:
		return (nbr < std::numeric_limits<int>::min() ||
				nbr > std::numeric_limits<int>::max());
	case FLOAT:
		return (nbr < std::numeric_limits<float>::min() ||
				nbr > std::numeric_limits<float>::max());
	case DOUBLE:
		return (nbr < std::numeric_limits<double>::min() ||
				nbr > std::numeric_limits<double>::max());
	default:
		return (false);
	}
}

// Print
void ScalarConverter::printPseudoLiteral(const std::string &param, t_types type) {
	if (type == CHAR)
		std::cout << "char: invalid" << std::endl;
	if (type == INT)
		std::cout << "int: invalid" << std::endl;

	if (param.find("nan") != std::string::npos) {
		if (type == FLOAT)
			std::cout << "float: nanf" << std::endl;
		if (type == DOUBLE)
			std::cout << "double: nan" << std::endl;
	} else {
		if (type == FLOAT)
			std::cout << "float: " << param[0] << "inff" << std::endl;
		if (type == DOUBLE)
			std::cout << "double: " << param[0] << "inf" << std::endl;
	}
}

void ScalarConverter::printInvalidInput(const std::string &param) {
	std::cout << "Error: Invalid input: " << param << std::endl;
}
