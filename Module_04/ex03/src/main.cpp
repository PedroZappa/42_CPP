/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:33:23 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 17:42:34 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/interface.hpp"

static void subjectTest(void);
static void extendedTests();

int main(void) {
	subjectTest();
	extendedTests();
	return 0;
}

static void subjectTest(void) {
	headerPrinter("SUBJECT TEST", WIDTH, '-', BGRN);
	std::cout << "Running subject tests:" << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
}

static void extendedTests() {
	headerPrinter("EXTENDED TEST", WIDTH, '-', BGRN);
	std::cout << "Create a MateriaSource:" << std::endl;  // Create a MateriaSource to store and create Materia
    IMateriaSource *src = new MateriaSource();

	std::cout << "Learning Ice and Cure:" << std::endl;  // Learn Ice and Cure materias
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

	std::cout << "Create a Character named \"Zedro\":" << std::endl;  // Create a Character named "Zedro"
    ICharacter *me = new Character("Zedro");

	std::cout << "Equipping Ice and Cure:" << std::endl;  // Equip Ice and Cure materias for "me"
    AMateria *iceMateria = src->createMateria("ice");
    AMateria *cureMateria = src->createMateria("cure");

    me->equip(iceMateria);
    me->equip(cureMateria);

	std::cout << "Testing equip limits:" << std::endl;  // Test equip limits (MAX_ITEMS == 4)
    AMateria *extraMateria1 = src->createMateria("ice");
    AMateria *extraMateria2 = src->createMateria("cure");
    me->equip(extraMateria1);
    me->equip(extraMateria2);

	std::cout << "Trying to equip beyond limit:" << std::endl;  // Trying to equip beyond limit
    AMateria *exceedMateria = src->createMateria("ice");
    me->equip(exceedMateria); // This should not add the materia, as the inventory is full.

	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << "Creating another character named \"bob\" and using Ice and Cure on it:" << std::endl;  // Create another character named "bob"
    ICharacter *bob = new Character("bob");

    // Use Ice and Cure on "bob"
    std::cout << "Using Ice and Cure on bob:" << std::endl;
    me->use(0, *bob);  // Use Ice on "bob"
    me->use(1, *bob);  // Use Cure on "bob"

    // Attempt to use invalid indexes
    std::cout << "Attempting to use an invalid index:" << std::endl;
    me->use(10, *bob);  // Should handle out of range gracefully

    // Unequip an item and check
    std::cout << "Unequipping first item (Ice) and re-equipping:" << std::endl;
    me->unequip(0);
    me->equip(iceMateria);  // Equip Ice again

    // Testing re-equipping of an already equipped item
    me->equip(cureMateria); // Cure should already be equipped

    // Dropping and listing Materia in Ground (simulating discarded items)
    std::cout << "Testing Ground singleton with discarded Materia:" << std::endl;
    Ground::dropMateria(iceMateria);
    Ground::dropMateria(cureMateria);
    // Ground::printList();  // Show all discarded materia

    // Clean up
    delete bob;
    delete me;
    delete src;
}
