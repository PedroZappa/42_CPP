/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:04:12 by passunca          #+#    #+#             */
/*   Updated: 2024/10/24 18:06:34 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "Ansi.h"   // For ANSI color codes
#include <iostream> // For std::cout

/**
 * @brief Class Fixed
 * @details
 * A class that represents a fixed-point number
 * with '_bits' bits of precision
 */
class Fixed
{
  public:
	Fixed(void);
	Fixed(const Fixed &copy);
	Fixed(const int value);
	Fixed(const float value);
	Fixed &operator=(const Fixed &copy);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(const int raw);

	float toFloat(void) const;
	int toInt(void) const;

  private:
	static const int _bits;
	int _value;
};

/**
 * @brief Overload of the insertion operator
 * @details Conventionally declared outside the class definition allowing it to
 * work with the standard ostream objects like `std::cout` as the left operand.
 * This symmetric design style goes in line with the standard library
 * implementation of stream operators for built-in types
 * */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

/** UI Helpers **/
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

#endif
