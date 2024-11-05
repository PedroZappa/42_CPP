/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:20:01 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 21:03:15 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

/** @brief Default Constructor */
Dog::Dog(void) : _brain(new Brain()) {
	Animal::setType("Dog");
	_brain = new Brain();
	std::cout << RED "Dog " BWHT << Animal::getType()
			  << NC " default constructor called " << std::endl;
}

/** @brief Copy Constructor */
Dog::Dog(const Dog &copy) : Animal(copy) {
	*this = copy;
	_brain = new Brain(*(copy._brain));
	std::cout << RED "Dog " BWHT << Animal::getType()
			  << NC " copy constructor called " << std::endl;
}

/** @brief Destructaor */
Dog::~Dog(void) {
	delete _brain;
	std::cout << RED "Dog " BWHT << Animal::getType()
			  << NC " destructor called " << std::endl;
}

/** @brief Copy Assignment Operator */
Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs)
		Animal::operator=(rhs);
	return (*this);
}

/** @brief Make sound */
void Dog::makeSound() const {
	std::cout << RED "Dog: " BWHT << "woof!" NC << std::endl;
}

/** @brief Get Brain */
Brain *Dog::getBrain(void) const {
	return (_brain);
}
