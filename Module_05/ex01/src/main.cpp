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
#include "../inc/Form.hpp"
#include <iostream>

#define WIDTH 53
#define N_BUREAUCRATZ 3
#define N_FORMZ 3

int main() {
	headerPrinter(
		"😈 Form up, you Maggots and Bureaucritize! 😈", WIDTH, '=', GRN);

	// Create Bureaucrats
	Bureaucrat *bureaucrats = static_cast<Bureaucrat *>(operator new[](
		sizeof(Bureaucrat) * N_BUREAUCRATZ));

	// Create Bureaucrats using placement new
	new (&bureaucrats[0]) Bureaucrat("Pedro", 150);
	new (&bureaucrats[1]) Bureaucrat("Zappa", 33);
	new (&bureaucrats[2]) Bureaucrat("Zedro", 1);

	// Annouce Bureaucrats
	headerPrinter("Announce Bureaucrats", WIDTH, '=', YEL);

	for (int i = 0; i < N_BUREAUCRATZ; ++i) {
		std::cout << bureaucrats[i] << std::endl;
		sepPrinter(WIDTH, '-', GRN, 1);
	}

	// Create Forms
	Form *forms =
		static_cast<Form *>(operator new[](sizeof(Form) * N_FORMZ));

	// Create Forms using placement new
	new (&forms[0]) Form("Creation Form", 149, 150);
	new (&forms[1]) Form("Init Form", 33, 33);
	new (&forms[2]) Form("Dominator Form", 1, 1);

	headerPrinter("Announce Forms", WIDTH, '=', YEL);
	for (int i = 0; i < N_FORMZ; i++) {
		std::cout << forms[i];
		sepPrinter(WIDTH, '-', GRN, 1);
	}

	// Sign Forms
	headerPrinter("Bureaucratizing", WIDTH, '=', YEL);
	for (int i = 0; i < N_FORMZ; i++) {
		bureaucrats[i].signForm(forms[i]);
		sepPrinter(WIDTH, '-', GRN, 1);
	}

	// Re-Print Form Status
	headerPrinter("Forms Status", WIDTH, '=', YEL);
	for (int i = 0; i < N_FORMZ; i++) {
		std::cout << forms[i];
		sepPrinter(WIDTH, '-', GRN, 1);
	}

	// Free Bureaucrats and Forms
	operator delete[](bureaucrats);
	operator delete[](forms);
	return (0);
}
