/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:39:48 by passunca          #+#    #+#             */
/*   Updated: 2024/11/02 20:13:36 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

/** @brief ScavTrap Constructor */
ScavTrap::ScavTrap(void) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << BWHT "ScavTrap default constructor called ✅" << std::endl;
}

/**
 * @brief ScavTrap Parameterized Constructor
 * @param name string
 * */
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << BWHT "ScavTrap parameterized constructor called ✅" << std::endl;
}

/** @brief ScavTrap Copy Constructor
 * @param copy ScavTrap
 * */
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	std::cout << BWHT "ScavTrap copy constructor called ✅" << std::endl;
}

/** @brief ScavTrap Destructor is virtual (see header file) */

/**
 * @brief Copy Assignment Operator Overload
 * @param rhs ScavTrap
 * */
ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return (*this);
}

/**
 * @brief ScavTrap Actions
 * @param target string
 * */
void ScavTrap::attack(const std::string &target) {
	if(this->getStatus() == false)
		return ;
	--this->_energyPoints;
	std::cout << BWHT "ScavTrap " << this->getName() << " attack " << target
			  << ", causing " << this->getAttackDamage() << " points of damage!"
			  << std::endl;
}

/**
* @brief Guard Gate
* */
void ScavTrap::guardGate(void) const {
	std::cout << BWHT "ScavTrap " << this->getName() << " is now in Gate keeper mode"
			  << std::endl;
}
