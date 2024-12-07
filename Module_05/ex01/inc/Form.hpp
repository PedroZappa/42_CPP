/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:15:15 by passunca          #+#    #+#             */
/*   Updated: 2024/12/05 17:05:00 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ansi.h"
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

// class Bureaucrat;

class Form {
  public:
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	~Form(void);

	Form(const Form &src);
	Form &operator=(const Form &rhs);

	void beSigned(const Bureaucrat &bureaucrat);
	bool isSigned(void) const;
	void printForm(std::ostream &os) const;
	
	std::string getName(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;

	/** Exceptions **/
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
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
	static const int GRADE_MIN = 150;
	static const int GRADE_MAX = 1;
};
