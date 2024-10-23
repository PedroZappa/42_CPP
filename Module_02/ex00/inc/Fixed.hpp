/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:01:52 by passunca          #+#    #+#             */
/*   Updated: 2024/10/23 20:21:19 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "Ansi.h"   // For ANSI color codes
#include <iostream> // For std::cout

#define WIDTH 45

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
	Fixed &operator=(const Fixed &copy);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);

  private:
	int _value;
	static const int _bits;
};

void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

#endif
