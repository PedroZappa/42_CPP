/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:04:34 by passunca          #+#    #+#             */
/*   Updated: 2024/12/08 11:19:35 by passunca         ###   ########.fr       */
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
#ifdef DEBUG
	std::cout << RED "Bureaucrat" BWHT << " destructor called" NC << std::endl;
#endif
}

/** Copy assignment operator **/
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << "Name: " MAG << bureaucrat.getName()
	   << "\n" NC "Bureaucracy Grade: " GRN << bureaucrat.getGrade() << NC;
	return (os);
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

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << YEL << _name << NC " Signed AForm " BBLU << form.getName()
				  << NC << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << NC << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.execute(*this);
		std::cout << YEL << _name << NC " Executed " BBLU << form.getName()
				  << NC << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << NC << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}
