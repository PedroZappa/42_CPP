/**
 * @defgroup ZombieModule Zombie Management Module
 * @{
 *
 * This module provides functionalities for creating and managing Zombie objects.
 * It includes functions to create Zombies on the stack and announce their presence.
 *
 * @version 1.0
 */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:29:24 by passunca          #+#    #+#             */
/*   Updated: 2024/10/19 12:30:12 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/**
 * @brief Create a Zombie on the stack and announce its presence.
 * 
 * This function creates a Zombie object on the stack with the given name
 * and calls its announce method to output its presence.
 * 
 * @param name The name of the Zombie.
 */
void	randomChump(std::string name)
{
	Zombie	zombie(name);
	zombie.announce();
}

/** @} */
