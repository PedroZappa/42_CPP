/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:04:26 by passunca          #+#    #+#             */
/*   Updated: 2024/11/03 12:01:22 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

/**
 * @brief FragTrap default constructor
 */
FragTrap::FragTrap(void) {
	this->_name = "FragTrap";
	this->_type = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << BRED "FragTrap " BWHT "default constructor called ✅"
			  << std::endl;
}

/** @brief FragTrap parameterized constructor
 * @param name string
 */
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_type = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << BRED "FragTrap " BWHT "parameterized constructor called ✅"
			  << std::endl;
}

/** @brief FragTrap copy constructor
 * @param copy FragTrap
 */
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	std::cout << BRED "FragTrap " BWHT "copy constructor called ✅" << std::endl;
}

/** @brief FragTrap destructor */
FragTrap::~FragTrap(void) {
	std::cout << BRED "FragTrap " BWHT "destructor called ❌" << std::endl;
}

/** @brief Copy Assignment Operator Overload
 * @param rhs FragTrap
 */
FragTrap &FragTrap::operator=(const FragTrap &rhs) {
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
 * @brief Getters
 */
// int FragTrap::getHitPoints(void) {
// 	return (FragTrap::getHitPoints());
// }
//
// int FragTrap::getEnergyPoints(void) {
// 	return (FragTrap::getEnergyPoints());
// }
//
// int FragTrap::getAttackDamage(void) {
// 	return (FragTrap::getAttackDamage());
// }

/**
 * @brief ClapTrap High Fives Guys
 * @param target string
 */
void FragTrap::highFivesGuys(void) {
	if (!this->getStatus("FragTrap"))
		return;
	std::cout << BRED "FragTrap " BWHT "high five guyz! ⚡" << std::endl;
}
