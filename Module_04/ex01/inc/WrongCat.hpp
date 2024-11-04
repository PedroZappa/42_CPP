/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:57:36 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 20:00:22 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
  public:
	WrongCat(void);
	WrongCat(const WrongCat &copy);
	~WrongCat(void);

	WrongCat &operator=(const WrongCat &copy);

	void makeSound() const;
};

#endif
