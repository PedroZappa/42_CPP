/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:39:32 by passunca          #+#    #+#             */
/*   Updated: 2024/10/25 18:52:27 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

static Fixed GetTriangleArea(Point a, Point b, Point c);

/**
 * @brief Check if point is within triangle
 * @param a triangle vertice
 * @param b triangle vertice
 * @param c triangle vertice
 * @param point to check
 * @return true
 * @return false
 */
bool bsp(const Point &a, const Point &b, const Point &c, const Point &point) {
	Fixed ABC = GetTriangleArea(a, b, c);

	Fixed PAB = GetTriangleArea(point, a, b);
	Fixed PAC = GetTriangleArea(point, a, c);
	Fixed PBC = GetTriangleArea(point, b, c);

	bool isWithin = (ABC == (PAB + PAC + PBC));

	bool isOnEdge =
		((PAB.toFloat() == 0) && (PAC.toFloat() == 0) && (PBC.toFloat() == 0));

	return (isWithin && isOnEdge);
}

/**
 * @brief Get Triangle Area
 * @param a triangle vertice cooardinates
 * @param b triangle vertice cooardinates
 * @param c triangle vertice cooardinates
 * @return area
 * @details Triangle Area Formula
 * area = ((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))) / 2
 */
static Fixed GetTriangleArea(Point a, Point b, Point c) {
	Fixed area;

	area = ((a.getX() * (b.getY() - c.getY())) +
			(b.getX() * (c.getY() - a.getY())) +
			(c.getX() * (a.getY() - b.getY()))) /
		2;
	return (area);
}
