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

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

#define WIDTH 60

int main (void)
{
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
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << YEL "User your brainz!!:" NC << std::endl;
	
	sepPrinter(WIDTH, '-', BGRN, 1);
	std::cout << YEL "TestBrain:" NC << std::endl;
	std::cout << j << " " << std::endl;
	std::cout << i << " " << std::endl;

	sepPrinter(WIDTH, '-', BGRN, 1);
	delete meta;
	delete j;
	delete i;
	sepPrinter(WIDTH, '-', BGRN, 1);

	return (0);
}
