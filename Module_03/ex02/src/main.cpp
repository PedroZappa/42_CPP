/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:35:26 by passunca          #+#    #+#             */
/*   Updated: 2024/11/02 21:46:31 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

#define WIDTH 80

int main(void) {
	int test = 1;

	// ClapTrap Tests
	{
		headerPrinter("Testing ClapTrap Class", WIDTH, '-', BGRN);
		std::cout << BMAG << test++
				  << BWHT ". Creating ClapTrap with default constructor:\n" NC;
		ClapTrap defaultClapTrap;
		sepPrinter(WIDTH, '-', BGRN, 1);
		std::cout << defaultClapTrap << std::endl;
		sepPrinter(WIDTH, '-', BGRN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Creating ClapTrap with parameterized "
						  "constructor:\n" NC;
		ClapTrap namedClapTrap("CT-001");
		sepPrinter(WIDTH, '-', BGRN, 1);
		std::cout << namedClapTrap << std::endl;
		sepPrinter(WIDTH, '-', BGRN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing ClapTrap attack function:\n" NC;
		namedClapTrap.attack("Enemy");
		sepPrinter(WIDTH, '-', BGRN, 1);
		std::cout << namedClapTrap << std::endl;
		sepPrinter(WIDTH, '-', BGRN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing ClapTrap takeDamage function:\n" NC;
		namedClapTrap.takeDamage(5);
		sepPrinter(WIDTH, '-', BGRN, 1);
		std::cout << namedClapTrap << std::endl;
		sepPrinter(WIDTH, '-', BGRN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing ClapTrap beRepaired function:\n" NC;
		namedClapTrap.beRepaired(2);
		sepPrinter(WIDTH, '-', BGRN, 1);
		std::cout << namedClapTrap << std::endl;
		sepPrinter(WIDTH, '-', BGRN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing ClapTrap energy depletion:\n" NC;
		for (int i = 0; i < 9; ++i) {
			namedClapTrap.attack("Enemy");
		}
		sepPrinter(WIDTH, '-', BGRN, 1);
		std::cout << namedClapTrap << std::endl;
		sepPrinter(WIDTH, '-', BGRN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing ClapTrap actions when out of energy:\n" NC;
		namedClapTrap.attack("Enemy");
		namedClapTrap.beRepaired(1);
		sepPrinter(WIDTH, '-', BGRN, 1);
		std::cout << namedClapTrap << std::endl;
		sepPrinter(WIDTH, '-', BGRN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing ClapTrap taking lethal damage:\n" NC;
		defaultClapTrap.takeDamage(100);
		sepPrinter(WIDTH, '-', BGRN, 1);
		std::cout << defaultClapTrap << std::endl;
		sepPrinter(WIDTH, '-', BGRN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing ClapTrap actions when dead:\n" NC;
		namedClapTrap.attack("Enemy");
		namedClapTrap.takeDamage(5);
		namedClapTrap.beRepaired(5);
		sepPrinter(WIDTH, '-', BGRN, 1);
		std::cout << namedClapTrap << std::endl;
		sepPrinter(WIDTH, '=', BGRN, 2);
	}

	// ScavTrap Tests
	{
		headerPrinter("Testing ScavTrap Class", WIDTH, '=', BCYN);
		test = 1;

		std::cout << BMAG << test++
				  << BWHT ". Creating ScavTrap with default constructor:\n" NC;
		ScavTrap defaultScavTrap;
		sepPrinter(WIDTH, '-', BCYN, 1);
		std::cout << defaultScavTrap << std::endl;
		sepPrinter(WIDTH, '-', BCYN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Creating ScavTrap with parameterized "
						  "constructor:\n" NC;
		ScavTrap namedScavTrap("ST-001");
		sepPrinter(WIDTH, '-', BCYN, 1);
		std::cout << namedScavTrap << std::endl;
		sepPrinter(WIDTH, '-', BCYN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing ScavTrap attack function:\n" NC;
		namedScavTrap.attack("Enemy");
		sepPrinter(WIDTH, '-', BCYN, 1);
		std::cout << namedScavTrap << std::endl;
		sepPrinter(WIDTH, '-', BCYN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing ScavTrap guardGate function:\n" NC;
		namedScavTrap.guardGate();
		sepPrinter(WIDTH, '-', BCYN, 1);
		std::cout << namedScavTrap << std::endl;
		sepPrinter(WIDTH, '-', BCYN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing ScavTrap taking damage:\n" NC;
		for (int i = 0; i < 5; ++i) {
			namedScavTrap.takeDamage(5);
		}
		sepPrinter(WIDTH, '-', BCYN, 1);
		std::cout << namedScavTrap << std::endl;
		sepPrinter(WIDTH, '-', BCYN, 1);

		std::cout << BMAG << test++ << BWHT ". Testing ScavTrap repairing:\n" NC;
		namedScavTrap.beRepaired(15);
		sepPrinter(WIDTH, '-', BCYN, 1);
		std::cout << namedScavTrap << std::endl;
		sepPrinter(WIDTH, '-', BCYN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing ScavTrap energy depletion:\n" NC;
		for (int i = 0; i < 49; ++i) {
			namedScavTrap.attack("Enemy");
		}
		sepPrinter(WIDTH, '-', BCYN, 1);
		std::cout << namedScavTrap << std::endl;
		sepPrinter(WIDTH, '-', BCYN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing ScavTrap actions when out of energy:\n" NC;
		namedScavTrap.attack("Enemy");
		namedScavTrap.beRepaired(11);
		namedScavTrap.guardGate();
		sepPrinter(WIDTH, '-', BCYN, 1);
		std::cout << namedScavTrap << std::endl;
		sepPrinter(WIDTH, '-', BCYN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing ScavTrap taking lethal damage:\n" NC;
		defaultScavTrap.takeDamage(200);
		sepPrinter(WIDTH, '-', BCYN, 1);
		std::cout << defaultScavTrap << std::endl;
		sepPrinter(WIDTH, '-', BCYN, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing ScavTrap actions when dead:\n" NC;
		std::cout << "Try to attack:" << std::endl;
		namedScavTrap.attack("Enemy");
		std::cout << "Try to take damage:" << std::endl;
		namedScavTrap.takeDamage(5);
		std::cout << "Try to be repaired:" << std::endl;
		namedScavTrap.beRepaired(5);
		std::cout << "Try to guardGate:" << std::endl;
		namedScavTrap.guardGate();
		sepPrinter(WIDTH, '-', BCYN, 1);
		std::cout << namedScavTrap << std::endl;
		sepPrinter(WIDTH, '=', BCYN, 2);
	}

	// Polymorphism Test
	{
		headerPrinter("Testing Polymorphism", WIDTH, '=', BYEL);

		std::cout << BMAG "1" BWHT ". Creating ClapTrap and ScavTrap "
								   "pointers:\n" NC;
		ClapTrap *clap_ptr = new ClapTrap("CT-PTR");
		ClapTrap *scav_ptr = new ScavTrap("ST-PTR");
		sepPrinter(WIDTH, '=', BGRN, 1);

		std::cout << BMAG "2" BWHT ". Testing attack function through "
								   "pointers:\n" NC;
		clap_ptr->attack("Enemy");
		scav_ptr->attack("Enemy");
		sepPrinter(WIDTH, '=', BGRN, 1);

		std::cout << BMAG "3" BWHT ". Deleting pointers:\n" NC;
		delete clap_ptr;
		delete scav_ptr;

		sepPrinter(WIDTH, '=', BYEL, 2);
	}

	return (0);
}
