/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:42:30 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 18:43:14 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

/** @brief Default Constructor */
Animal::Animal(void) : _type("Animal") {
	std::cout << GRN "Animal " BWHT << _type
			  << NC " default constructor called " << std::endl;
}

/** @brief Copy Constructor */
Animal::Animal(const Animal &copy) {
	*this = copy;
	std::cout << GRN "Animal " BWHT << _type << NC " copy constructor called "
			  << std::endl;
}

/** @brief Destructor */
Animal::~Animal(void) {
	std::cout << GRN "Animal " BWHT << _type << NC " destructor called "
			  << std::endl;
}

/** @brief Copy Assignment Operator */
Animal &Animal::operator=(const Animal &copy) {
	if (this != &copy)
		this->_type = copy._type;
	std::cout << GRN "Animal " BWHT << _type
			  << NC " copy assignment operator called " << std::endl;
	return (*this);
}

/** @brief Getters */
std::string Animal::getType() const {
	return (this->_type);
}

/** @brief Setters */
void Animal::setType(const std::string &type) {
	this->_type = type;
}

/** @brief Make sound */
void Animal::makeSound() const {
}
