/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:03:29 by passunca          #+#    #+#             */
/*   Updated: 2024/10/22 14:17:52 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

/** @brief Construct a new Harl:: Harl object */
Harl::Harl()
{
	std::cout << BWHT << "Harl 2.0 ";
	std::cout << GRN << " created ✅✅✅" << NC << std::endl;
}

/** @brief Destroy the Harl:: Harl object */
Harl::~Harl()
{
	std::cout << BWHT << "Harl 2.0 ";
	std::cout << RED << " destroyed ☠☠☠" << NC << std::endl;
}

/** @brief Complain about DEBUG level */
void Harl::debug()
{
	headerPrinter("[ DEBUG ]", WIDTH, ' ', BWHT);
	std::cout << YEL "I love having extra bacon for my\n"
					 "7XL-double-cheese-triple-pickle-special-ketchup\n"
					 "burger. I really do!\n\n" NC;
}

/** @brief Complain level INFO */
void Harl::info()
{
	headerPrinter("[ INFO ]", WIDTH, ' ', BWHT);
	std::cout << YEL "I cannot believe adding extra bacon costs\n"
					 "more money.\nYou didn’t put enough bacon\n"
					 "in my burger! If you did, I wouldn’t be\n"
					 "asking for more!\n\n" NC;
}

/** @brief Complain level WARNING */
void Harl::warning()
{
	headerPrinter("[ WARNING ]", WIDTH, ' ', BWHT);
	std::cout << YEL "I think I deserve to have some extra\n"
					 "bacon for free. I’ve been coming for years\n"
					 "whereas you started working here since "
					 "last\nmonth.\n\n" NC;
}

/** @brief Complain level ERROR */
void Harl::error()
{
	headerPrinter("[ ERROR ]", WIDTH, ' ', BWHT);
	std::cout << YEL "This is unacceptable! I want to speak to\n"
					 "the manager now.\n\n" NC;
}

/**
 * @brief Harl 2.0 Complain
 * @param level
 */
void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int lvl = DEBUG;
	while ((lvl < ERROR) && (levels[lvl] != level))
		lvl++;
	switch (lvl)
	{
	case DEBUG:
		Harl::debug();
		break;
	case INFO:
		Harl::info();
		break;
	case WARNING:
		Harl::warning();
		break;
	case ERROR:
		Harl::error();
		break;
	default:
		std::cout << BWHT "[ Who knows, probably complaining about stuff ]\n" NC;
	}
}