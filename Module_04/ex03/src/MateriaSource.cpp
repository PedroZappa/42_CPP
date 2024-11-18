/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:13:35 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 11:36:35 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

/** @brief Constructor */
MateriaSource::MateriaSource(void) : _source() {
#ifdef DEBUG
	std::cout << CYN "MateriaSource" NC " constructor called" << std::endl;
#endif
	// for (int i = 0; i < MAX_ITEMS; i++)
	// 	this->_source[i] = NULL;
}

/** @brief Copy Constructor */
MateriaSource::MateriaSource(const MateriaSource &copy) {
#ifdef DEBUG
	std::cout << CYN "MateriaSource " NC "copy constructor called" << std::endl;
#endif
	*this = copy;
}

/** @brief Destructor */
MateriaSource::~MateriaSource(void) {
#ifdef DEBUG
	std::cout << "MateriaSource destructor called" << std::endl;
#endif
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (!this->_source[i])
			continue;
		delete this->_source[i];
	}
}

/** @brief Copy Assignment Operator */
MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
	if (this != &copy) {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (this->_source[i]) {
				delete this->_source[i];
				this->_source[i] = NULL;
			}
			if (copy._source[i])
				this->_source[i] = copy._source[i]->clone();
		}
	}
	return (*this);
}

/** @brief Getters */
AMateria *MateriaSource::getMateria(std::string const &type) const {
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (this->_source[i] && this->_source[i]->getType() == type)
			return (this->_source[i]);
	}
	return (NULL);
}

/** @brief Learn a new Materia */
void MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (this->_source[i])
			continue;
		this->_source[i] = materia;
		materia->setIsEquipped(true);
		return ;
	}
	Ground::dropMateria(materia);
}

/** @brief Create a new Materia */
AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (this->_source[i] && this->_source[i]->getType() == type) {
			AMateria *new_materia = this->_source[i]->clone();
			new_materia->setIsEquipped(false);
			std::cout << CYN "MateriaSource " NC << this << " created materia " << type
					  << " " << new_materia << std::endl;
			return (new_materia);
		}
	}
	std::cout << "MateriaSource " << this << " does not know " << type
			  << std::endl;
	return (NULL);
}

/** @brief Print the inventory */
void MateriaSource::printMateria(int idx, std::ostream &ofs) const {
	if (idx < 0 || idx >= MAX_ITEMS || !this->_source[idx])
		return;
	ofs << "Printing Materia: " << this->_source[idx]->getType() << " " << std::endl;
}

/** @brief Overload of the << operator */
std::ostream &operator<<(std::ostream &ofs, const MateriaSource &rhs) {
	for (int i = 0; i < MAX_ITEMS; i++)
		rhs.printMateria(i, ofs);
	return (ofs);
}
