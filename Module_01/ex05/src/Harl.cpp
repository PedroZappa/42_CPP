/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:03:29 by passunca          #+#    #+#             */
/*   Updated: 2024/10/22 12:17:32 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

void debug() {
  std::cout << GRN "I love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
               "really do!\n" NC;
}

void info() {
  std::cout << CYN  "I cannot believe adding extra bacon costs more money."
               "You didn’t put enough bacon in my burger! If you did, I "
               "wouldn’t be asking for more!\n" NC;
}

void warning() {
  std::cout
	  << YEL "I think I deserve to have some extra bacon for free. I’ve been "
		 "coming for years whereas you started working here since last month.\n" NC;
}

void error() {
  std::cout
	  << "This is unacceptable! I want to speak to the manager now.\n" NC;
}
