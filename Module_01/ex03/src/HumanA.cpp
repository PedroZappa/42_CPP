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
 * @brief HumanA:: HumanA object constructor
 * @param name human's name
 * @param weapon human's weapon
 * */
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << YEL "HumanA " GRN << _name << BWHT " with " << _weapon.getType()
			  << GRN " created \n" NC;
}

/**
 * @brief HumanA:: HumanA object destructor
 * */
HumanA::~HumanA(void)
{
	std::cout << RED "HumanA " BWHT << _name << " with " << _weapon.getType()
			  << RED " destroyed ☠☠☠\n" NC;
}

/**
 * @brief HumanA:: attack function
 * */
void HumanA::attack(void) const
{
	std::cout << GRN << _name << BWHT " attacks with their " YEL
			  << _weapon.getType() << "\n" NC;
}
