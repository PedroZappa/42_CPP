/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:19:41 by passunca          #+#    #+#             */
/*   Updated: 2024/10/19 20:27:09 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << BWHT << "N" << RED;
		std::cout << " must be greater than 0" << NC << std::endl;
		return (NULL);
	}
	if (name.empty())
	{
		std::cout << BWHT << "Name" << RED;
		std::cout << " cannot be empty" << std::endl;
		return (NULL);
	}
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
