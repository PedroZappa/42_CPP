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
#include <fcntl.h> // open()
#include <unistd.h> // read()

Base::~Base(void) {
#ifdef DEBUG
	std::cout << "Base destructor called" << std::endl;
#endif
}

Base *Base::generate(void) {
	int fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0) {
		return NULL;
	}
	unsigned int random_number;
	ssize_t result = read(fd, &random_number, sizeof(random_number));
	close(fd);
	if (result != sizeof(random_number)) {
		return NULL;
	}
	switch (random_number % 3) {
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
		std::cout << YEL "A" NC << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << MAG "B" NC << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << BLU "C" NC << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void Base::identify(Base &p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << YEL "A" NC << std::endl;
	} catch (std::exception &e) {
	}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << MAG "B" NC << std::endl;
	} catch (std::exception &e) {
	}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << BLU "C" NC << std::endl;
	} catch (std::exception &e) {
	}
}
