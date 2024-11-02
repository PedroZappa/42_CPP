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
void test(const std::string &type,
		  const Point &a,
		  const Point &b,
		  const Point &c,
		  const Point &p) {
	headerPrinter(type, WIDTH, '-', BGRN);

	printPlane(a, b, c, p);
	sepPrinter(WIDTH, '-', BGRN, 1);
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
	std::ostringstream coordinates, areas;
	int prec = 2;
	int width = 10;

	// Prepare coordinates column
	coordinates << std::setw(width) << std::left << BYEL "Coordinates:\t\t" NC;
	coordinates << "\n P: " << std::left << std::fixed << std::setprecision(prec)
				<< std::setw(width / 2) << p.getX().toFloat() << " , "
				<< std::setw(width) << p.getY().toFloat();
	coordinates << "\n A: " << std::left << std::fixed << std::setprecision(prec)
				<< std::setw(width / 2) << a.getX().toFloat() << " , "
				<< std::setw(width) << a.getY().toFloat();
	coordinates << "\n B: " << std::left << std::fixed << std::setprecision(prec)
				<< std::setw(width / 2) << b.getX().toFloat() << " , "
				<< std::setw(width) << b.getY().toFloat();
	coordinates << "\n C: " << std::left << std::fixed << std::setprecision(prec)
				<< std::setw(width / 2) << c.getX().toFloat() << " , "
				<< std::setw(width) << c.getY().toFloat();

	// Calculate areas
	Fixed ABC = GetTriangleArea(a, b, c);
	Fixed PAB = GetTriangleArea(p, a, b);
	Fixed PAC = GetTriangleArea(p, a, c);
	Fixed PBC = GetTriangleArea(p, b, c);

	// Prepare areas column
	areas << std::setw(width) << std::left << BYEL "Areas:" NC;
	areas << "\nABC: " << std::setw(width) << std::left << std::fixed
		  << std::setprecision(prec) << ABC.toFloat();
	areas << "\nPAB: " << std::setw(width) << std::left << std::fixed
		  << std::setprecision(prec) << PAB.toFloat();
	areas << "\nPAC: " << std::setw(width) << std::left << std::fixed
		  << std::setprecision(prec) << PAC.toFloat();
	areas << "\nPBC: " << std::setw(width) << std::left << std::fixed
		  << std::setprecision(prec) << PBC.toFloat();

  // Access ostringstrem's strings
	std::string coord_str = coordinates.str();
	std::string area_str = areas.str();
	// NOTE: string::size_type represents sizes and positions in a string
	// Designed to be large enough to represent any string on the system
	// Ensures the support for strings of any length without risking overflow
	std::string::size_type coord_pos = 0, area_pos = 0;
	std::string::size_type coord_end, area_end;

	// Print both columns side by side
	while (coord_pos != std::string::npos || area_pos != std::string::npos) {
		coord_end = coord_str.find('\n', coord_pos); // Find end of line
		area_end = area_str.find('\n', area_pos);

		// Store sections for printing
		std::string coord_line = (coord_pos != std::string::npos)
			? coord_str.substr(coord_pos, (coord_end - coord_pos))
			: "";
		std::string area_line = (area_pos != std::string::npos)
			? area_str.substr(area_pos, (area_end - area_pos))
			: "";

		// Print both columns side by side
		std::cout << std::setw(30) << std::left << coord_line << area_line
				  << std::endl;

		// Get next line for each section
		coord_pos = (coord_end != std::string::npos) ? (coord_end + 1)
													 : std::string::npos;
		area_pos = (area_end != std::string::npos) ? (area_end + 1)
												   : std::string::npos;
	}

	sepPrinter(WIDTH, '-', BMAG, 1);
}
