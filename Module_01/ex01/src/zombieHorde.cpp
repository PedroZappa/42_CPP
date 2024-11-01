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
 * @brief Create a Zombie horde and return it
 * @param N Number of zombies
 * @param name Zombie's name
 * @return Zombie horde
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
		int randomIndex = rand() % suffixN;
		std::string currName = name + suffixes[randomIndex];
		horde[i].setName(currName);
	}
	return (horde);
}
