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

typedef enum e_types {
	ERR,
	CHAR,  // 'c', 'a'
	INT,   // 0, 42, -42
	FLOAT, // 0.0f, 42.42f, -42.42f, -inff, +inff, nanf
	DOUBLE // 0.0, -4.2, 4.2, -inf, +inf, nan
} t_types;

class ScalarConverter {
  public:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter(void);

	ScalarConverter &operator=(const ScalarConverter &other);

  private:
	static void convert(const std::string &input);
};
