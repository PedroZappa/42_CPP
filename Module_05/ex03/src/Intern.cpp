/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:08:31 by passunca          #+#    #+#             */
/*   Updated: 2024/12/08 17:26:58 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern(void) {
#ifdef DEBUG
	std::cout << BBLU "Intern" NC " constructor called" << std::endl;
#endif
}

Intern::~Intern(void) {
#ifdef DEBUG
	std::cout << BRED "Intern" NC " destructor called" << std::endl;
#endif
}

Intern::Intern(const Intern &src) {
#ifdef DEBUG
	std::cout << BBLU "Intern" NC " copy constructor called" << std::endl;
#endif
	*this = src;
}

const Intern &Intern::operator=(const Intern &copy) {
#ifdef DEBUG
	std::cout << BBLU "Intern" NC " copy assignment operator called" << std::endl;
#endif
	(void)copy;
	return (*this);
}

AForm *Intern::makeForm(const std::string &formName,
						const std::string &target) const {
	const std::string formTypes[3] = {"Shrubbery", "Robotomy", "Presidential"};
	int formI = 0;

	while ((formI < 3) && (formTypes[formI] != formName))
		++formI;
	if (formI == 3) {
		std::cout << BRED << formName << " is an Unknown form type\n" NC;
		return (NULL);
	}

	// Array of function pointers
	AForm *(Intern::*formList[3])(const std::string &target)
		const = {&Intern::createShrubberyCreationForm,
				 &Intern::createRobotomyRequestForm,
				 &Intern::createPresidentialPardonForm};

	std::cout << BBLU "Intern" NC " creates " << formTypes[formI] << " form" << std::endl; 

	return ((this->*formList[formI])(target));
}

/** Exceptions **/
const char *Intern::UnknownFormException::what() const throw() {
	return (BRED "Unknown form type\n" NC);
}

/** Factory methods **/
AForm *Intern::createShrubberyCreationForm(const std::string &target) const {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) const {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) const {
	return (new PresidentialPardonForm(target));
}
