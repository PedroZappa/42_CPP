/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:35:56 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 19:41:07 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "ansi.h"
#include <iostream>

class WrongAnimal {
  public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &copy);
	virtual ~WrongAnimal(void);

	WrongAnimal &operator=(const WrongAnimal &copy);

	std::string getType() const;
	void setType(const std::string &type);

	virtual void makeSound() const;

  protected:
	std::string _type;
};

#endif
