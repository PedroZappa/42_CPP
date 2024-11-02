/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:31:35 by passunca          #+#    #+#             */
/*   Updated: 2024/11/02 12:32:09 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

#define WIDTH 60

int main(void) {
	int test = 1;
	headerPrinter("Testing ClapTrap Class", WIDTH, '-', BGRN);

	std::cout << BMAG << test << BWHT ". Creating w/ default constructor:\n\n" NC;
	ClapTrap defaultClapTrap;
	std::cout << defaultClapTrap << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);
	++test;

	std::cout << BMAG << test
			  << BWHT ". Creating w/ parameterized constructor:\n\n" NC;
	ClapTrap namedClapTrap("Zed");
	std::cout << namedClapTrap << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);
	++test;

	std::cout << BMAG << test << BWHT ". Creating w/ copy constructor:\n\n" NC;
	ClapTrap copiedClapTrap(namedClapTrap);
	std::cout << copiedClapTrap << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);
	++test;

	std::cout << BMAG << test << BWHT ". Testing assignment operator:\n\n" NC;
	ClapTrap assignedClapTrap;
	assignedClapTrap = namedClapTrap;
	std::cout << assignedClapTrap << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);
	++test;

	std::cout << BMAG << test << BWHT ". Testing attack function:\n\n" NC;
	namedClapTrap.attack("Zed");
	std::cout << namedClapTrap << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);
	++test;

	std::cout << BMAG << test << BWHT ". Testing takeDamage function:\n\n" NC;
	namedClapTrap.takeDamage(5);
	std::cout << namedClapTrap << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);
	++test;

	std::cout << BMAG << test << BWHT ". Testing beRepaired function:\n\n" NC;
	namedClapTrap.beRepaired(3);
	std::cout << namedClapTrap << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);
	++test;

	std::cout << BMAG << test << BWHT ". Testing energy depletion:\n\n" NC;
	for (int i = 0; i < 3; ++i) {
		namedClapTrap.attack("ClapTrap");
	}
	std::cout << namedClapTrap << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);

	std::cout << BMAG << test
			  << BWHT ". Testing attack when out of energy:\n\n" NC;
	namedClapTrap.attack("Enemy");
	sepPrinter(WIDTH, '-', BGRN, 1);
	++test;

	std::cout << BMAG << test << BWHT ". Testing taking lethal damage:\n\n" NC;
	namedClapTrap.takeDamage(100);
	std::cout << namedClapTrap << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);
	++test;

	// Test actions when dead
	std::cout << BMAG << test << BWHT ". Testing actions when dead:\n\n" NC;
	std::cout << "ClapTrap " << namedClapTrap.getName() << " tries to attack\n";
	namedClapTrap.attack("Enemy");
	std::cout << "ClapTrap " << namedClapTrap.getName()
			  << " tries to damage itself\n";
	namedClapTrap.takeDamage(5);
	std::cout << "ClapTrap " << namedClapTrap.getName()
			  << " tries to be repaired\n";
	namedClapTrap.beRepaired(5);
	sepPrinter(WIDTH, '-', BGRN, 2);
	++test;

	// Address of ClapTraps in Memory
	std::cout << BYEL "Address of defaultClapTrap: " << &defaultClapTrap
			  << "\n" NC;
	std::cout << BYEL "Address of namedClapTrap: " << &namedClapTrap << "\n" NC;
	std::cout << BYEL "Address of copiedClapTrap: " << &copiedClapTrap << "\n" NC;
	std::cout << BYEL "Address of assignedClapTrap: " << &assignedClapTrap
			  << "\n" NC;
	sepPrinter(WIDTH, '-', BGRN, 2);
	return (0);
}
