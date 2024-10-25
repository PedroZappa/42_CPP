/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:53:03 by passunca          #+#    #+#             */
/*   Updated: 2024/10/25 20:21:46 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
  public:
	Point(void);
	Point(const Point &copy);
	Point(const Fixed &x, const Fixed &y);
	~Point();

	Point &operator=(const Point &rhs);
	bool operator==(const Point &rhs);

	Fixed getX(void) const;
	Fixed getY(void) const;

  private:
	const Fixed _x;
	const Fixed _y;
};

/**  @brief Overload of the insertion operator */
std::ostream &operator<<(std::ostream &out, const Point &point);
#endif
