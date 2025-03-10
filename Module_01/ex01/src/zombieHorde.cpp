/**
 * @defgroup ZombieHordeModule Zombie Horde Creation Module
 * @{
 *
 * This module provides functionality to create a horde of zombies, each with a unique name.
 * It includes a function to generate a specified number of zombies by appending a random
 * suffix to a given base name. The module ensures that each zombie has a distinct name
 * and handles cases where the base name is empty by returning NULL.
 *
 * @version 1.0
 */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:19:41 by passunca          #+#    #+#             */
/*   Updated: 2024/10/19 21:27:21 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/**
 * @brief Creates a horde of zombies with unique names.
 * 
 * This function generates a specified number of zombies, each with a unique name
 * by appending a random suffix to the provided base name. If the base name is empty,
 * the function will print an error message and return NULL.
 * 
 * @param N The number of zombies to create.
 * @param name The base name for the zombies.
 * @return A pointer to the array of created zombies, or NULL if the name is empty.
 */
Zombie *zombieHorde(int N, std::string name) {
	if (name.empty()) {
		std::cout << BWHT "Name" RED;
		std::cout << " cannot be empty" << std::endl;
		return (NULL);
	}

	Zombie *horde = new Zombie[N];
	std::string suffixes[] = {"al",
							  "el",
							  "il",
							  "ol",
							  "ul",
							  "az",
							  "ez",
							  "iz",
							  "oz",
							  "uz",
							  "ah",
							  "eh",
							  "ih",
							  "ih",
							  "oh",
							  "uh"};
	int suffixN = (sizeof(suffixes) / sizeof(suffixes[0]));

	// Seed the random number generator
	srand(static_cast<unsigned int>(time(NULL)));

	// Create zombies
	for (int i = 0; i < N; i++) {
		// Generate a random index
		int randomIndex = (rand() % suffixN);
		std::string currName = (name + suffixes[randomIndex]);
		horde[i].setName(currName);
	}
	return (horde);
}
/** @} */

