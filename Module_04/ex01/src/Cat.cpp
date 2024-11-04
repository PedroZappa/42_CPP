/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:29:35 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 21:09:52 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

/** @brief Default Constructor */
Cat::Cat(void) : _brain(new Brain()) {
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
	{
		Animal::operator=(copy);
		if (_brain != NULL)
			delete _brain;
		_brain = new Brain(*(copy._brain));
	}

	return (*this);
}

std::ostream &operator<<(std::ostream &ofs, const Cat &rhs) {
	ofs << "Type:" << rhs.getType() << std::endl;
	ofs << "Brain:" << rhs.getBrain() << std::endl;
	return (ofs);
}

/** @brief Make sound */
void Cat::makeSound() const {
	std::cout << CYN "Cat: " BWHT << "meow!" NC << std::endl;
}

/** @brief Get Brain */
Brain *Cat::getBrain(void) const {
	return (this->_brain);
}
