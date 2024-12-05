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
	Form(void);
	Form(std::string name, int gradeToSign, int gradeToExecute);
	~Form(void);

	Form(Form const &src);
	Form &operator=(Form const &rhs);

	void beSigned(const Bureaucrat &bureaucrat);

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
	int const _gradeToSign;
	int const _gradeToExecute;
};
