/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:03:29 by passunca          #+#    #+#             */
/*   Updated: 2024/10/22 14:04:22 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

/** @brief Construct a new Harl:: Harl object */
Harl::Harl() {
  std::cout << BWHT << "Harl 2.0 ";
  std::cout << GRN << " created ✅✅✅" << NC << std::endl;
}

/** @brief Destroy the Harl:: Harl object */
Harl::~Harl() {
  std::cout << BWHT << "Harl 2.0 ";
  std::cout << RED << " destroyed ☠☠☠" << NC << std::endl;
}

/** @brief Complain about DEBUG level */
void Harl::debug() {
  std::cout << GRN "I love having extra bacon for my "
                   "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
                   "really do!\n" NC;
}

/** @brief Complain level INFO */
void Harl::info() {
  std::cout << CYN "I cannot believe adding extra bacon costs more money."
                   "You didn’t put enough bacon in my burger! If you did, I "
                   "wouldn’t be asking for more!\n" NC;
}

/** @brief Complain level WARNING */
void Harl::warning() {
  std::cout << RED
      "I think I deserve to have some extra bacon for free. I’ve been "
      "coming for years whereas you started working here since last "
      "month.\n" NC;
}

/**
 * @brief Complain level ERROR
 */
void Harl::error() {
  std::cout << "This is unacceptable! I want to speak to the manager now.\n" NC;
}

void Harl::complain(std::string level) {
  void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                              &Harl::error};

  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  for (int i = 0; i < 4; i++) {
    if (level == levels[i])
      (this->*f[i])();
  }
}
