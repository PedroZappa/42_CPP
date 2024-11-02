/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:04:15 by passunca          #+#    #+#             */
/*   Updated: 2024/10/25 21:05:54 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_HPP
#define BSP_HPP

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"
#include "ansi.h" // For ANSI color codes
#include <iostream>
#include <iomanip> // For std::setw
#include <sstream>

#define WIDTH 60
#define PLANE_W 60
#define PLANE_H 30

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);
void printPlane(Point a, Point b, Point c, Point p);

/** @brief BSP Helper Functions */
bool bsp(const Point &a, const Point &b, const Point &c, const Point &point);
Fixed GetTriangleArea(Point a, Point b, Point c);

/** @brief tests */
void test(const std::string &type,
		  const Point &a,
		  const Point &b,
		  const Point &c,
		  const Point &p);

#endif
