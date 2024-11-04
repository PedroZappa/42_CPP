/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:20:01 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 18:44:00 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

/** @brief Default Constructor */
Dog::Dog(void)
{
	Animal::setType("Dog");
	std::cout << RED "Dog " BWHT << Animal::getType()
			  << NC " default constructor called " << std::endl;
}

/** @brief Copy Constructor */
Dog::Dog(const Dog &copy) : Animal(copy) {
	*this = copy;
	std::cout << RED "Dog " BWHT << Animal::getType()
			  << NC " copy constructor called " << std::endl;
}

/** @brief Destructaor */
Dog::~Dog(void) {
	std::cout << RED "Dog " BWHT << Animal::getType()
			  << NC " destructor called " << std::endl;
}

/** @brief Copy Assignment Operator */
Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		Animal::operator=(rhs);
	return (*this);
}

/** @brief Make sound */
void Dog::makeSound() const
{
	std::cout << RED "Dog: " BWHT << "woof!" NC << std::endl;
}
