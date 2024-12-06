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
	Bureaucrat bob("Zedro", 42);
	std::cout << MAGB "Print original Bureaucrat's grade:" NC << std::endl;
	std::cout << bob << std::endl;
	std::cout << MAGB "Print incremented Bureaucrat's grade:" NC << std::endl;
	bob.incrementGrade();
	std::cout << bob << std::endl;
	std::cout << MAGB "Print decremented Bureaucrat's grade:" NC << std::endl;
	bob.decrementGrade();
	std::cout << bob << std::endl;

	// Testing GradeTooHighException
	sepPrinter(WIDTH, '-', GRN, 1);
	try {
		Bureaucrat bob2("Pappa", 0);
		std::cout << bob2 << std::endl;
		bob2.incrementGrade();
		std::cout << bob2 << std::endl;
		bob2.decrementGrade();
		std::cout << bob2 << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	// Testing GradeTooLowException
	sepPrinter(WIDTH, '-', GRN, 1);
	try {
		Bureaucrat bob3("bob3", 151);
		std::cout << bob3 << std::endl;
		bob3.incrementGrade();
		std::cout << bob3 << std::endl;
		bob3.decrementGrade();
		std::cout << bob3 << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
