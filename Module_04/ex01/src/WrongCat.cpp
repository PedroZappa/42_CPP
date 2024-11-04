/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:04:35 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 20:14:26 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

/** @brief Default Constructor */
WrongCat::WrongCat(void) : WrongAnimal() {
	WrongAnimal::setType("WrongCat");
	std::cout << CYN "WrongCat " BWHT << WrongAnimal::getType()
			  << NC " default constructor called " << std::endl;
}

/** @brief Copy Constructor */
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	*this = copy;
	std::cout << CYN "WrongCat " BWHT << WrongAnimal::getType()
			  << NC " copy constructor called " << std::endl;
}

/** @brief Destructor */
WrongCat::~WrongCat(void) {
	std::cout << CYN "WrongCat " BWHT << WrongAnimal::getType()
			  << NC " destructor called " << std::endl;
}

/** @brief Copy Assignment Operator */
WrongCat &WrongCat::operator=(const WrongCat &copy) {
	if (this != &copy)
		WrongAnimal::operator=(copy);
	return (*this);
}

/** @brief Make sound */
void WrongCat::makeSound() const {
	std::cout << CYN "WrongCat: " BWHT << "wrong meow!" NC << std::endl;
}
