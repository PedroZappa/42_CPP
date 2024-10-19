/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:45:13 by passunca          #+#    #+#             */
/*   Updated: 2024/10/19 12:27:31 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>	// std::string
#include <iostream>	// std::cout std::endl
#include <cstdlib>	// EXIT_SUCCESS

# include "Ansi.h"

class Zombie
{
  public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void announce(void);

  private:
	const std::string _name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
