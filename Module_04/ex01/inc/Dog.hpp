/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:18:03 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 21:04:52 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
  public:
	Dog(void);
	Dog(const Dog &copy);
	~Dog(void);

	Dog &operator=(const Dog &copy);

	Brain *getBrain() const;

	void makeSound() const;

  private:
	Brain *_brain;
};

#endif
