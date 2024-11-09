/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:45:10 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 11:45:38 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
  public:
	Cure(void);
	Cure(const Cure &other);
	~Cure(void);

	Cure &operator=(const Cure &other);

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif
