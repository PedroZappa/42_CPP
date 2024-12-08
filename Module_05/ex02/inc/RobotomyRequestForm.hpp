/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:47:11 by passunca          #+#    #+#             */
/*   Updated: 2024/12/08 10:49:08 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
  public:
	RobotomyRequestForm(const std::string &target);
	~RobotomyRequestForm(void);

	RobotomyRequestForm(const RobotomyRequestForm &src);

	void execute(void) const;
  private:
	const std::string _target;

	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
};
