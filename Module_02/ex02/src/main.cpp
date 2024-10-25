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

	sepPrinter(WIDTH, '-', BGRN, 2);
	std::cout << a << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << ++a << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << a << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 2);
	std::cout << a++ << std::endl; // Uses Copy Constructor
	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << a << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 2);

	return 0;
}
