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
Fixed::Fixed(void) : _value(0) {
	std::cout << BWHT "Fixed point number";
	std::cout << GRN " created ✅\n" NC;
}

/**
 * @brief Copy Constructor
 */
Fixed::Fixed(const Fixed &copy) : _value(copy._value) {
	*this = copy;
	std::cout << BWHT "Fixed point number";
	std::cout << YEL " copied\n" NC;
}

/**
 * @brief Copy Assignment Operator Overload
 */
Fixed &Fixed::operator=(const Fixed &copy) {
	if (this != &copy)
		this->_value = copy.getRawBits();
	std::cout << BWHT "Fixed point number";
	std::cout << MAG " assigned\n" NC;
	return (*this);
}

/**
 * @brief Destructor
 */
Fixed::~Fixed(void) {
	std::cout << BWHT "Fixed point number";
	std::cout << RED " destroyed ❌\n" NC;
}

/**
 * @brief Get Raw Bits
 * @return bits value
 */
int Fixed::getRawBits(void) const {
	return (this->_value);
	std::cout << "Getting bits:\n" NC;
}

/**
 * @brief Set bits Bits
 * @param raw raw bits value
 */
void Fixed::setRawBits(int const raw) {
	this->_value = raw;
	std::cout << "Setting bits bits:\n" NC;
}
