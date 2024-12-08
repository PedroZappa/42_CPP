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
#include <iostream>

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute) {
	if (_gradeToSign < GRADE_MAX || _gradeToExecute < GRADE_MAX)
		throw Form::GradeTooHighException();
	if (_gradeToSign > GRADE_MIN || _gradeToExecute > GRADE_MIN)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &src)
	: _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign),
	  _gradeToExecute(src._gradeToExecute) {
	*this = src;
}

Form::~Form(void) {
}

/** Operator Overloads **/
Form &Form::operator=(const Form &rhs) {
	if (this == &rhs)
		return (*this);
	this->_signed = rhs._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, Form &rhs) {
	std::string sign = rhs.isSigned() ? "🮱 " : "❌";

	os << YEL "FORM" NC << std::endl;
	os << "Name: " BBLU << rhs.getName() << NC << std::endl;
	os << "Grade to sign: " GRN << rhs.getSignGrade() << NC << std::endl;
	os << "Grade to execute: " GRN << rhs.getExecGrade() << NC << std::endl;
	os << "Signature Status: " << sign << std::endl;
	return os;
}

/** Getters **/
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

void Form::beSigned(const Bureaucrat &bureaucrat) {
	std::cout << bureaucrat << std::endl;
	std::cout << "Attempting to sign\n" GRN << *this << NC << std::endl;
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

/** Exceptions **/
const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}
