/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:37:48 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 21:10:32 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

#define WIDTH 60
#define N_ANIMALS 10

static void nextTest(void);
static void simpleTest(void);
static void copyTest(void);
static void soundTest(void);
static void brainTest(void);

int main(void) {
	void (*tests[])(void) = {// Array of function pointers
		simpleTest,
		copyTest,
		soundTest,
		brainTest};
	size_t n_tests =
		sizeof(tests) / sizeof(tests[0]); // Number of functions in the array

	for (size_t i = 0; i < n_tests; i++) { // Loop through and call each function
		tests[i]();
		if (i < n_tests - 1)
			nextTest();
	}
	return EXIT_SUCCESS;
}

/** @brief Simple test */
static void simpleTest(void) {
	headerPrinter("Simple Test", WIDTH, '-', BGRN);
	headerPrinter("Creating array of Animals in the Heap:", WIDTH, '-', BYEL);
	AAnimal *animals[N_ANIMALS];
	for (int i = 0; i < N_ANIMALS; i++) {
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	nextTest();

	headerPrinter("Simple Test", WIDTH, '-', BGRN);
	headerPrinter("Testing array of Animals:", WIDTH, '-', BYEL);
	for (int i = 0; i < N_ANIMALS; i++)
		animals[i]->makeSound();
	nextTest();

	headerPrinter("Simple Test", WIDTH, '-', BGRN);
	headerPrinter("Deleting array of Animals:", WIDTH, '-', BYEL);
	for (int i = 0; i < N_ANIMALS; i++)
		delete animals[i];
	headerPrinter("Simple Test finished!", WIDTH, '-', BGRN);
}

static void copyTest(void) {
	headerPrinter("Copy Test", WIDTH, '-', BGRN);

	headerPrinter("Creating and copying Cat object:", WIDTH, '-', BYEL);
	Cat original;
	Cat copy(original);

	sepPrinter(WIDTH, '-', BMAG, 1);
	std::cout << "Original Cat brain address: " << original.getBrain()
		<< std::endl;
	std::cout << "Copied Cat brain address: " << copy.getBrain() << std::endl;

	headerPrinter("Creating and assigning Dog object:", WIDTH, '-', BYEL);
	Dog dog1;
	Dog dog2 = dog1;

	sepPrinter(WIDTH, '-', BMAG, 1);
	std::cout << "Dog1 brain address: " << dog1.getBrain() << std::endl;
	std::cout << "Dog2 brain address: " << dog2.getBrain() << std::endl;

	headerPrinter("Copy Test finished!", WIDTH, '-', BGRN);
}

static void soundTest(void) {
	headerPrinter("Sound Test", WIDTH, '-', BGRN);

	Cat cat;
	Dog dog;

	headerPrinter("Testing Cat sound:", WIDTH, '-', BYEL);
	cat.makeSound();

	headerPrinter("Testing Dog sound:", WIDTH, '-', BYEL);
	dog.makeSound();

	headerPrinter("Sound Test finished!", WIDTH, '-', BGRN);
}

static void brainTest(void) {
	headerPrinter("Brain Test", WIDTH, '-', BGRN);

	Cat cat;
	Dog dog;

	headerPrinter("Testing Cat brain:", WIDTH, '-', BYEL);
	Brain *catBrain = cat.getBrain();
	std::cout << "Cat brain address: " << catBrain << std::endl;

	headerPrinter("Testing Dog brain:", WIDTH, '-', BYEL);
	Brain *dogBrain = dog.getBrain();
	std::cout << "Dog brain address: " << dogBrain << std::endl;

	headerPrinter("Brain Test finished!", WIDTH, '-', BGRN);
}

/**
 * @brief Press enter to continue
 * @details ignore 1000 characters until '\n' is pressed
 * */
static void nextTest(void) {
	std::cout << BYEL "\nPress ENTER to continue test..." NC;
	std::cin.ignore(1000, '\n');
	clearScreen();
}
