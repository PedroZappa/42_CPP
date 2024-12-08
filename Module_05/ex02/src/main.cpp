/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:28:32 by passunca          #+#    #+#             */
/*   Updated: 2024/12/08 11:42:42 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include <iostream>

#define WIDTH 50
#define N_BUREAUCRATZ 3
#define N_FORMZ 3

void formTester(Bureaucrat &bureaucrat, AForm &form);

int main() {
	headerPrinter("😈 No, you need form 28B, not 28C! 😈", WIDTH, '=', GRN);

	try {
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 10);

		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur Dent");
		sepPrinter(WIDTH, '=', GRN, 1);

		// Test signing and executing with different bureaucrat levels
		headerPrinter("😈 Burocratize Intern! Do it NOW! 😈", WIDTH, '=', YEL);
		intern.signForm(shrub);
		intern.executeForm(shrub); // Should work
		sepPrinter(WIDTH, '=', GRN, 1);

		headerPrinter("😈 Burocratize Like a Boss! GO GO GO! 😈", WIDTH, '=', YEL);
		boss.signForm(robot);
		boss.executeForm(robot); // Should work
		sepPrinter(WIDTH, '=', GRN, 1);

		headerPrinter("😈 Burocracy Failure! 😈", WIDTH, '=', YEL);
		boss.signForm(pardon);
		intern.executeForm(pardon); // Should fail - grade too low
		boss.executeForm(pardon);   // Should work
		sepPrinter(WIDTH, '=', GRN, 1);

	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}

void formTester(Bureaucrat &b, AForm &f) {
	std::cout << " [ " GRN << b.getName() << NC " testing form " << f.getName()
			  << " ] " << std::endl;

	// Try to sign: Grade is too Low
	b.signForm(f);
}
