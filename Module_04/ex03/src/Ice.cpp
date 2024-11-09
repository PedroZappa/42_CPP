/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:52:04 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 11:52:56 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

/** @brief Default constructor */
Ice::Ice(void) {
	this->_type = "ice";
	this->_isEquipped = false;
#ifdef DEBUG
	std::cout << YEL "Ice " BWHT << _type << NC " constructor called"
			  << std::endl;
#endif
}

/** @brief Copy constructor */
Ice::Ice(const Ice &other) {
	*this = other;
#ifdef DEBUG
	std::cout << YEL "Ice " BWHT << _type << NC " copy constructor called"
			  << std::endl;
#endif
}

/** @brief Destructor */
Ice::~Ice(void) {
#ifdef DEBUG
	std::cout << YEL "Ice " BWHT << _type << NC " destructor called" << std::endl;
#endif
}

/** @brief Copy assignment operator */
Ice &Ice::operator=(const Ice &other) {
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

/** @brief Clone method */
AMateria *Ice::clone() const {
	return (new Ice(*this));
}

/** @brief Use method */
void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
			  << std::endl;
}
