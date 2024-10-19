/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:43:28 by passunca          #+#    #+#             */
/*   Updated: 2024/10/19 12:43:42 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/* 
** NOTE: In which case is it better to allocate the Zombie    
**       on the stack or on the heap?
** WARN: Zombies must be destroyed when not needed anymore
*/

void	headerPrinter(void);
void	sepPrinter(void);

int main(void) {
	std::string zombieName;
	std::string chumpName;
	Zombie *zombie;

	headerPrinter();
	std::cout << "Name a new Zombie: ";
	std::getline(std::cin, zombieName);
	std::cout << "Name a new Chump: ";
	std::getline(std::cin, chumpName);
	
	sepPrinter();
	zombie = newZombie(zombieName);
	zombie->announce();

	randomChump(chumpName);

	delete zombie;
	return (0);
}

void	headerPrinter(void) {
	std::cout << "=========================" << std::endl;
	std::cout << "     Zedro's Zombies     " << std::endl;
	std::cout << "=========================" << std::endl;
}

void	sepPrinter(void) {
	std::cout << "=========================" << std::endl;
	std::cout << "=========================" << std::endl;
}
