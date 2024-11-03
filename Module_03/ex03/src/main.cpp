/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:35:26 by passunca          #+#    #+#             */
/*   Updated: 2024/11/03 12:14:09 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

#define WIDTH 80
#define MAX_TRAPS 3

typedef enum e_test {
	EXIT = 0,
	CLAPTRAP_TEST,
	SCAVTRAP_TEST,
	POLYMORPHISM_TEST,
	FRAGTRAP_TEST,
	DIAMONDTRAP_TEST,
	INTERACTION_TEST,
	RUN_ALL_TESTS,
	SDELECT_TEST
} t_test;

void clapTrapTest();
void scavTrapTest();
void polymorphismTest();
void fragTrapTest();
void diamondTrapTest();
void interactionTest();
void clearScreen();

int main(void) {
	int choice;

	do {
		headerPrinter("Choose a test suite to run:", WIDTH, '-', BYEL);
		std::cout << BGRN "\t1." NC " ClapTrap Test" << std::endl;
		std::cout << BGRN "\t2." NC " ScavTrap Test" << std::endl;
		std::cout << BGRN "\t3." NC " Polymorphism Test" << std::endl;
		std::cout << BGRN "\t4." NC " FragTrap Test" << std::endl;
		std::cout << BGRN "\t5." NC " DiamondTrap Test" << std::endl;
		std::cout << BGRN "\t6." NC " Interaction Test" << std::endl;
		std::cout << BGRN "\t7." NC " Run all tests" << std::endl;
		std::cout << BGRN "\t0." NC " Exit" << std::endl;
		sepPrinter(WIDTH, '-', BYEL, 1);
		std::cout << BCYN "Enter your choice: " NC;

		// Get user input
		while (!(std::cin >> choice)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << BRED "Invalid input. Please enter a number: " NC;
		}

		// Update the switch statement:
		switch (choice) {
		case CLAPTRAP_TEST:
			clapTrapTest();
			break;
		case SCAVTRAP_TEST:
			scavTrapTest();
			break;
		case POLYMORPHISM_TEST:
			polymorphismTest();
			break;
		case FRAGTRAP_TEST:
			fragTrapTest();
			break;
		case DIAMONDTRAP_TEST:
			diamondTrapTest();
			break;
		case INTERACTION_TEST:
			interactionTest();
			break;
		case RUN_ALL_TESTS:
			clapTrapTest();
			scavTrapTest();
			polymorphismTest();
			fragTrapTest();
			diamondTrapTest();
			interactionTest();
			break;
		case EXIT:
			std::cout << "Exiting program. Bu-Bye 󱠡" << std::endl;
			break;
		default:
			std::cout << BRED "Invalid choice. Please try again..." NC
					  << std::endl;
		}

		if (choice != EXIT) {
			sepPrinter(WIDTH, '-', BYEL, 1);
			std::cout << "Press Enter to continue...";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
			clearScreen();
		}
	} while (choice != EXIT);

	return (EXIT_SUCCESS);
}

void clapTrapTest() {
	int test = 1;

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
	std::cout << "Try to attack:" << std::endl;
	namedClapTrap.attack("Enemy");
	std::cout << "Try to be repaired:" << std::endl;
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
	std::cout << "Try to attack:" << std::endl;
	namedClapTrap.attack("Enemy");
	std::cout << "Try to take damage:" << std::endl;
	namedClapTrap.takeDamage(5);
	std::cout << "Try to be repaired:" << std::endl;
	namedClapTrap.beRepaired(5);
	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << namedClapTrap << std::endl;
	sepPrinter(WIDTH, '=', BGRN, 2);
}

void scavTrapTest() {
	int test = 1;
	headerPrinter("Testing ScavTrap Class", WIDTH, '=', BCYN);

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

	std::cout << BMAG << test++ << BWHT ". Testing ScavTrap taking damage:\n" NC;
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
	std::cout << "Try to attack:" << std::endl;
	namedScavTrap.attack("Enemy");
	std::cout << "Try to be repaired:" << std::endl;
	namedScavTrap.beRepaired(11);
	std::cout << "Try to guardGate:" << std::endl;
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

void polymorphismTest() {
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

void fragTrapTest() {
	int test = 1;
	headerPrinter("Testing FragTrap Class", WIDTH, '=', BRED);

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
	std::cout << "Try to attack:" << std::endl;
	namedFragTrap.attack("Enemy");
	std::cout << "Try to be repaired:" << std::endl;
	namedFragTrap.beRepaired(1);
	std::cout << "Try to high five:" << std::endl;
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
	std::cout << "Try to attack:" << std::endl;
	namedFragTrap.attack("Enemy");
	std::cout << "Try to take damage:" << std::endl;
	namedFragTrap.takeDamage(5);
	std::cout << "Try to be repaired:" << std::endl;
	namedFragTrap.beRepaired(5);
	std::cout << "Try to high five:" << std::endl;
	namedFragTrap.highFivesGuys();
	sepPrinter(WIDTH, '-', BRED, 1);
	std::cout << namedFragTrap << std::endl;
	sepPrinter(WIDTH, '=', BRED, 2);
}

void diamondTrapTest() {
	int test = 1;
	headerPrinter("Testing DiamondTrap Class", WIDTH, '=', BMAG);

	std::cout << BMAG << test++
			  << BWHT ". Creating DiamondTrap with default constructor:\n" NC;
	DiamondTrap defaultDiamondTrap;
	sepPrinter(WIDTH, '-', BMAG, 1);
	std::cout << defaultDiamondTrap << std::endl;

	sepPrinter(WIDTH, '-', BMAG, 1);
	std::cout << BMAG << test++
			  << BWHT ". Creating DiamondTrap with parameterized "
					  "constructor:\n" NC;
	DiamondTrap namedDiamondTrap("DT-001");
	sepPrinter(WIDTH, '-', BMAG, 1);
	std::cout << namedDiamondTrap << std::endl;

	sepPrinter(WIDTH, '-', BMAG, 1);
	std::cout << BMAG << test++
			  << BWHT ". Testing DiamondTrap attack function:\n" NC;
	namedDiamondTrap.attack("Enemy");
	sepPrinter(WIDTH, '-', BMAG, 1);
	std::cout << namedDiamondTrap << std::endl;

	sepPrinter(WIDTH, '-', BMAG, 1);
	std::cout << BMAG << test++
			  << BWHT ". Testing DiamondTrap whoAmI function:\n" NC;
	namedDiamondTrap.whoAmI();

	sepPrinter(WIDTH, '-', BMAG, 1);
	std::cout << BMAG << test++
			  << BWHT ". Testing DiamondTrap inherited functions:\n" NC;
	namedDiamondTrap.guardGate();
	namedDiamondTrap.highFivesGuys();

	sepPrinter(WIDTH, '=', BMAG, 2);
}

void interactionTest() {
	int test = 1;
	headerPrinter("Testing Interactions Between Classes", WIDTH, '=', BYEL);

	std::cout << BMAG << test++ << BWHT ". Creating one of each type:\n" NC;
	sepPrinter(WIDTH, '-', BYEL, 1);
	ClapTrap clap("CT-002");
	ScavTrap scav("ST-002");
	FragTrap frag("FT-002");
	DiamondTrap diamond("DT-002");
	sepPrinter(WIDTH, '-', BYEL, 1);
	std::cout << clap << std::endl
			  << scav << std::endl
			  << frag << std::endl
			  << diamond << std::endl;

	sepPrinter(WIDTH, '-', BYEL, 1);
	std::cout << BMAG << test++
			  << BWHT ". Testing attacks between different types:\n" NC;
	sepPrinter(WIDTH, '-', BYEL, 1);
	clap.attack("ST-002");
	scav.takeDamage(clap.getAttackDamage());
	scav.attack("FT-002");
	frag.takeDamage(scav.getAttackDamage());
	frag.attack("DT-002");
	diamond.takeDamage(frag.getAttackDamage());
	diamond.attack("CT-002");
	clap.takeDamage(diamond.getAttackDamage());
	sepPrinter(WIDTH, '-', BYEL, 1);
	std::cout << clap << std::endl
			  << scav << std::endl
			  << frag << std::endl
			  << diamond << std::endl;

	sepPrinter(WIDTH, '-', BYEL, 1);
	std::cout << BMAG << test++ << BWHT ". Testing unique abilities:\n" NC;
	sepPrinter(WIDTH, '-', BYEL, 1);
	std::cout << scav.getName() << " triggers Gate Keeper mode.\n";
	scav.guardGate();
	std::cout << frag.getName() << " triggers High Five.\n";
	frag.highFivesGuys();
	std::cout << diamond.getName() << " reveals its identity.\n";
	diamond.whoAmI();

	sepPrinter(WIDTH, '-', BYEL, 1);
	std::cout << BMAG << test++ << BWHT ". Testing polymorphism:\n" NC;
	ClapTrap *trapArray[4];
	trapArray[0] = new ClapTrap("CT-Poly");
	trapArray[1] = new ScavTrap("ST-Poly");
	trapArray[2] = new FragTrap("FT-Poly");
	trapArray[3] = new DiamondTrap("DT-Poly");

	for (int i = 0; i < 4; ++i) {
		sepPrinter(WIDTH, '*', BYEL, 1);
		std::cout << *trapArray[i] << std::endl;
		trapArray[i]->attack("Enemy");
	}
	sepPrinter(WIDTH, '-', BYEL, 1);
	
	std::cout << BMAG << test++ << BWHT ". Testing attacking eachother:\n" NC;
	sepPrinter(WIDTH, '-', BYEL, 1);
	trapArray[0]->attack("ST-Poly");
	trapArray[1]->takeDamage(trapArray[0]->getAttackDamage());
	trapArray[1]->attack("FT-Poly");
	trapArray[2]->takeDamage(trapArray[1]->getAttackDamage());
	trapArray[2]->attack("DT-Poly");
	trapArray[3]->takeDamage(trapArray[2]->getAttackDamage());
	sepPrinter(WIDTH, '-', BYEL, 1);

	for (int i = 0; i < 4; ++i) {
		sepPrinter(WIDTH, '*', BYEL, 1);
		std::cout << *trapArray[i] << std::endl;
	}
	sepPrinter(WIDTH, '-', BYEL, 1);

	// Delete all pointers to ClapTraps
	for (int i = 0; i < 4; ++i) {
		delete trapArray[i];
	}

	sepPrinter(WIDTH, '=', BYEL, 2);
}

void clearScreen() {
	std::cout << "\033[2J\033[1;1H";
}
