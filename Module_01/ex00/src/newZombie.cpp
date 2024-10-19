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
 * @brief Create a Zombie and return it
 * @param name Zombie's name
 * @return Zombie
 */
Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}
