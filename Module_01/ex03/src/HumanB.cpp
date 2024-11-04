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
 * @brief HumanB:: HumanB object constructor
 * @param name human's name
 * */
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	if (this->_weapon)
		std::cout << GRN "HumanB " YEL << _name << " with "
				  << _weapon->getType() << GRN " created " NC << std::endl;
}

/**
 * @brief HumanB:: HumanB object destructor
 * */
HumanB::~HumanB(void) {
	std::cout << RED "HumanB " BWHT << _name << " with " << _weapon->getType()
			  << RED " destroyed ☠☠☠" NC << std::endl;
}

/**
 * @brief HumanB:: attack function
 * */
void HumanB::attack(void) const {
	if (_weapon == NULL)
		std::cout << BWHT << _name << " is unarmed." NC "\n";
	else
		std::cout << YEL << _name << BWHT " attacks with their " YEL
				  << _weapon->getType() << NC << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
