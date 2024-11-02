/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:03:53 by passunca          #+#    #+#             */
/*   Updated: 2024/10/25 20:20:16 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

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
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;
	bool operator>(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	Fixed operator+(const Fixed &rhs);
	Fixed operator-(const Fixed &rhs);
	Fixed operator*(const Fixed &rhs);
	Fixed operator/(const Fixed &rhs);

	Fixed &operator++();
	Fixed operator++(int valuue);
	Fixed &operator--();
	Fixed operator--(int value);

	~Fixed(void);

	/**
	 * @brief Get and Set
	 */
	int getRawBits(void) const;
	void setRawBits(const int raw);

	/**
	 * @brief Convert
	 */
	float toFloat(void) const;
	int toInt(void) const;

	/**
	 * @brief Min and Max
	 * @details Declared as static to indicate that these 
	 * functions belong to the class itself, not to individual objects
	 * */
	static Fixed &min(Fixed &lhs, Fixed &rhs);
	static Fixed &max(Fixed &lhs, Fixed &rhs);
	static const Fixed &min(const Fixed &lhs, const Fixed &rhs);
	static const Fixed &max(const Fixed &lhs, const Fixed &rhs);

  private:
  // Static variables are shared among all instances of the class
  // There is only one _bits variable for all instances
  // _bits determines how to interpret the _value as a fixed-point number
	static const int _bits;
	int _value;
  // Each instance of the class has its own _value
  // Holds the actual value of the fixed-point number
};

/**
 * @brief Overload of the insertion operator
 * @details Conventionally declared outside the class definition allowing it to
 * work with the standard ostream objects like `std::cout` as the left operand.
 * This symmetric design style goes in line with the standard library
 * implementation of stream operators for built-in types
 * */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

