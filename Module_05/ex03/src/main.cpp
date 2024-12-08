/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:28:32 by passunca          #+#    #+#             */
/*   Updated: 2024/12/08 17:37:12 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include <iostream>

#define WIDTH 50

int main() {
	headerPrinter("󰛊 At least this beats coffee-making 󰛊", WIDTH, '=', GRN);

	Bureaucrat *bureaucrat;
	Intern intern;
	AForm *shrubbery, *robotomy, *presidential, *silly;

	shrubbery = intern.makeForm("Shrubbery", "garden");
	robotomy = intern.makeForm("Robotomy", "Marvin");
	presidential = intern.makeForm("Presidential", "Arthur Dent");
	silly = intern.makeForm("Silly", "Zedro");
	sepPrinter(WIDTH, '=', GRN, 1);

	headerPrinter("󰜎 Try to execute unsigned form 󰜎", WIDTH, '=', YEL);
	bureaucrat = (new Bureaucrat("Zedro", 33));
	bureaucrat->executeForm(*presidential);
	sepPrinter(WIDTH, '=', GRN, 1);

	headerPrinter("🖋 Try to sign forms 🖋", WIDTH, '=', YEL);
	try {
		bureaucrat->signForm(*presidential);
		sepPrinter(WIDTH, '=', GRN, 1);
		bureaucrat->signForm(*shrubbery);
		sepPrinter(WIDTH, '=', GRN, 1);
		bureaucrat->signForm(*robotomy);
		sepPrinter(WIDTH, '=', GRN, 1);
		if (silly)
			bureaucrat->signForm(*silly);
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	sepPrinter(WIDTH, '=', GRN, 1);

	headerPrinter("󰜎 Try to execute form 󰜎", WIDTH, '=', YEL);
	try {
		bureaucrat->executeForm(*presidential);
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	} catch (...) {
		std::cout << "Unknown error" << std::endl;
	}
	sepPrinter(WIDTH, '=', GRN, 1);

	delete bureaucrat;
	delete shrubbery;
	delete robotomy;
	delete presidential;
	delete silly;
	return (0);
}
