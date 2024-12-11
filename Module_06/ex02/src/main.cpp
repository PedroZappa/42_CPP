/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:56:13 by passunca          #+#    #+#             */
/*   Updated: 2024/12/11 16:27:07 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/A.hpp"
#include "../inc/Ansi.hpp"
#include "../inc/B.hpp"
#include "../inc/Base.hpp"
#include "../inc/C.hpp"
#include <cstdlib> // rand()
#include <iostream>

#define WIDTH 50

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main(void) {
	headerPrinter("Identify real type", WIDTH, '-', YEL);
	srand(time(NULL));
	for (int i = 0; i < 10; ++i) {
		Base *ptr = generate();
		Base &ref = *ptr;
		identify(ptr);
		identify(ref);
		delete ptr;
		sepPrinter(WIDTH, '-', GRN, 1);
	}
	return (0);
}

Base *generate(void) {
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

void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {
	}
	try {
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {
	}
	try {
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &e) {
	}
}
