/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:52:28 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 10:15:03 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "interface.hpp"

class AMateria {
  public:
	AMateria(void);
	AMateria(const std::string &type);
	virtual ~AMateria(void);

	AMateria &operator=(const AMateria &copy);

	std::string const &getType() const;

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target) = 0;

  protected:
	std::string _type;
};

#endif
