/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:35:03 by passunca          #+#    #+#             */
/*   Updated: 2024/11/02 12:53:44 by passunca         ###   ########.fr       */
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
	std::cout << BWHT "ClapTrap name: " YEL << rhs.getName() << NC;
  std::cout << BWHT " hit points: " YEL << rhs.getHitPoints() << NC;
  std::cout << BWHT " energy points: " YEL << rhs.getEnergyPoints() << NC;
  std::cout << BWHT " attack damage: " YEL << rhs.getAttackDamage() << NC;
  return (ofs);
}

/* @brief Getters */
std::string ClapTrap::getName(void) const { return (this->_name); }

int ClapTrap::getAttackDamage(void) const { return (this->_attackDamage); }

int ClapTrap::getHitPoints(void) const { return (this->_hitPoints); }

int ClapTrap::getEnergyPoints(void) const { return (this->_energyPoints); }

