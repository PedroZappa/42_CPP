/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:12:43 by passunca          #+#    #+#             */
/*   Updated: 2024/12/08 12:15:03 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
  public:
	Intern(void);
	~Intern(void);

	Intern(const Intern &src);
	const Intern &operator=(const Intern &copy);

	AForm *makeForm(std::string formName, std::string target) const;

  private:
	AForm *createShrubberyCreationForm(const std::string target) const;
	AForm *createRobotomyRequestForm(const std::string target) const;
	AForm *createPresidentialPardonForm(const std::string target) const;
};
