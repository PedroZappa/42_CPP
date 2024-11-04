/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:16:41 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 20:00:24 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
  public:
	Cat(void);
	Cat(const Cat &copy);
	~Cat(void);

	Cat &operator=(const Cat &copy);

	void makeSound() const;
};

#endif
