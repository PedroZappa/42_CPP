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
        AMateria* materia = dynamic_cast<Character*>(me)->getMateria(i);
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
        delete exceedMateria;
        exceedMateria = NULL;
        std::cout << "Exceed materia deleted as it couldn't be equipped." << std::endl;
    }

    sepPrinter(WIDTH, '-', BGRN, 1);
	me->unequip(0);
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
	std::cout << "src\t" << src << std::endl;
	std::cout << "src2\t" << src2 << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << "After Deep copy:" << std::endl;
	*src2 = *src;
	std::cout << "src\t" << src << std::endl;
	std::cout << "src2\t" << src2 << std::endl;
	sepPrinter(WIDTH, '-', BGRN, 1);

	delete src;
	delete src2;
}
