/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:19:32 by passunca          #+#    #+#             */
/*   Updated: 2024/10/20 12:34:31 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
  public:
	Weapon(std::string type);
	~Weapon(void);

	void setType(std::string newType);      // Sets _type
	const std::string &getType(void) const; // Gets a reference to _type

  private:
	std::string _type;
};

#endif
