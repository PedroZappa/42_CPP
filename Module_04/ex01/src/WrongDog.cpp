/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:13:56 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 20:15:43 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongDog.hpp"

/** @brief Default Constructor */
WrongDog::WrongDog(void) : WrongAnimal() {
	WrongAnimal::setType("WrongDog");
	std::cout << RED "WrongDog " BWHT << WrongAnimal::getType()
			  << NC " default constructor called " << std::endl;
}

/** @brief Copy Constructor */
WrongDog::WrongDog(const WrongDog &copy) : WrongAnimal(copy) {
	*this = copy;
	std::cout << RED "WrongDog " BWHT << WrongAnimal::getType()
			  << NC " copy constructor called " << std::endl;
}

/** @brief Destructor */
WrongDog::~WrongDog(void) {
	std::cout << RED "WrongDog " BWHT << WrongAnimal::getType()
			  << NC " destructor called " << std::endl;
}

/** @brief Copy Assignment Operator */
WrongDog &WrongDog::operator=(const WrongDog &copy) {
	if (this != &copy)
		WrongAnimal::operator=(copy);
	return (*this);
}

/** @brief Make sound */
void WrongDog::makeSound() const {
	std::cout << RED "WrongDog: " BWHT << "wrong woof!" NC << std::endl;
}
