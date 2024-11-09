/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:47:49 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 11:51:47 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

/** @brief Default constructor */
Cure::Cure(void) {
	this->_type = "cure";
	this->_isEquipped = false;
#ifdef DEBUG
	std::cout << YEL "Cure " BWHT << _type << NC " constructor called"
			  << std::endl;
#endif
}

/** @brief Copy constructor */
Cure::Cure(const Cure &other) {
	*this = other;
#ifdef DEBUG
	std::cout << YEL "Cure " BWHT << _type << NC " copy constructor called"
			  << std::endl;
#endif
}

/** @brief Destructor */
Cure::~Cure(void) {
#ifdef DEBUG
	std::cout << YEL "Cure " BWHT << _type << NC " destructor called"
			  << std::endl;
#endif
}

/** @brief Copy assignment operator */
Cure &Cure::operator=(const Cure &other) {
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

/** @brief Clone method */
AMateria *Cure::clone() const {
	return (new Cure(*this));
}

/** @brief Use method */
void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
