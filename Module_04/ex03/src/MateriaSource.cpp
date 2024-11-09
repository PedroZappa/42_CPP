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
#include "../inc/interface.hpp"

/** @brief Constructor */
MateriaSource::MateriaSource(void) : _source() {
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < MAX_ITEMS; i++)
		this->_source[i] = NULL;
}

/** @brief Copy Constructor */
MateriaSource::MateriaSource(const MateriaSource &copy) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (copy._source[i])
			this->_source[i] = copy._source[i]->clone();
		else
			this->_source[i] = NULL;
	}
}

/** @brief Destructor */
MateriaSource::~MateriaSource(void) {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < MAX_ITEMS; i++)
		delete this->_source[i];
}

/** @brief Copy Assignment Operator */
MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
	if (this != &copy) {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (this->_source[i])
				delete this->_source[i];
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
		if (!this->_source[i]) {
			this->_source[i] = materia;
			break;
		}
	}
}

/** @brief Create a new Materia */
AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (this->_source[i] && this->_source[i]->getType() == type) {
			std::cout << "MateriaSource " << this << " created materia " << type
					  << std::endl;
			return (this->_source[i]->clone());
		}
	}
	std::cout << "MateriaSource " << this << " does not know " << type
			  << std::endl;
	return (NULL);
}

/** @brief Print the inventory */
void MateriaSource::printInventory(int idx, std::ostream &ofs) const {
	if (idx < 0 || idx >= MAX_ITEMS)
		return;
	ofs << "Inventory: ";
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (this->_source[i])
			ofs << this->_source[i]->getType() << " ";
	}
	ofs << std::endl;
}

/** @brief Overload of the << operator */
std::ostream &operator<<(std::ostream &ofs, const MateriaSource &rhs) {
	for (int i = 0; i < MAX_ITEMS; i++)
		rhs.printInventory(i, ofs);
	return (ofs);
}
