/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:39:29 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 19:47:56 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

/** @brief Default Constructor */
WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	std::cout << BGRN "WrongAnimal " BWHT << _type
			  << NC " default constructor called " << std::endl;
}

/** @brief Copy Constructor */
WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy._type) {
	std::cout << BGRN "WrongAnimal " BWHT << _type
			  << NC " copy constructor called " << std::endl;
}

/** @brief Destructor */
WrongAnimal::~WrongAnimal(void) {
	std::cout << BGRN "WrongAnimal " BWHT << _type
			  << NC " destructor called " << std::endl;
}

/** @brief Copy Assignment Operator */
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

/** @brief Getters */
std::string WrongAnimal::getType() const {
	return (this->_type);
}

/** @brief Setters */
void WrongAnimal::setType(const std::string &type) {
	this->_type = type;
}

/** @brief Make sound */
void WrongAnimal::makeSound() const {
	std::cout << "wrong\n";
}
