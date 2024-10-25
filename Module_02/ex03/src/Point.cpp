/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:08:46 by passunca          #+#    #+#             */
/*   Updated: 2024/10/25 18:33:03 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

/** @brief Default constructor */
Point::Point(void) : _x(0), _y(0) {
}

/** @brief Copy constructor */
Point::Point(const Point &copy) {
	*this = copy;
}

/** @brief Constructor wit Fixed point parameters */
Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y) {
}

/** @brief Destructor */
Point::~Point(void) {
}

/** @brief Overload of the assignment operator */
Point &Point::operator=(const Point &rhs) {
	if (this != &rhs) {
		const_cast<Fixed &>(_x) = rhs._x;
		const_cast<Fixed &>(_y) = rhs._y;
	}
	return (*this);
}

/** @brief Overload of the equality operator */
bool Point::operator==(const Point &rhs) {
	return (_x == rhs._x && _y == rhs._y);
}

/** @brief Get X & Y */
Fixed Point::getX(void) const {
	return (_x);
}
Fixed Point::getY(void) const {
	return (_y);
}
