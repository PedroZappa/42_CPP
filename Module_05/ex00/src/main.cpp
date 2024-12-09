/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:28:32 by passunca          #+#    #+#             */
/*   Updated: 2024/12/04 16:33:38 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include <iostream>

#define WIDTH 50

int main() {
	headerPrinter(
		"Mommy, when I grow up I wanna be a Bureaucrat!", WIDTH, '=', GRN);
	Bureaucrat zedro("Zedro", 42);
	std::cout << MAGB "Print original Bureaucrat's grade:" NC << std::endl;
	std::cout << zedro << std::endl;
	std::cout << MAGB "Print incremented Bureaucrat's grade:" NC << std::endl;
	zedro.incrementGrade();
	std::cout << zedro << std::endl;
	std::cout << MAGB "Print decremented Bureaucrat's grade:" NC << std::endl;
	zedro.decrementGrade();
	std::cout << zedro << std::endl;

	// Testing GradeTooHighException
	sepPrinter(WIDTH, '-', GRN, 1);
	try {
		Bureaucrat pappa("Pappa", 0);
		std::cout << pappa << std::endl;
		pappa.incrementGrade();
		std::cout << pappa << std::endl;
		pappa.decrementGrade();
		std::cout << pappa << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	// Testing GradeTooLowException
	sepPrinter(WIDTH, '-', GRN, 1);
	try {
		Bureaucrat buh("Buh", 151);
		std::cout << buh << std::endl;
		buh.incrementGrade();
		std::cout << buh << std::endl;
		buh.decrementGrade();
		std::cout << buh << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
