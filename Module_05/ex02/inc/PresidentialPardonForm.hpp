/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:07:12 by passunca          #+#    #+#             */
/*   Updated: 2024/12/08 11:13:10 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>
#include <iostream>

class PresidentialPardonForm : public AForm {
  public:
	PresidentialPardonForm(const std::string &target);
	~PresidentialPardonForm(void);

	PresidentialPardonForm(const PresidentialPardonForm &copy);

	void execute(void) const;
private:
	std::string _target;

	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
};
