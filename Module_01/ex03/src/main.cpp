/**
 * @defgroup WeaponSimulation Weapon Simulation Module
 * @{
 *
 * This module demonstrates a simple simulation of humans interacting with weapons.
 * It includes classes for HumanA and HumanB, each capable of performing attack actions
 * with a specified weapon. The module showcases how weapon types can be dynamically
 * changed and how these changes affect the behavior of the human objects.
 *
 * @version 1.0
 */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:58:55 by passunca          #+#    #+#             */
/*   Updated: 2024/10/20 17:01:40 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"
#include "../inc/Weapon.hpp"

/**
 * @brief Entry point of the program.
 * 
 * This function demonstrates the usage of HumanA and HumanB classes
 * with Weapon objects. It creates instances of HumanA and HumanB,
 * assigns weapons to them, and performs attack actions.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
	{
		// Creates an object of type HumanA;
		// HumanA must have a name and a Weapon
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		// Creates an object of type HumanB;
		// HumanB only needs a name to be initialized
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

/** @} */
