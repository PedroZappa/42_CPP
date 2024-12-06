/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:04:34 by passunca          #+#    #+#             */
/*   Updated: 2024/12/04 16:40:26 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include <iostream>

/** Constructor **/
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
}

/** Parametarized Constructor **/
Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade) {
	if (this->_grade < GRADE_MAX)
		throw GradeTooHighException();
	if (this->_grade > GRADE_MIN)
		throw GradeTooLowException();
#ifdef DEBUG
	std::cout << GRN "Bureaucrat" BWHT << " constructor called" NC << std::endl;
#endif
}

/** Copy Constructor **/
Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	*this = other;
}

/** Destructor **/
Bureaucrat::~Bureaucrat() {
}

/** Copy assignment operator **/
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}

/** Getters **/
const std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (this->_grade <= GRADE_MAX)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade >= GRADE_MIN)
		throw GradeTooLowException();
	this->_grade++;
}

void signForm(Form &form) {
	try {
		(void)form;
	} catch (std::exception &e) {
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << YEL << bureaucrat.getName() << NC ", bureaucrat grade " GRN
	   << bureaucrat.getGrade() << NC;
	return (os);
}
