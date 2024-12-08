/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:13:24 by passunca          #+#    #+#             */
/*   Updated: 2024/12/08 11:47:33 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_shrubbery =
"       ,.,\n"
"      MMMM_    ,..,\n"
"        \"_ \"__\"MMMMM          ,...,,\n"
" ,..., __.\" --\"    ,.,     _-\"MMMMMMM\n"
"MMMMMM\"___ \"_._   MMM\"_.\"\" _ \"\"\"\"\"\"\n"
" \"\"\"\"\"    \"\" , \\_.   \"_. .\"\n"
"        ,., _\"__ \\__./ .\"\n"
"       MMMMM_\"  \"_    ./\n"
"        ''''      (    )\n"
" ._______________.-'____\"---._.\n"
"  \\                          /\n"
"   \\________________________/\n"
"   (_)                    (_)\n"
"   Corwyn Yasuo Miyagishima\n";

/** Constructor **/
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
#ifdef DEBUG
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
#endif
}

/** Destructor **/
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
#ifdef DEBUG
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
#endif
}

/** Copy constructor **/
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), _target(src._target) {
#ifdef DEBUG
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
#endif
	*this = src;
}

/** Copy assignment operator **/
ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
#ifdef DEBUG
	std::cout << "ShrubberyCreationForm copy assignment operator called"
			  << std::endl;
#endif
	(void)rhs; // Unused
	// Do nothing; this prevents thew Form from being copied
	return (*this);
}

void ShrubberyCreationForm::execute(void) const {
#ifdef DEBUG
	std::cout << "ShrubberyCreationForm execute called" << std::endl;
#endif
	std::string filename = (this->_target + "_shrubbery");
	std::ofstream ofs;

	// Attempt to open the file
	// Open file for writting, if file exists truncate (delete) contents
	ofs.open(filename.c_str(), std::ios::out | std::ios::trunc);
	if (!ofs.is_open())
		throw std::runtime_error("Failed to create/open file");

	// Check if file is valid
	struct stat info;
	if (stat(filename.c_str(), &info) != 0)
	{
		std::cerr << "Failed to create/open " << filename << std::endl;
		return ;
	}
	ofs << this->_shrubbery;
	ofs.close();
}
