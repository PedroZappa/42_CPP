/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:15:11 by passunca          #+#    #+#             */
/*   Updated: 2024/12/08 17:33:39 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include <iostream>

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute) {
	if (_gradeToSign < GRADE_MAX || _gradeToExecute < GRADE_MAX)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > GRADE_MIN || _gradeToExecute > GRADE_MIN)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &src)
	: _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign),
	  _gradeToExecute(src._gradeToExecute) {
	*this = src;
}

AForm::~AForm(void) {
}

/** Operator Overloads **/
AForm &AForm::operator=(const AForm &rhs) {
	if (this == &rhs)
		return (*this);
	this->_signed = rhs._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, AForm &rhs) {
	std::string sign = rhs.isSigned() ? "🮱 " : "❌";

	os << YEL "FORM" NC << std::endl;
	os << "Name: " BBLU << rhs.getName() << NC << std::endl;
	os << "Grade to sign: " GRN << rhs.getSignGrade() << NC << std::endl;
	os << "Grade to execute: " GRN << rhs.getExecGrade() << NC << std::endl;
	os << "Signature Status: " << sign << std::endl;
	return os;
}

/** Getters **/
bool AForm::isSigned(void) const {
	return (this->_signed);
}

std::string AForm::getName(void) const {
	return (this->_name);
}

int AForm::getSignGrade(void) const {
	return (this->_gradeToSign);
}

int AForm::getExecGrade(void) const {
	return (this->_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	std::cout << bureaucrat << std::endl;
	std::cout << "Grade required to sign: " YEL << this->_gradeToSign << NC
			  << std::endl;
	std::cout << "Attempting to sign " GRN << this->getName() << NC << std::endl;
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	std::cout << executor << std::endl;
	std::cout << "Attempting to execute " GRN << this->getName() << NC
			  << std::endl;
	std::cout << "Grade required to sign: " YEL << this->_gradeToSign << NC
			  << std::endl;
	std::cout << "Grade required to execute: " YEL << this->_gradeToExecute
			  << NC << std::endl;
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	this->execute();
}

/** Exceptions **/
const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("Form not signed");
}
