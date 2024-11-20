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

int main(void) {
	subjectTest();
	equipLimitsTest();
	return (0);
}

static void subjectTest(void) {
	Ice *ice = new Ice();
	Cure *cure = new Cure();
	headerPrinter("SUBJECT TEST", WIDTH, '-', BGRN);
	std::cout << "Running subject tests:" << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(ice);
	src->learnMateria(cure);

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
	headerPrinter("EQUIP LIMITS", WIDTH, '-', BGRN);
	std::cout << "Create a MateriaSource:" << std::endl;
	IMateriaSource *src = new MateriaSource();

	// Learn materias
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "Create a Character named \"Zedro\":" << std::endl;
	ICharacter *me = new Character("Zedro");

	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << "Equipping Ice and Cure:" << std::endl;
	AMateria *iceMateria = src->createMateria("ice");
	AMateria *cureMateria = src->createMateria("cure");


	me->equip(iceMateria);
	me->equip(cureMateria);

	std::cout << "Testing equip limits:" << std::endl;
	AMateria *extraMateria1 = src->createMateria("ice");
	AMateria *extraMateria2 = src->createMateria("cure");
	me->equip(extraMateria1);
	me->equip(extraMateria2);

	// Print equipped materias
	std::cout << "Equipped materias for \"Zedro\":" << std::endl;
	for (int i = 0; i < MAX_ITEMS; i++) {
		AMateria *materia = dynamic_cast<Character *>(me)->getMateria(i);
		if (materia) {
			std::cout << "Slot " << i << ": " << materia->getType() << std::endl;
		} else {
			std::cout << "Slot " << i << ": Empty" << std::endl;
		}
	}

	std::cout << "Trying to equip beyond limit:" << std::endl;
	AMateria *exceedMateria = src->createMateria("ice");
	me->equip(exceedMateria);

	// Cleanup for `exceedMateria`, if it was not equipped due to inventory limits
	if (!me->hasMateria(exceedMateria)) {
			std::cout << "Exceed materia at " << exceedMateria->getType() << " as it couldn't be equipped."
				  << std::endl;
		delete exceedMateria;
		exceedMateria = NULL;
	}

	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << "Unequipping 0 index:" << std::endl;
	me->unequip(0);
	std::cout << "Unequipping 1 index:" << std::endl;
	me->unequip(1);
	std::cout << "Unequipping 2 index:" << std::endl;
	me->unequip(2);
	std::cout << "Unequipping 3 index:" << std::endl;
	me->unequip(3);
	sepPrinter(WIDTH, '-', BGRN, 1);

	delete src;
	delete me;
	sepPrinter(WIDTH, '-', BGRN, 1);
}
