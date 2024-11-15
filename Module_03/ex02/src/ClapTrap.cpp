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
    std::string color;
    std::string message;

    if (this->_hitPoints == 0 || this->_energyPoints == 0) {
        if (this->_type == "ClapTrap")
            color = BGRN;
        else if (this->_type == "ScavTrap")
            color = BMAG;
        else if (this->_type == "FragTrap")
            color = BRED;

        message = (this->_hitPoints == 0) ? " is dead!\n" : " out of energy! 󱏵\n";

        std::cout << color << type << BWHT " " << this->_name << message;
        return false;
    }
    return true;
}

/**
 * @brief ClapTrap Attack
 * @param target string
 * */
void ClapTrap::attack(const std::string &target) {
    if (!this->getStatus(this->_type))
        return;
    
    --this->_energyPoints;
    std::string color;
    
    if (this->getType() == "ClapTrap")
        color = BGRN;
    else if (this->getType() == "ScavTrap")
        color = BMAG;
    else if (this->getType() == "FragTrap")
        color = BRED;

    std::cout << color << this->getType() << BWHT " " << this->getName()
              << " attacks " BRED << target << BWHT ", causing " BRED
              << this->getAttackDamage() << BWHT " points of damage!\n";
}

/**
 * @brief ClapTrap Take Damage
 * @param amount unsigned int
 * */
void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0)
	{
		std::cout << this->getType() << " " << this->_name << " is dead!\n";
		return;
	}

    this->_hitPoints = ((int)amount > this->_hitPoints) ? 0 : this->_hitPoints - amount;

    std::string color;
    
    if (this->getType() == "ClapTrap")
        color = BGRN;
    else if (this->getType() == "ScavTrap")
        color = BMAG;
    else if (this->getType() == "FragTrap")
        color = BRED;

    std::cout << color << this->getType() << " " BWHT << this->getName()
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
	std::cout << BGRN << this->_type << " " BWHT << this->_name
			  << " is repaired for " << amount << " hit points!\n";
}
