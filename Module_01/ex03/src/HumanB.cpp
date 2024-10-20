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

/**
 * @brief HumanB:: HumanB object constructor
 * @param name human's name
 * */
HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << GRN "HumanB " YEL << _name << " with "
			  << _weapon->getType() << GRN " created \n" NC;
}

/**
 * @brief HumanB:: HumanB object destructor
 * */
HumanB::~HumanB(void)
{
	std::cout << RED "HumanB " BWHT << _name << " with " << _weapon->getType()
			  << RED " destroyed ☠☠☠\n" NC;
}

/**
 * @brief HumanB:: attack function
 * */
void HumanB::attack(void) const
{
	if (_weapon == NULL)
		std::cout << BWHT << _name << " is unarmed." NC "\n";
	else
		std::cout << YEL << _name << BWHT " attacks with their " YEL
				  << _weapon->getType() << NC "\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
