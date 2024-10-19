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
 * @brief Zombie Class Constructor
 */
Zombie::Zombie(void)
{
}

/**
 * @brief Zombie Parameterized Constructor
 * @param name Zombie's name
 * @note Member Initializer List:
 - (https://en.cppreference.com/w/cpp/language/constructor)
 * - more efficient than assignment;
 * - Mandatory for const or reference inits
 */
Zombie::Zombie(std::string name) : _name(name)
{
}

/**
 * @brief Zombie Class Destructor
 */
Zombie::~Zombie(void)
{
	std::cout << "Zombie " << _name << " destroyed ☠" << std::endl;
}

/* Zombie's Public Methods */

/**
 * @brief Announce Zombie
 */
void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
