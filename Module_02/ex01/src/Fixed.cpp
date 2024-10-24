/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:04:53 by passunca          #+#    #+#             */
/*   Updated: 2024/10/24 18:05:37 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

const int Fixed::_bits = 8;

/**
 * @brief Constructor
 */
Fixed::Fixed(void) : _value(0)
{
	std::cout << BWHT "Fixed point number";
	std::cout << GRN " created ✅\n" NC;
}

/**
 * @brief Copy Constructor
 */
Fixed::Fixed(const Fixed &copy) : _value(copy._value)
{
	std::cout << BWHT "Fixed point number";
	std::cout << YEL " copied\n" NC;
	*this = copy;
}

/** 
 * @brief Convert int value to fixed point
 * @param value int
 * @details left-shifting multiplies value by 2^_bits
 * */
Fixed::Fixed(const int value)
{
	std::cout << BYEL "int" BWHT "constructor called" NC;
	this->_value = (value << Fixed::_bits);
}

/** 
 * @brief Convert float value to fixed point
 * @param value float
 * @details 
 * */
Fixed::Fixed(const float value)
{
	std::cout << BYEL "float" BWHT "constructor called" NC;
	this->_value = (value * (1 << Fixed::_bits));
}

/**
 * @brief Copy Assignment Operator Overload
 */
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << BWHT "Fixed point number";
	std::cout << MAG " assigned\n" NC;
	if (this != &copy)
		this->_value = copy.getRawBits();

	return (*this);
}

/**
 * @brief Destructor
 */
Fixed::~Fixed(void)
{
	std::cout << BWHT "Fixed point number";
	std::cout << RED " destroyed ❌\n" NC;
}

/**
 * @brief Get Raw Bits
 * @return bits value
 */
int Fixed::getRawBits(void) const
{
	std::cout << "Getting bits:\n" NC;
	return (this->_value);
}

/**
 * @brief Set bits Bits
 * @param raw raw bits value
 */
void Fixed::setRawBits(int const raw)
{
	std::cout << "Setting bits bits:\n" NC;
	this->_value = raw;
}

/**
 * @brief Convert fixed point to float
 * @return float
 */
float Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << Fixed::_bits));
}

/**
 * @brief Convert fixed point to int
 * @return int
 */
int Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_bits);
}

/**
 * @brief Overload the insertion operator
 */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
