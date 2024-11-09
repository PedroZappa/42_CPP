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
Dog::Dog(void) {
	AAnimal::setType("Dog");
	_brain = new Brain();
	std::cout << RED "Dog " BWHT << AAnimal::getType()
			  << NC " default constructor called " << std::endl;
}

/** @brief Copy Constructor */
Dog::Dog(const Dog &copy) : AAnimal(copy) {
	_brain = new Brain(*(copy._brain));
	std::cout << RED "Dog " BWHT << AAnimal::getType()
			  << NC " copy constructor called " << std::endl;
}

/** @brief Destructaor */
Dog::~Dog(void) {
	delete _brain;
	std::cout << RED "Dog " BWHT << AAnimal::getType()
			  << NC " destructor called " << std::endl;
}

/** @brief Copy Assignment Operator */
Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		if (_brain != NULL)
			delete _brain;
		_brain = new Brain(*(rhs._brain));
	}
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
