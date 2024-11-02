/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:11:24 by passunca          #+#    #+#             */
/*   Updated: 2024/10/25 20:28:25 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bsp.hpp"

const int Fixed::_bits = 8;

/**
 * @brief Constructor
 */
Fixed::Fixed(void) : _value(0) {
}

/**
 * @brief Copy Constructor
 */
Fixed::Fixed(const Fixed &copy) : _value(copy._value) {
	*this = copy;
}

/**
 * @brief Convert int value to fixed point
 * @param value int
 * @details left-shifting multiplies value by 2^_bits
 * */
Fixed::Fixed(const int value) {
	this->_value = (value << Fixed::_bits);
}

/**
 * @brief Convert float value to fixed point
 * @param value float
 * @details
 * */
Fixed::Fixed(const float value) {
	this->_value = (value * (1 << Fixed::_bits));
}

/**
 * @brief Copy Assignment Operator Overload
 */
Fixed &Fixed::operator=(const Fixed &copy) {
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

/** @brief Equality Operator Overload */
bool Fixed::operator==(const Fixed &rhs) const {
	return (this->_value == rhs.getRawBits());
}

/** @brief Inequality Operator Overload */
bool Fixed::operator!=(const Fixed &rhs) const {
	return (this->_value != rhs.getRawBits());
}

/** @brief Greater than Operator Overload */
bool Fixed::operator>(const Fixed &rhs) const {
	return (this->_value > rhs.getRawBits());
}

/** @brief Greater than or equal to Operator Overload */
bool Fixed::operator>=(const Fixed &rhs) const {
	return (this->_value >= rhs.getRawBits());
}

/** @brief Less than Operator Overload */
bool Fixed::operator<(const Fixed &rhs) const {
	return (this->_value < rhs.getRawBits());
}

/** @brief Less than or equal to Operator Overload */
bool Fixed::operator<=(const Fixed &rhs) const {
	return (this->_value <= rhs.getRawBits());
}

/** @brief Add Operator Overload */
Fixed Fixed::operator+(const Fixed &rhs) {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

/** @brief Subtract Operator Overload */
Fixed Fixed::operator-(const Fixed &rhs) {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

/** @brief Multiply Operator Overload */
Fixed Fixed::operator*(const Fixed &rhs) {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

/** @brief Divide Operator Overload */
Fixed Fixed::operator/(const Fixed &rhs) {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

/** @brief Prefix Increment Operator Overload */
Fixed &Fixed::operator++() {
	this->_value++;
	return (*this);
}

/** @brief Postfix Increment Operator Overload */
Fixed Fixed::operator++(int value) {
	(void)value;
	Fixed buf = Fixed(*this);
	this->_value++;
	return (buf);
}

/** @brief Prefix Decrement Operator Overload */
Fixed &Fixed::operator--() {
	this->_value--;
	return (*this);
}

/** @brief Postfix Decrement Operator Overload */
Fixed Fixed::operator--(int value) {
	(void)value;
	Fixed buf = *this;
	this->_value--;
	return (buf);
}

/**
 * @brief Destructor
 */
Fixed::~Fixed(void) {
}

/**
 * @brief Get Raw Bits
 * @return bits value
 */
int Fixed::getRawBits(void) const {
	return (this->_value);
}

/**
 * @brief Set bits Bits
 * @param raw raw bits value
 */
void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

/**
 * @brief Convert fixed point to float
 * @return float
 */
float Fixed::toFloat(void) const {
	return (static_cast<float>(this->_value) / (1 << Fixed::_bits));
}

/**
 * @brief Convert fixed point to int
 * @return int
 */
int Fixed::toInt(void) const {
	return (this->_value >> Fixed::_bits);
}

/**
 * @brief Overload the insertion operator
 */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}

/**
 * @brief Get Minimum
 * @param lhs
 * @param rhs
 * @details
 * Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) => Static member function
 */
Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) {
	return ((lhs < rhs) ? lhs : rhs);
}

const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs) {
	return ((lhs < rhs) ? lhs : rhs);
}

/**
 * @brief Get Maximum
 * @param lhs
 * @param rhs
 * @return
 */
Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) {
	return ((lhs > rhs) ? lhs : rhs);
}

const Fixed &Fixed::max(const Fixed &lhs, const Fixed &rhs) {
	return ((lhs > rhs) ? lhs : rhs);
}
