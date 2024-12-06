/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:15:11 by passunca          #+#    #+#             */
/*   Updated: 2024/12/05 16:59:14 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToSign < GRADE_MAX || _gradeToExecute < GRADE_MAX)
		throw Form::GradeTooHighException();
	if (_gradeToSign > GRADE_MIN || _gradeToExecute > GRADE_MIN)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &src)
	: _name(src._name), _gradeToSign(src._gradeToSign),
	  _gradeToExecute(src._gradeToExecute) {
	*this = src;
}

Form::~Form(void) {
}

std::ostream &operator<<(std::ostream &os, const Form &rhs) {
	std::string sign = rhs.isSigned() ? "🮱 " : "❌";

	os << YEL "FORM" NC << std::endl;
	os << "Bureaucrat: " BLU << rhs.getName() << NC << std::endl;
	os << "Grade to sign: " GRN << rhs.getSignGrade() << NC << std::endl;
	os << "Grade to execute: " GRN << rhs.getExecGrade() << NC << std::endl;
	os << "Signature Status: " << sign << std::endl;
	return os;
}

/** Getters **/
void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)	
		throw Form::GradeTooLowException();
}

bool Form::isSigned(void) const {
	return (this->_signed);
}

std::string Form::getName(void) const {
	return (this->_name);
}

int Form::getSignGrade(void) const {
	return (this->_gradeToSign);
}

int Form::getExecGrade(void) const {
	return (this->_gradeToExecute);
}

/** Exceptions **/
const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}
