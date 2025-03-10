/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:17:10 by passunca          #+#    #+#             */
/*   Updated: 2024/10/20 18:02:14 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"
#include <sstream>

/**
 * @brief Construct a new HumanB object.
 *
 * This constructor initializes a HumanB object with a given name.
 * It outputs a message indicating the creation of the HumanB object if a weapon is set.
 *
 * @param name The name of the human character.
 */
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	if (this->_weapon)
		std::cout << GRN "HumanB " YEL << _name << " with "
				  << _weapon->getType() << GRN " created " NC << std::endl;
}

/**
 * @brief Destroy the HumanB object.
 *
 * This destructor outputs a message indicating the destruction of the HumanB object.
 */
HumanB::~HumanB(void) {
	std::cout << RED "HumanB " BWHT << _name << " with " << _weapon->getType()
			  << RED " destroyed ☠☠☠" NC << std::endl;
}

/**
 * @brief Perform an attack action.
 *
 * This method outputs a message indicating that the HumanB character is
 * attacking with their equipped weapon. If no weapon is set, it indicates that
 * the character is unarmed.
 */
void HumanB::attack(void) const {
	if (_weapon == NULL)
		std::cout << BWHT << _name << " is unarmed." NC "\n";
	else
		std::cout << YEL << _name << BWHT " attacks with their " YEL
				  << _weapon->getType() << NC << std::endl;
}

/**
 * @brief Set the weapon for the HumanB character.
 *
 * This method assigns a weapon to the HumanB character.
 *
 * @param weapon A reference to the Weapon object to be equipped.
 */
void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
