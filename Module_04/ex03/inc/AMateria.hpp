/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:52:28 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 17:47:11 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include "ansi.h"
#include <iostream>

class ICharacter;

class AMateria {
  public:
	AMateria(void);
	AMateria(const std::string &type);
	virtual ~AMateria(void);

	AMateria &operator=(const AMateria &copy);

	const std::string &getType() const;
	bool getIsEquipped() const;
	void setIsEquipped(bool isEquipped);

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);

  protected:
	std::string _type;
	bool _isEquipped;
};

#endif
