/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:35:03 by passunca          #+#    #+#             */
/*   Updated: 2024/11/02 12:57:49 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

/**
 * @brief ClapTrap Constructor
 */
ClapTrap::ClapTrap(void)
	: _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << BWHT "ClapTrap default constructor called ✅" << std::endl;
}

/**
 * @brief ClapTrap Parameterized Constructor
 * @param name string
 */
ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << BWHT "ClapTrap parameterized constructor called ✅" << std::endl;
}

/**
 * @brief ClapTrap Copy Constructor
 * @param copy ClapTrap
 */
ClapTrap::ClapTrap(const ClapTrap &copy) {
	*this = copy;
	std::cout << BWHT "ClapTrap copy constructor called ✅" << std::endl;
}

/**
 * @brief ClapTrap Destructor
 */
ClapTrap::~ClapTrap(void) {
	std::cout << BWHT "ClapTrap destructor called ❌" << std::endl;
}

/**
 * @brief Copy Assignment Operator Overload
 * @param rhs ClapTrap
 */
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return (*this);
}

/**
 * @brief Insertion Operator Overload
 * @param ofs
 * @param rhs ClapTrap
 */
std::ostream &operator<<(std::ostream &ofs, const ClapTrap &rhs) {
	std::cout << BWHT "ClapTrap name : " YEL << rhs.getName() << "\n" NC;
	std::cout << BWHT "Hit points : " YEL << rhs.getHitPoints() << "\n" NC;
	std::cout << BWHT "Energy points : " YEL << rhs.getEnergyPoints() << "\n" NC;
	std::cout << BWHT "Attack damage : " YEL << rhs.getAttackDamage() << "\n" NC;
	return (ofs);
}

/* @brief Getters */
std::string ClapTrap::getName(void) const {
	return (this->_name);
}
int ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}
int ClapTrap::getHitPoints(void) const {
	return (this->_hitPoints);
}
int ClapTrap::getEnergyPoints(void) const {
	return (this->_energyPoints);
}
bool ClapTrap::getStatus(void) const {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is dead!\n";
		return (false);
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " outs of energy!\n";
		return (false);
	}
	return (true);
}

/**
 * @brief ClapTrap Attack
 * @param target string
 * */
void ClapTrap::attack(const std::string &target) {
	if (!this->getStatus())
		return;
	--this->_energyPoints;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!\n";
}

/**
 * @brief ClapTrap Take Damage
 * @param amount int
 * */
void ClapTrap::takeDamage(unsigned int amount) {
	if (!this->getStatus())
		return;
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0) // avoid negative hit points
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " takes " << amount
			  << " points of damage!\n";
}

/**
 * @brief ClapTrap Be Repaired
 * @param amount int
 * */
void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->getStatus())
		return;
	--this->_energyPoints;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired for " << amount
			  << " hit points!\n";
}
