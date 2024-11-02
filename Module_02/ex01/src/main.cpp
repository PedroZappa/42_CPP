/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:03:39 by passunca          #+#    #+#             */
/*   Updated: 2024/10/24 17:49:38 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

#define WIDTH 45

int main(void)
{
	headerPrinter("Towards a more useful Fixed Point Number", WIDTH, '-', BRED);
	Fixed a;
	const Fixed b(10);
	const Fixed c(42.42f);
	const Fixed d(b);

	a = Fixed(1234.4321f);
	
	sepPrinter(WIDTH, '-', BGRN, 2);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	sepPrinter(WIDTH, '-', BGRN, 2);
	return (0);
}
