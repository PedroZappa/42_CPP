/**
 * @defgroup HumanAModule HumanA Class Module
 * @{
 *
 * This module provides the implementation of the HumanA class, which represents
 * a human character equipped with a weapon. The class allows the human to attack
 * using the weapon they are equipped with. It includes methods for constructing
 * and destructing a HumanA object, as well as performing an attack action.
 *
 * @version 1.0
 */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:07:24 by passunca          #+#    #+#             */
/*   Updated: 2024/10/20 18:02:25 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

/**
 * @brief Construct a new HumanA object.
 *
 * This constructor initializes a HumanA object with a given name and weapon.
 * It outputs a message indicating the creation of the HumanA object.
 *
 * @param name The name of the human character.
 * @param weapon A reference to the Weapon object the human is equipped with.
 */
HumanA::HumanA(std::string name, Weapon &weapon)
	: _name(name), _weapon(weapon) {
	std::cout << GRN "HumanA " YEL << _name << " with " << _weapon.getType()
			  << GRN " created " NC << std::endl;
}

/**
 * @brief Destroy the HumanA object.
 *
 * This destructor outputs a message indicating the destruction of the HumanA object.
 */
HumanA::~HumanA(void) {
	std::cout << RED "HumanA " BWHT << _name << " with " << _weapon.getType()
			  << RED " destroyed ☠☠☠" NC << std::endl;
}

/**
 * @brief Perform an attack action.
 *
 * This method outputs a message indicating that the HumanA character is attacking
 * with their equipped weapon.
 */
void HumanA::attack(void) const {
	std::cout << YEL << _name << BWHT " attacks with their " YEL
			  << _weapon.getType() << NC << std::endl;
}

/** @} */
