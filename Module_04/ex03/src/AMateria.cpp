/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:06:29 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 10:17:46 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

/** @brief Default Constructor */
AMateria::AMateria(void) {
	std::cout << YEL "AMateria " BWHT << _type << NC " constructor called"
			  << std::endl;
}

/** @brief Copy Constructor */
AMateria::AMateria(const std::string &type) : _type(type) {
	std::cout << YEL "AMateria " BWHT << _type << NC " constructor called"
			  << std::endl;
}

/** @brief Destructor */
AMateria::~AMateria(void) {
	std::cout << YEL "AMateria " BWHT << _type << NC " destructor called"
			  << std::endl;
}

/** @brief Copy Assignment Operator */
AMateria &AMateria::operator=(const AMateria &copy) {
	_type = copy._type;
	return (*this);
}

/** @brief Get Type */
std::string const &AMateria::getType() const {
	return (_type);
}
