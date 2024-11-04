/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:29:35 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 18:44:05 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

/** @brief Default Constructor */
Cat::Cat(void) {
	Animal::setType("Cat");
	std::cout << CYN "Cat " BWHT << Animal::getType()
			  << NC " default constructor called " << std::endl;
}

/** @brief Copy Constructor */
Cat::Cat(const Cat &copy) : Animal(copy) {
	*this = copy;
	std::cout << CYN "Cat " BWHT << Animal::getType()
			  << NC " copy constructor called " << std::endl;
}

/** @brief Destructor */
Cat::~Cat(void) {
	std::cout << CYN "Cat " BWHT << Animal::getType()
			  << NC " destructor called " << std::endl;
}

/** @brief Copy Assignment Operator */
Cat &Cat::operator=(const Cat &copy) {
	if (this != &copy)
		Animal::operator=(copy);
	return (*this);
}

/** @brief Make sound */
void Cat::makeSound() const {
	std::cout << CYN "Cat: " BWHT << "meow!" NC << std::endl;
}
