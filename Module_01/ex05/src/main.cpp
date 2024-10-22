/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:51:04 by passunca          #+#    #+#             */
/*   Updated: 2024/10/22 12:20:05 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	headerPrinter("HarlFilter", WIDTH, '-', RED);

	if (argc != 2)
	{
		std::cout << RED "Error: " BWHT "Usage: " YEL "./HarlFilter "
													  "<level>\n" NC;
		sepPrinter(WIDTH, '-', RED, 2);
		return (1);
	}

	harl.complain(argv[1]);
	sepPrinter(WIDTH, '-', GRN, 2);

	return (0);
}
