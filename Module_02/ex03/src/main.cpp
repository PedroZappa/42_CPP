/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:05:16 by passunca          #+#    #+#             */
/*   Updated: 2024/10/25 21:08:52 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bsp.hpp"

static void nextTest(void);

int main(void) {
	headerPrinter("BSP", WIDTH, '-', BRED);

	/** Testing with Fixed Points defined with ints */
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(10), Fixed(42));
	Point c(Fixed(25), Fixed(0));

	Point p(Fixed(10), Fixed(15));
	test("Int Test 1", a, b, c, p);
	nextTest();
	headerPrinter("BSP", WIDTH, '-', BRED);
	Point p2(Fixed(5), Fixed(15));
	test("Int Test 2", a, b, c, p2);
	nextTest();
	headerPrinter("BSP", WIDTH, '-', BRED);
	Point p3(Fixed(20), Fixed(45));
	test("Int Test 3", a, b, c, p3);
	nextTest();
	headerPrinter("BSP", WIDTH, '-', BRED);
	Point p4(Fixed(10), Fixed(42));
	test("Int Test 4 : Edge", a, b, c, p4);
	nextTest();

	/** Testing with Fixed Points defined with floats */
	Point d(Fixed(1.2f), Fixed(2.3f));
	Point e(Fixed(10.5f), Fixed(31.2f));
	Point f(Fixed(20.7f), Fixed(2));

	headerPrinter("BSP", WIDTH, '-', BRED);
	Point p5(Fixed(5), Fixed(5));
	test("Float Test 1", d, e, f, p5);
	nextTest();
	headerPrinter("BSP", WIDTH, '-', BRED);
	Point p6(Fixed(10), Fixed(12));
	test("Float Test 2", d, e, f, p6);
	nextTest();
	headerPrinter("BSP", WIDTH, '-', BRED);
	Point p7(Fixed(20), Fixed(25));
	test("Float Test 3", d, e, f, p7);
	nextTest();

	return (0);
}

/**
 * @brief Press enter to continue
 * @details ignore 1000 characters until '\n' is pressed
 * */
static void nextTest(void) {
	std::cout << BYEL "\nPress ENTER for next test..." NC;
	std::cin.ignore(1000, '\n');
}
