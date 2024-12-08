/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:09:01 by passunca          #+#    #+#             */
/*   Updated: 2024/12/08 17:19:44 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

/** Paramneterized Constructor **/
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {
#ifdef DEBUG
	std::cout << YEL "PresidentialPardonForm" NC " default constructor called"
			  << std::endl;
#endif
}

/** Destructor **/
PresidentialPardonForm::~PresidentialPardonForm(void) {
#ifdef DEBUG
	std::cout << RED "PresidentialPardonForm" NC " destructor called" << std::endl;
#endif
}

/** Copy constructor **/
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy), _target(copy._target) {
#ifdef DEBUG
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
#endif
	*this = copy;
}

/** Copy assignment operator **/
PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
#ifdef DEBUG
	std::cout << "PresidentialPardonForm copy assignment operator called"
			  << std::endl;
#endif
	(void)rhs; // Unused
	// Do nothing; this prevents the Form from being copied
	return (*this);
}

/** Execute method **/
void PresidentialPardonForm::execute(void) const {
#ifdef DEBUG
	std::cout << "PresidentialPardonForm execute called" << std::endl;
#endif
	std::cout << YEL << this->_target
			  << NC " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
