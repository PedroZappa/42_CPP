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
static void equipLimitsTest();
static void deepCopyTest(void);

int main(void) {
	subjectTest();
	equipLimitsTest();
	deepCopyTest();
	return (0);
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

static void equipLimitsTest() {
	headerPrinter("EXTENDED TEST", WIDTH, '-', BGRN);
	std::cout << "Create a MateriaSource:"
			  << std::endl; // Create a MateriaSource to store and create Materia
	IMateriaSource *src = new MateriaSource();

	std::cout << "Learning Ice and Cure:"
			  << std::endl; // Learn Ice and Cure materias
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "Create a Character named \"Zedro\":"
			  << std::endl; // Create a Character named "Zedro"
	ICharacter *me = new Character("Zedro");

	std::cout << "Equipping Ice and Cure:"
			  << std::endl; // Equip Ice and Cure materias for "me"
	AMateria *iceMateria = src->createMateria("ice");
	AMateria *cureMateria = src->createMateria("cure");

	me->equip(iceMateria);
	me->equip(cureMateria);

	std::cout << "Testing equip limits:"
			  << std::endl; // Test equip limits (MAX_ITEMS == 4)
	AMateria *extraMateria1 = src->createMateria("ice");
	AMateria *extraMateria2 = src->createMateria("cure");
	me->equip(extraMateria1);
	me->equip(extraMateria2);

	std::cout << "Trying to equip beyond limit:"
			  << std::endl; // Trying to equip beyond limit
	AMateria *exceedMateria = src->createMateria("ice");
	me->equip(exceedMateria);
	// This should not add the materia, as the inventory is full.
	// Cleanup for `exceedMateria`, if it was not equipped due to inventory limits
	if (!me->hasMateria(exceedMateria)) {
		delete exceedMateria;
		exceedMateria = NULL;
	}
	sepPrinter(WIDTH, '-', BGRN, 1);
	delete me;
	delete src;
}

static void deepCopyTest(void) {
	headerPrinter("DEEP COPY TEST", WIDTH, '-', BGRN);

	IMateriaSource *src = new MateriaSource();
	IMateriaSource *src2 = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << "Before Deep copy:" << std::endl;
	std::cout << "src " << src << std::endl;
	std::cout << "src2 " << src2 << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << "After Deep copy:" << std::endl;
	*src2 = *src;
	std::cout << "src " << src << std::endl;
	std::cout << "src2 " << src2 << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);

	delete src;
	delete src2;
}
