/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:12:19 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 20:13:17 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
  public:
	WrongDog(void);
	WrongDog(const WrongDog &copy);
	~WrongDog(void);

	WrongDog &operator=(const WrongDog &copy);

	void makeSound() const;
};

#endif
