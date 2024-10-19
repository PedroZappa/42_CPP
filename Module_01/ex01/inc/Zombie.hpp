/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:45:13 by passunca          #+#    #+#             */
/*   Updated: 2024/10/19 21:16:32 by passunca         ###   ########.fr       */
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
	void setName(const std::string &name);

  private:
	std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
