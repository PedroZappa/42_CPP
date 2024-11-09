/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:42:30 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 18:43:14 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

/** @brief Default Constructor */
AAnimal::AAnimal(void) : _type("AAnimal") {
	std::cout << GRN "AAnimal " BWHT << _type
			  << NC " default constructor called " << std::endl;
}

/** @brief Copy Constructor */
AAnimal::AAnimal(const AAnimal &copy) {
	*this = copy;
	std::cout << GRN "AAnimal " BWHT << _type << NC " copy constructor called "
			  << std::endl;
}

/** @brief Destructor */
AAnimal::~AAnimal(void) {
	std::cout << GRN "AAnimal " BWHT << _type << NC " destructor called "
			  << std::endl;
}

/** @brief Copy Assignment Operator */
AAnimal &AAnimal::operator=(const AAnimal &copy) {
	if (this != &copy)
		this->_type = copy._type;
	std::cout << GRN "AAnimal " BWHT << _type
			  << NC " copy assignment operator called " << std::endl;
	return (*this);
}

/** @brief Getters */
std::string AAnimal::getType() const {
	return (this->_type);
}

/** @brief Setters */
void AAnimal::setType(const std::string &type) {
	this->_type = type;
}
