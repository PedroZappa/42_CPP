/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:35:03 by passunca          #+#    #+#             */
/*   Updated: 2024/11/02 21:51:22 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

/**
 * @brief ClapTrap Constructor
 */
ClapTrap::ClapTrap(void)
	: _name("ClapTrap"), _type("ClapTrap"), _hitPoints(10), _energyPoints(10),
	  _attackDamage(0) {
	std::cout << BGRN "ClapTrap" BWHT " default constructor called ✅"
			  << std::endl;
}

/**
 * @brief ClapTrap Parameterized Constructor
 * @param name string
 */
ClapTrap::ClapTrap(std::string name)
	: _name(name), _type("ClapTrap"), _hitPoints(10), _energyPoints(10),
	  _attackDamage(0) {
	std::cout << BGRN "ClapTrap " << BWHT "parameterized constructor called ✅"
			  << std::endl;
}

/**
 * @brief ClapTrap Copy Constructor
 * @param copy ClapTrap
 */
ClapTrap::ClapTrap(const ClapTrap &copy) {
	*this = copy;
	std::cout << BGRN "ClapTrap" BWHT " copy constructor called ✅" << std::endl;
}

/**
 * @brief ClapTrap Destructor
 */
ClapTrap::~ClapTrap(void) {
	std::cout << BGRN "ClapTrap " BWHT " destructor called ❌" << std::endl;
}

/**
 * @brief Copy Assignment Operator Overload
 * @param rhs ClapTrap
 */
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_type = rhs.getType();
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
	std::cout << BWHT "ClapTrap type : " YEL << rhs.getType() << "\n" NC;
	std::cout << BWHT "Hit points : " YEL << rhs.getHitPoints() << "\n" NC;
	std::cout << BWHT "Energy points : " YEL << rhs.getEnergyPoints() << "\n" NC;
	std::cout << BWHT "Attack damage : " YEL << rhs.getAttackDamage() << "\n" NC;
	return (ofs);
}

/* @brief Getters */
std::string ClapTrap::getName(void) const {
	return (this->_name);
}
std::string ClapTrap::getType(void) const {
	return (this->_type);
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
bool ClapTrap::getStatus(std::string type) const {
	if (this->_hitPoints == 0) {
		if (this->_type == "ClapTrap")
			std::cout << BGRN << type << BWHT " " << this->_name << " is dead!\n";
		if (this->_type == "ScavTrap")
			std::cout << BMAG << type << BWHT " " << this->_name << " is dead!\n";
		return (false);
	}
	if (this->_energyPoints == 0) {
		if (this->_type == "ClapTrap")
			std::cout << BGRN << type << BWHT " " << this->_name
					  << " out of energy!\n";
		if (this->_type == "ScavTrap")
			std::cout << BMAG << type << BWHT " " << this->_name
					  << " out of energy!\n";
		return (false);
	}
	return (true);
}

/**
 * @brief ClapTrap Attack
 * @param target string
 * */
void ClapTrap::attack(const std::string &target) {
	if (!this->getStatus(this->_type))
		return;
	--this->_energyPoints;
	if (this->getType() == "ClapTrap")
		std::cout << BGRN "ClapTrap" BWHT " " << this->getName()
				  << " attacks " BRED << target << BWHT ", causing " BRED
				  << this->getAttackDamage() << BWHT " points of damage!\n";
	if (this->getType() == "ScavTrap")
		std::cout << BMAG "ScavTrap " BWHT << this->getName()
				  << " attacks " BRED << target << BWHT ", causing " BRED
				  << this->getAttackDamage() << BWHT " points of damage!\n";
}

/**
 * @brief ClapTrap Take Damage
 * @param amount int
 * */
void ClapTrap::takeDamage(unsigned int amount) {
	if (!this->getStatus(this->_type))
		return;
	this->_hitPoints -= amount;
	if (this->getHitPoints() < 0) // avoid negative hit points
		this->_hitPoints = 0;
	if (this->getType() == "ClapTrap")
		std::cout << BGRN << "ClapTrap " BWHT << this->getName()
				  << " takes " BRED << amount << BWHT " points of damage!\n" NC;
	if (this->getType() == "ScavTrap")
		std::cout << BMAG << "ScavTrap " BWHT << this->getName()
				  << " takes " BRED << amount << BWHT " points of damage!\n" NC;
}

/**
 * @brief ClapTrap Be Repaired
 * @param amount int
 * */
void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->getStatus(this->_type))
		return;
	--this->_energyPoints;
	this->_hitPoints += amount;
	std::cout << BGRN "ClapTrap " BWHT << this->_name << " is repaired for "
			  << amount << " hit points!\n";
}
