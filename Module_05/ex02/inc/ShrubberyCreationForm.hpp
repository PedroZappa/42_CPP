/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:07:50 by passunca          #+#    #+#             */
/*   Updated: 2024/12/08 10:42:46 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sys/stat.h>

class ShrubberyCreationForm : public AForm {
  public:
	ShrubberyCreationForm(const std::string &target);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm(const ShrubberyCreationForm &src);

	virtual void execute(void) const;

  private:
	const std::string _target;
	static const std::string _shrubbery;

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
};
