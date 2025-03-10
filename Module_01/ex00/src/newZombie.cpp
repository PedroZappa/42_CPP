/**
 * @defgroup ZombieCreation Zombie Creation Module
 * @{
 *
 * This module provides functionality for creating Zombie objects.
 * It includes functions to allocate and initialize Zombie instances
 * on the heap with specified names.
 *
 * @version 1.0
 */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:28:18 by passunca          #+#    #+#             */
/*   Updated: 2024/10/19 12:30:56 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/**
 * @brief Create a new Zombie on the heap.
 * 
 * This function allocates memory for a new Zombie object on the heap
 * and initializes it with the given name.
 * 
 * @param name The name of the Zombie.
 * @return Zombie* Pointer to the newly created Zombie object.
 */
Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}

/** @} */
