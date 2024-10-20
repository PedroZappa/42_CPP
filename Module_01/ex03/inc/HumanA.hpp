/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:25:24 by passunca          #+#    #+#             */
/*   Updated: 2024/10/20 17:57:55 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Ansi.h"
#include "Weapon.hpp"

class HumanA
{
  private:
	std::string _name;
	Weapon &_weapon; // Reference: cannot be NULL and cannot be changed 
  public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void attack(void) const;
};

#endif
