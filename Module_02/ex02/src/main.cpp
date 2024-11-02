/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:10:37 by passunca          #+#    #+#             */
/*   Updated: 2024/10/24 18:10:59 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

#define WIDTH 45

int main(void)
{
    headerPrinter("Now we're Fix Pointing!!", WIDTH, '-', BRED);
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed c(3);
    Fixed d(4.2f);

    sepPrinter(WIDTH, '-', BGRN, 2);
    std::cout << "Initial values:" << std::endl;
    std::cout << " a = " << a << std::endl;
    std::cout << " b = " << b << std::endl;
    std::cout << " c = " << c << std::endl;
    std::cout << " d = " << d << std::endl;

    sepPrinter(WIDTH, '-', BGRN, 2);
    std::cout << "Testing arithmetic operators:" << std::endl;
    std::cout << " c + d = " << (c + d) << std::endl;
    std::cout << " d - c = " << (d - c) << std::endl;
    std::cout << " c * d = " << (c * d) << std::endl;
    std::cout << " d / c = " << (d / c) << std::endl;

    sepPrinter(WIDTH, '-', BGRN, 2);
    std::cout << "Testing comparison operators:" << std::endl;
    std::cout << " c == d: " << (c == d) << std::endl;
    std::cout << " c != d: " << (c != d) << std::endl;
    std::cout << " c > d: " << (c > d) << std::endl;
    std::cout << " c >= d: " << (c >= d) << std::endl;
    std::cout << " c < d: " << (c < d) << std::endl;
    std::cout << " c <= d: " << (c <= d) << std::endl;

    sepPrinter(WIDTH, '-', BGRN, 2);
    std::cout << "Testing increment/decrement operators:" << std::endl;
    std::cout << " ++a = " << ++a << std::endl;
    std::cout << " a = " << a << std::endl;
    std::cout << " a++ = " << a++ << std::endl;
    sepPrinter(WIDTH, '-', BGRN, 1);
    std::cout << " a = " << a << std::endl;
    std::cout << " --a = " << --a << std::endl;
    std::cout << " a = " << a << std::endl;
    std::cout << " a-- = " << a-- << std::endl;
    std::cout << " a = " << a << std::endl;

    sepPrinter(WIDTH, '-', BGRN, 2);
    std::cout << "Testing min and max functions:" << std::endl;
    std::cout << " Min(a, b) = " << Fixed::min(a, b) << std::endl;
    std::cout << " Max(a, b) = " << Fixed::max(a, b) << std::endl;
    std::cout << " Min(c, d) = " << Fixed::min(c, d) << std::endl;
    std::cout << " Max(c, d) = " << Fixed::max(c, d) << std::endl;

    sepPrinter(WIDTH, '-', BGRN, 2);
    std::cout << "Testing assignment operator:" << std::endl;
    Fixed e;
    e = d;
    std::cout << " e = d, e is now: " << e << std::endl;

    sepPrinter(WIDTH, '-', BGRN, 2);
    std::cout << "Testing toFloat() and toInt():" << std::endl;
    std::cout << " d as float: " << d.toFloat() << std::endl;
    std::cout << " d as int: " << d.toInt() << std::endl;

    return 0;
}
