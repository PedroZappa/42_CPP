/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:18:37 by passunca          #+#    #+#             */
/*   Updated: 2024/10/23 20:24:52 by passunca         ###   ########.fr       */
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
 * @brief Copy Assignment Operator Overload
 */
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << BWHT "Fixed point number";
	std::cout << MAG " assigned\n" NC;
	if (this != &copy)
		_value = copy.getRawBits();
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
	return (_value);
}

/**
 * @brief Set bits Bits
 * @param raw raw bits value
 */
void Fixed::setRawBits(int const raw)
{
	std::cout << "Setting bits bits:\n" NC;
	_value = raw;
}
