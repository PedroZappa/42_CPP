/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:11:00 by passunca          #+#    #+#             */
/*   Updated: 2024/12/10 11:27:27 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ansi.h"
#include <iostream>
#include <limits>
#include <cstdlib>

typedef enum e_types {
	ERR,
	CHAR,  // 'c', 'a'
	INT,   // 0, 42, -42
	FLOAT, // 0.0f, 42.42f, -42.42f, -inff, +inff, nanf
	DOUBLE // 0.0, -4.2, 4.2, -inf, +inf, nan
} t_types;

class ScalarConverter {
  public:
	static void convert(const std::string &input);

  private:
	// To avoid instantiation
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter(void);

	ScalarConverter &operator=(const ScalarConverter &other);

	// Check Types
	static t_types getType(const std::string &param);
	static bool isChar(const std::string &param);
	static bool isInt(const std::string &param);
	static bool isFloat(const std::string &param);
	static bool isDouble(const std::string &param);

	// Convert Types
	static void convertData(const std::string &param, long double nbr);
	static void convertChar(const std::string &param, char c);
	static void convertInt(const std::string &param, int i);
	static void convertFloat(const std::string &param, float f);
	static void convertDouble(const std::string &param, double d);

	// Check Limits
	static bool isOverflow(const std::string &param, t_types type);

	// Print
	static void printPseudoLiteral(const std::string &param, t_types type);
	static void printInvalidInput(const std::string &param);
};
