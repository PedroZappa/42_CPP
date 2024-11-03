/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:24:23 by passunca          #+#    #+#             */
/*   Updated: 2024/11/03 12:24:43 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

/** @brief DiamondTrap Default Constructor */
DiamondTrap::DiamondTrap(void)
	: ClapTrap("DiamondTrap_clap_name"), FragTrap(), ScavTrap() {
	FragTrap frag("tempFrag");
	this->_name = "DiamondTrap_clap_name";
	ClapTrap::_name = this->_name;
	this->_type = "DiamondTrap";
	this->_hitPoints = frag.getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = frag.getAttackDamage();
	std::cout << BBLU "DiamondTrap" BWHT " default constructor called ✅"
			  << std::endl;
}

/** @brief DiamondTrap Parameterized Constructor
 * @param name
 */
DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	FragTrap frag("tempFrag");
	this->_name = name + "_clap_name";
	ClapTrap::_name = this->_name;
	this->_type = "DiamondTrap";
	this->_hitPoints = frag.getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = frag.getAttackDamage();
	std::cout << BBLU "DiamondTrap" BWHT " parameterized constructor called "
										 "✅" NC
			  << std::endl;
}

/** @brief DiamondTrap Copy Constructor
 * @param copy
 */
DiamondTrap::DiamondTrap(const DiamondTrap &copy)
	: ClapTrap(copy), FragTrap(copy), ScavTrap(copy) {
	*this = copy;
	std::cout << BBLU "ClapTrap" BWHT " copy constructor called ✅" NC
			  << std::endl;
}

/** @brief DiamondTrap Destructor
 */
DiamondTrap::~DiamondTrap(void) {
	std::cout << BBLU "DiamondTrap" BWHT " destructor called ❌" NC << std::endl;
}

/** @brief DiamondTrap Copy Assignment Operator Overload
 * @param rhs
 */
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		this->_name = rhs._name; // rhs.ClapTrap::getName();
		this->_type = rhs.getType();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return (*this);
}

/** @brief Insertion Operator Overload
 * @param ofs
 */
std::ostream &operator<<(std::ostream &ofs, const DiamondTrap &rhs) {
	std::cout << BWHT "DiamondTrap name: " YEL << rhs.getName() << NC << std::endl
			  << BWHT "ClapTrap name: " YEL << rhs.ClapTrap::getName() << NC
			  << std::endl
			  << BWHT "DiamondTrap type: " YEL << rhs.getType() << NC << std::endl
			  << BWHT "DiamondTrap hit points: " YEL << rhs.getHitPoints() << NC
			  << std::endl
			  << BWHT "DiamondTrap energy points: " YEL << rhs.getEnergyPoints()
			  << NC << std::endl
			  << BWHT "DiamondTrap attack damage: " << YEL
			  << rhs.getAttackDamage() << NC << std::endl;
	return (ofs);
}

/** @brief DiamondTrap Copy Constructor
 */
void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

/** @brief DiamondTrap whoAmI
 */
void DiamondTrap::whoAmI(void) {
	std::cout << "I am " << this->_name << " and my ClapTrap name is "
			  << ClapTrap::_name << std::endl;
}
