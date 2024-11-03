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

#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"

#define WIDTH 80
#define MAX_TRAPS 3

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
	
	// FragTrap Tests
	{
		headerPrinter("Testing FragTrap Class", WIDTH, '=', BRED);
		test = 1;

		std::cout << BMAG << test++
				  << BWHT ". Creating FragTrap with default constructor:\n" NC;
		FragTrap defaultFragTrap;
		sepPrinter(WIDTH, '-', BRED, 1);
		std::cout << defaultFragTrap << std::endl;
		sepPrinter(WIDTH, '-', BRED, 1);

		std::cout << BMAG << test++
				  << BWHT ". Creating FragTrap with parameterized "
						  "constructor:\n" NC;
		FragTrap namedFragTrap("FT-001");
		sepPrinter(WIDTH, '-', BRED, 1);
		std::cout << namedFragTrap << std::endl;
		sepPrinter(WIDTH, '-', BRED, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing FragTrap attack function:\n" NC;
		namedFragTrap.attack("Enemy");
		sepPrinter(WIDTH, '-', BRED, 1);
		std::cout << namedFragTrap << std::endl;
		sepPrinter(WIDTH, '-', BRED, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing FragTrap beRepaired function:\n" NC;
		namedFragTrap.beRepaired(1);
		sepPrinter(WIDTH, '-', BRED, 1);
		std::cout << namedFragTrap << std::endl;
		sepPrinter(WIDTH, '-', BRED, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing FragTrap highFivesGuys function:\n" NC;
		namedFragTrap.highFivesGuys();
		sepPrinter(WIDTH, '-', BRED, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing FragTrap energy depletion:\n" NC;
		for (int i = 0; i < 99; ++i) {
			namedFragTrap.attack("Enemy");
		}
		sepPrinter(WIDTH, '-', BRED, 1);
		std::cout << namedFragTrap << std::endl;
		sepPrinter(WIDTH, '-', BRED, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing FragTrap actions when out of energy:\n" NC;
		namedFragTrap.attack("Enemy");
		namedFragTrap.beRepaired(1);
		namedFragTrap.highFivesGuys();
		sepPrinter(WIDTH, '-', BRED, 1);
		std::cout << namedFragTrap << std::endl;
		sepPrinter(WIDTH, '-', BRED, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing FragTrap taking lethal damage:\n" NC;
		namedFragTrap.takeDamage(200);
		sepPrinter(WIDTH, '-', BRED, 1);
		std::cout << namedFragTrap << std::endl;
		sepPrinter(WIDTH, '-', BRED, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing FragTrap actions when dead:\n" NC;
		namedFragTrap.attack("Enemy");
		namedFragTrap.takeDamage(5);
		namedFragTrap.beRepaired(5);
		namedFragTrap.highFivesGuys();
		sepPrinter(WIDTH, '-', BRED, 1);
		std::cout << namedFragTrap << std::endl;
		sepPrinter(WIDTH, '=', BRED, 2);
	}

	// Interaction Tests
	{
		headerPrinter("Testing Interactions Between Classes", WIDTH, '=', BYEL);
		test = 1;

		std::cout << BMAG << test++ << BWHT ". Creating one of each type:\n" NC;
		ClapTrap clap("CT-002");
		ScavTrap scav("ST-002");
		FragTrap frag("FT-002");
		std::cout << clap << std::endl
				  << scav << std::endl
				  << frag << std::endl;
		sepPrinter(WIDTH, '-', BYEL, 1);

		std::cout << BMAG << test++
				  << BWHT ". Testing attacks between different types:\n" NC;
		clap.attack("ST-002");
		scav.takeDamage(clap.getAttackDamage());
		scav.attack("FT-002");
		frag.takeDamage(scav.getAttackDamage());
		frag.attack("CT-002");
		clap.takeDamage(frag.getAttackDamage());
		std::cout << clap << std::endl
				  << scav << std::endl
				  << frag << std::endl;
		sepPrinter(WIDTH, '-', BYEL, 1);

		std::cout << BMAG << test++ << BWHT ". Testing unique abilities:\n" NC;
		scav.guardGate();
		frag.highFivesGuys();
		sepPrinter(WIDTH, '-', BYEL, 1);

		std::cout << BMAG << test++ << BWHT ". Testing polymorphism:\n" NC;
		ClapTrap *trapArray[MAX_TRAPS];
		trapArray[0] = new ClapTrap("CT-Poly");
		trapArray[1] = new ScavTrap("ST-Poly");
		trapArray[2] = new FragTrap("FT-Poly");

		for (int i = 0; i < MAX_TRAPS; ++i) {
			std::cout << *trapArray[i] << std::endl;
			trapArray[i]->attack("Enemy");
		}

		for (int i = 0; i < MAX_TRAPS; ++i) {
			delete trapArray[i];
		}
		sepPrinter(WIDTH, '=', BYEL, 2);
	}
	return (0);
}
