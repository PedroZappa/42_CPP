/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:35:03 by passunca          #+#    #+#             */
/*   Updated: 2024/11/02 12:42:48 by passunca         ###   ########.fr       */
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
