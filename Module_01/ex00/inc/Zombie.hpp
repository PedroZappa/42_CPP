/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:45:13 by passunca          #+#    #+#             */
/*   Updated: 2024/10/19 11:49:26 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
  public:
	Zombie(void);
	~Zombie(void);

	Zombie(std::string name);
	void announce(void);

  private:
	std::string _name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
