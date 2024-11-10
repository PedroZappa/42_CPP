/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:20:48 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 17:38:04 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

/** @brief Constructor */
Character::Character(void) : _inventory(), _name("Zedro") {
#ifdef DEBUG
	std::cout << YEL "Character " NC " constructor called" << std::endl;
#endif
}

/** @brief Parameterized Constructor */
Character::Character(const std::string &name) : _inventory(), _name(name) {
#ifdef DEBUG
	std::cout << YEL "Character " NC " constructor called" << std::endl;
#endif
}

/** @brief Copy Constructor */
Character::Character(const Character &copy) {
	*this = copy;
#ifdef DEBUG
	std::cout << YEL "Character " NC " copy constructor called" << std::endl;
#endif
}

/** @brief Destructor */
Character::~Character(void) {
#ifdef DEBUG
	std::cout << YEL "Character " NC " destructor called" << std::endl;
#endif
	for (int i = 0; i < MAX_ITEMS; i++)
		if (_inventory[i])
			delete _inventory[i];
}

/** @brief Copy Assignment Operator */
Character &Character::operator=(const Character &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (this->_inventory[i]) {
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return (*this);
}

/** @brief Overload of the << operator */
std::ostream &operator<<(std::ostream &ofs, const Character &rhs) {
#ifndef DEBUG
	ofs << "Character " << rhs.getName() << " has ";
#endif
	for (int i = 0; i < MAX_ITEMS; i++)
		if (rhs.getMateria(i))
			ofs << rhs.getMateria(i)->getType() << std::endl;
	return (ofs);
}

/** @brief Getters */
const std::string &Character::getName(void) const {
	return (this->_name);
}

/** @brief Getters */
AMateria *Character::getMateria(int idx) const {
	if (idx < 0 || idx >= MAX_ITEMS)
		return (NULL);
	return (this->_inventory[idx]);
}

/** @brief Has Materia */
bool Character::hasMateria(AMateria *materia) const {
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (_inventory[i] == materia) {
			return true;
		}
	}
	return false;
}

/** @brief Equip */
void Character::equip(AMateria *m) {
	if (!m || m->getIsEquipped()) {
		std::cout << "You can't equip an already equipped item" << std::endl;
		return;
	}
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			m->setIsEquipped(true);
			return;
		}
	}
}

/** @brief Unequip */
void Character::unequip(int idx) {
	if (idx < 0 || idx >= MAX_ITEMS || !_inventory[idx])
		return;
	Ground::dropMateria(_inventory[idx]);
	this->_inventory[idx] = NULL;
}

/** @brief Use */
void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= MAX_ITEMS || !_inventory[idx])
		return;
	this->_inventory[idx]->use(target);
}
