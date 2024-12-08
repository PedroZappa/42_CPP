/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:51:57 by passunca          #+#    #+#             */
/*   Updated: 2024/12/08 11:06:07 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

/** Parameterized Constructor **/
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
#ifdef DEBUG
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
#endif
}

/** Destructor **/
RobotomyRequestForm::~RobotomyRequestForm(void) {
#ifdef DEBUG
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
#endif
}

/** Copy constructor **/
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), _target(copy._target) {
#ifdef DEBUG
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
#endif
	*this = copy;
}

void RobotomyRequestForm::execute(void) const {
#ifdef DEBUG
	std::cout << "RobotomyRequestForm execute called" << std::endl;
#endif
	std:srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << YEL "[Drilling Noises...]" NC << std::endl;
	if ((std::rand() % 2) == 0)
		std::cout << YEL << _target << NC " has been robotomized successfully"
				  << std::endl;
	else
		std::cout << RED << _target << NC " robotomy failed" << std::endl;
}
