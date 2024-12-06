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
#include <ostream>
#include <string>

class Bureaucrat;

class Form {
  public:
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	~Form(void);

	Form(const Form &src);
	Form &operator=(Form const &rhs);

	void beSigned(const Bureaucrat &bureaucrat);
	bool isSigned(void) const; // TODO: TO IMPLEMENT
	
	std::string getName(void) const; // TODO:L TO IMPLEMENT
	int getSignGrade(void) const; // TODO: TO IMPLEMENT
	int getExecGrade(void) const; // TODO: TO IMPLEMENT

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
