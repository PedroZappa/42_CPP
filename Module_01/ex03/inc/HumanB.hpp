/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:27:39 by passunca          #+#    #+#             */
/*   Updated: 2024/10/20 17:31:23 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Ansi.h"
#include "Weapon.hpp"

class HumanB {
  public:
	HumanB(std::string name);
	~HumanB();

	void attack(void) const;
	void setWeapon(Weapon &weapon);

  private:
	std::string _name;
	Weapon *_weapon; // May be NULL
};

#endif
