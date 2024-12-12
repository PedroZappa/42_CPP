/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:56:13 by passunca          #+#    #+#             */
/*   Updated: 2024/12/12 09:14:43 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ansi.hpp"
#include "../inc/Base.hpp"
#include <cstdlib> // rand()
#include <iostream>
#include <unistd.h>

#define WIDTH 50

int main(void) {
	headerPrinter("Identify real type", WIDTH, '-', YEL);
	for (int i = 0; i < 10; ++i) {
		Base *ptr = Base::generate();
		Base &ref = *ptr;
		Base::identify(ptr);
		Base::identify(ref);
		delete ptr;
		sepPrinter(WIDTH, '-', GRN, 1);
	}
	return (0);
}
