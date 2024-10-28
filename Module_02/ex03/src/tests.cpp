/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:26:57 by passunca          #+#    #+#             */
/*   Updated: 2024/10/25 21:06:01 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"
#include "../inc/bsp.hpp"
#include <cstdio>

static void log(Point p, Point a, Point b, Point c);

/**
 * @brief Tests if a point with int coordinates is inside a triangle
 * @param type Test Title
 * @param a Triagle Vertice
 * @param b Triagle Vertice
 * @param c Triagle Vertice
 * @param p Point
 * */
void test(const std::string &type, const Point &a, const Point &b, const Point &c, const Point &p) {
	headerPrinter(type, WIDTH, '-', BGRN);

	printPlane(a, b, c, p);
	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << "\n";
	log(p, a, b, c);
	std::cout << "\n\tIs the point inside the triangle? => ";
	if (bsp(a, b, c, p)) {
		std::cout << BGRN "Ohhh yeeeah\n" NC;
	} else {
		std::cout << BRED "Nope\n" NC;
	}
	sepPrinter(WIDTH, '-', BGRN, 1);
}

/**
 * @brief Logs triangle info
 * @param p Point
 * @param a Point
 * @param b Point
 * @param c Point
 * */
static void log(Point p, Point a, Point b, Point c) {
	Fixed ABC = GetTriangleArea(a, b, c);
	Fixed PAB = GetTriangleArea(p, a, b);
	Fixed PAC = GetTriangleArea(p, a, c);
	Fixed PBC = GetTriangleArea(p, b, c);

	std::cout << "\tABC: " << ABC << "\n";
	std::cout << "\tPAB: " << PAB << "\n";
	std::cout << "\tPAC: " << PAC << "\n";
	std::cout << "\tPBC: " << PBC << "\n";
}
