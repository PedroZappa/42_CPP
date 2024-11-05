/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:16:41 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 21:07:45 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
  public:
	Cat(void);
	Cat(const Cat &copy);
	~Cat(void);

	Cat &operator=(const Cat &copy);

	Brain *getBrain() const;

	void makeSound() const;

  private:
	Brain *_brain;
};

std::ostream &operator<<(std::ostream &ofs, const Cat &rhs);

#endif
