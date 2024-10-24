/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:27:37 by passunca          #+#    #+#             */
/*   Updated: 2024/10/23 20:26:14 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

#define WIDTH 45

void printRawBits(const Fixed &og,
				  const Fixed &copy,
				  const Fixed &assign_copy);

int main()
{
	Fixed og;
	Fixed copy(og);
	Fixed assign_copy = copy;

	headerPrinter("Fixed Point Numbers and Copy Constructors", WIDTH, '-', BRED);
	
	headerPrinter("Original Raw Bits", WIDTH, '-', BBLU);
	printRawBits(og, copy, assign_copy);

	headerPrinter("Setting Original Raw Bits", WIDTH, '-', BMAG);
	og.setRawBits(666);
	printRawBits(og, copy, assign_copy);

	headerPrinter("Setting Copy Raw Bits", WIDTH, '-', BMAG);
	copy.setRawBits(777);
	printRawBits(og, copy, assign_copy);

	headerPrinter("Setting Assigned Copy Raw Bits", WIDTH, '-', BMAG);
	assign_copy.setRawBits(888);
	printRawBits(og, copy, assign_copy);
	sepPrinter(WIDTH, '-', GRN, 2);

	return (0);
}

/**
 * @brief Print Raw Bits
 * @param og reference to original object
 * @param copy reference to copy object
 * @param assign_copy reference to assigned copy object
*/
void printRawBits(const Fixed &og, const Fixed &copy, const Fixed &assign_copy)
{
	std::cout << YEL "Original Object:\n" NC;
	std::cout << "Address: " BWHT << &og << "\n" NC;
	std::cout << CYN "Raw Bits:\n" NC << og.getRawBits() << "\n";
	sepPrinter(WIDTH, '-', GRN, 1);
	std::cout << YEL "Copy Object:\n" NC;
	std::cout << "Address: " BWHT << &copy << "\n" NC;
	std::cout << CYN "Raw Bits:\n" NC << copy.getRawBits() << "\n";
	sepPrinter(WIDTH, '-', GRN, 1);
	std::cout << YEL "Assigned Copy Object:\n" NC;
	std::cout << "Address: " BWHT << &assign_copy << "\n" NC;
	std::cout << CYN "Raw Bits:\n" NC << assign_copy.getRawBits() << "\n";
}
