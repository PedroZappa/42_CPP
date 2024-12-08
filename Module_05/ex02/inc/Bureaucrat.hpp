/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:54:02 by passunca          #+#    #+#             */
/*   Updated: 2024/12/05 17:05:04 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Ansi.h"
#include <ostream>
#include <string>

class AForm;

class Bureaucrat {
  public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	Bureaucrat(const Bureaucrat &other);

	const std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	void signForm(AForm &form);
	void executeForm(AForm const &form) const; // TODO:

	// ** Exceptions **/
	class GradeTooHighException : public std::exception {
	  public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	  public:
		const char *what() const throw();
	};

  private:
	const std::string _name;
	int _grade;
	static const int GRADE_MIN = 150;
	static const int GRADE_MAX = 1;

	Bureaucrat &operator=(const Bureaucrat &other);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);
