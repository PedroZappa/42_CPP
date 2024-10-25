/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:19:18 by passunca          #+#    #+#             */
/*   Updated: 2024/10/25 18:19:21 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

/**
 * @brief Get Triangle Area
 * @param a
 * @param b
 * @param c
 * @return area
 */
Fixed GetTriangleArea(Point a, Point b, Point c)
{
	Fixed area;

	area = ((a.getX() * (b.getY() - c.getY())) +
		(b.getX() * (c.getY() - a.getY())) + 
		(c.getX() * (a.getY() - b.getY()))) / 2;
	return (abs(area));
}

