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
* @brief Create a Zombie and announce it
* @param name Zombie's name
*/
void	randomChump(std::string name)
{
	Zombie	zombie(name);
	zombie.announce();
}
