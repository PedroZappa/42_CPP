/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:56:42 by passunca          #+#    #+#             */
/*   Updated: 2024/12/12 09:11:50 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include <cstdlib> // rand()

Base::~Base(void) {
#ifdef DEBUG
	std::cout << "Base destructor called" << std::endl;
#endif
}

Base *Base::generate(void) {
	switch (rand() % 3) {
	case 0:
		return (new A());
	case 1:
		return (new B());
	case 2:
		return (new C());
	}
	return (NULL);
}

void Base::identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void Base::identify(Base &p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {
	}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {
	}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &e) {
	}
}

