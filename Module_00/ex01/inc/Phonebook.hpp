/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:00:43 by passunca          #+#    #+#             */
/*   Updated: 2024/09/14 18:40:40 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <fstream>
#include <string>

# include "Ansi.h"
# include "Contact.hpp"

# define MAX_CONTACTS 8

# define HEADER "==>\tWelcome to My Awesome Phonebook!\t<==\n"
# define ARROW	"==> "

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void		add(void);
		void		search(void);

		static void	printMenu(void);
		static void	printErr(std::string msg);
		static void	prompt(std::string prompt);
		static std::string formatString(std::string str);

	private:
		Contact		_contacts[MAX_CONTACTS];
		int			_n;

		void		_display(void);
		bool		_isPrintable(std::string str);
		void		_printPhoneBook(void);
};

#endif
