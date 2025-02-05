/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:39:48 by passunca          #+#    #+#             */
/*   Updated: 2024/11/03 11:02:56 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

/** @brief ScavTrap Constructor */
ScavTrap::ScavTrap(void) {
	this->_name = "ScavTrap";
	this->_type = "ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << BMAG "ScavTrap" BWHT " default constructor called ✅"
			  << std::endl;
}

/**
 * @brief ScavTrap Parameterized Constructor
 * @param name string
 * */
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_type = "ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << BMAG "ScavTrap " BWHT "parameterized constructor called ✅"
			  << std::endl;
}

/** @brief ScavTrap Copy Constructor
 * @param copy ScavTrap
 * */
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	std::cout << BMAG "ScavTrap " BWHT "copy constructor called ✅" << std::endl;
}

/** @brief ScavTrap Destructor */
ScavTrap::~ScavTrap(void) {
	std::cout << BMAG "ScavTrap " BWHT "destructor called ❌" << std::endl;
}

/**
 * @brief Copy Assignment Operator Overload
 * @param rhs ScavTrap
 * */
ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
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
 * @brief ClapTrap Attack
 * @param target string
 * */
void ScavTrap::attack(const std::string &target) {
	if (!this->getStatus("ScavTrap"))
		return;
	--this->_energyPoints;

	std::string color;
	if (this->getType() == "ScavTrap")
		color = BMAG;
	if (this->getType() == "DiamondTrap")
		color = BBLU;

	std::cout << color << this->getType() << BWHT " " << this->getName()
			  << " attacks " BRED << target << BWHT ", causing " BRED
			  << this->getAttackDamage() << BWHT " points of damage!\n";
}

/**
 * @brief Guard Gate
 * */
void ScavTrap::guardGate(void) const {
	if (!this->getStatus("ScavTrap"))
		return;

	std::string color;
	if (this->getType() == "ScavTrap")
		color = BMAG;
	if (this->getType() == "DiamondTrap")
		color = BBLU;

	std::cout << BMAG << color << this->getType() << " " << BWHT
			  << this->getName() << BWHT
			  << " is now in " BYEL "Gate keeper mode 󰊙" NC << std::endl;
}
