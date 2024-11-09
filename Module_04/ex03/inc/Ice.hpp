/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:44:09 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 11:45:57 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
  public:
	Ice(void);
	Ice(const Ice &other);
	~Ice(void);

	Ice &operator=(const Ice &other);

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif
