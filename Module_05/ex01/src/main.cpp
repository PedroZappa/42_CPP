/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:28:32 by passunca          #+#    #+#             */
/*   Updated: 2024/12/04 16:33:38 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include <iostream>

#define WIDTH 50

int main() {
	headerPrinter("Form up, you Maggots and Associate!", WIDTH, '=', GRN);
	Bureaucrat zedro("Zedro", 33);

	std::cout << YEL "Testing Bureaucrat" NC << std::endl;
	std::cout << "Name: " << zedro.getName() << std::endl;
	std::cout << "Grade: " << zedro.getGrade() << std::endl;

	// Increment grade
	zedro.incrementGrade();
	std::cout << "Incremented grade: " << zedro.getGrade() << std::endl;
	
	// Decrement grade
	zedro.decrementGrade();
	std::cout << "Decremented grade: " << zedro.getGrade() << std::endl;
	return (0);
}
