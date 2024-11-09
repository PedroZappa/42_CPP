/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:22:02 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 17:28:28 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Ground.hpp"
#include "ansi.h"
#include <iostream>

#define MAX_ITEMS 4

class Character : public ICharacter {
  public:
	Character(void);
	Character(const std::string &name);
	Character(const Character &copy);
	~Character(void);

	Character &operator=(const Character &rhs);

	const std::string &getName() const;
	AMateria *getMateria(int idx) const;

	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

  private:
	AMateria *_inventory[MAX_ITEMS];
	std::string _name;
};

std::ostream &operator<<(std::ostream &ofs, const Character &rhs);

#endif
