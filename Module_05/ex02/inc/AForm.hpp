/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:15:15 by passunca          #+#    #+#             */
/*   Updated: 2024/12/05 17:05:00 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once // Equivalent to #ifndef and #define

#include "Ansi.h"
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class Bureaucrat;

class AForm {
  public:
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	~AForm(void);

	AForm(const AForm &src);

	bool isSigned(void) const;

	std::string getName(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;

	void beSigned(const Bureaucrat &bureaucrat);

	virtual void execute(const Bureaucrat &executor) const = 0;

	/** Exceptions **/
	class GradeTooHighException : public std::exception {
	  public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	  public:
		const char *what() const throw();
	};
	class FormNotSignedException : public std::exception {
	  public:
		const char *what() const throw();
	};

  private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
	static const int GRADE_MIN = 150;
	static const int GRADE_MAX = 1;

	AForm &operator=(const AForm &rhs); // So that forms cannot be duplicated
};

std::ostream &operator<<(std::ostream &os, AForm &rhs);
