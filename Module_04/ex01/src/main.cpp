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

int main(void) {
	headerPrinter("Testing Animal Class", WIDTH, '-', BGRN);
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << YEL "Test Animals:" NC << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << YEL "Sounds please:" NC << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << YEL "Test your brainz!!:" NC << std::endl;
	// Test Dog's Brain
	Dog *dog1 = new Dog();
	Dog *dog2 = new Dog(*dog1); // Copy constructor

	std::cout << "Dog1 thinking: ";
	dog1->getBrain()->think();

	std::cout << "Dog2 thinking: ";
	dog2->getBrain()->think();

	// Modify dog1's brain
	std::string newIdea = "I love bones!";
	dog1->getBrain()->setIdea(newIdea, 0);

	std::cout << "Dog1 thinking after modification: ";
	dog1->getBrain()->think();
	std::cout << "Dog2 thinking (should be unchanged): ";
	dog2->getBrain()->think();

	sepPrinter(WIDTH, '-', BGRN, 1);
	// Test Cat's Brain
	Cat *cat1 = new Cat();
	Cat *cat2 = new Cat();

	std::cout << "Cat1 thinking: ";
	cat1->getBrain()->think();

	// Assign cat1 to cat2
	*cat2 = *cat1;

	std::cout << "Cat2 thinking after assignment: ";
	cat2->getBrain()->think();

	// Modify cat1's brain
	std::string catIdea = "I want to catch a mouse!";
	cat1->getBrain()->setIdea(catIdea, 1);

	std::cout << "Cat1 thinking after modification: ";
	cat1->getBrain()->think();
	std::cout << "Cat2 thinking (should be unchanged): ";
	cat2->getBrain()->think();

	sepPrinter(WIDTH, '-', BGRN, 1);
	delete meta;
	delete j;
	delete i;
	delete dog1;
	delete dog2;
	delete cat1;
	delete cat2;
	sepPrinter(WIDTH, '-', BGRN, 1);

	return (0);
}
