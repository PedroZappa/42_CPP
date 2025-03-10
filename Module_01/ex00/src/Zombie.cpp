/**
 * @defgroup ZombieModule Zombie Management Module
 * @{
 *
 * This module provides functionality for creating and managing Zombie objects.
 * It includes constructors for initializing Zombies with or without names,
 * a destructor for cleanup, and methods for announcing their presence.
 *
 * @version 1.0
 */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:02:55 by passunca          #+#    #+#             */
/*   Updated: 2024/10/19 12:27:46 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/**
 * @brief Default constructor for the Zombie class.
 *
 * This constructor initializes a Zombie object without setting a name.
 */
Zombie::Zombie(void) {
}


/**
 * @brief Zombie Parameterized Constructor
 * @param name Zombie's name
 * @note Member Initializer List:
 - (https://en.cppreference.com/w/cpp/language/constructor)
 * - more efficient than assignment;
 * - Mandatory for const or reference initializations
 */
Zombie::Zombie(std::string name) : _name(name) {
}

/**
 * @brief Destructor for the Zombie class.
 *
 * This destructor outputs a message indicating that the Zombie object
 * with the specified name is being destroyed.
 */
Zombie::~Zombie(void) {
	std::cout << RED "Zombie " BWHT << _name;
	std::cout << RED " destroyed ☠☠☠" NC << "\n";
}

/**
 * @brief Announce the presence of the Zombie.
 *
 * This method outputs the Zombie's name followed by a message indicating
 * its craving for brains.
 */
void Zombie::announce(void) {
	std::cout << _name << ": " BMAG "BraiiiiiiinnnzzzZ...\n" NC;
}
/** @} */
