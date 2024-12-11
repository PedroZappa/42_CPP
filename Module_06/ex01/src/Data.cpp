/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:29:57 by passunca          #+#    #+#             */
/*   Updated: 2024/12/11 13:38:36 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Data.hpp"

Data::Data(void) {
#ifdef DEBUG
	std::cout << "Data constructor called" << std::endl;
#endif
}

Data::Data(const Data &copy) {
#ifdef DEBUG
	std::cout << "Data copy constructor called" << std::endl;
#endif
	*this = copy;
}

Data::~Data(void) {
#ifdef DEBUG
	std::cout << "Data destructor called" << std::endl;
#endif
}

Data &Data::operator=(const Data &other) {
#ifdef DEBUG
	std::cout << "Data assignation operator called" << std::endl;
#endif
	if (this == &other)
		return (*this);
	this->_artist = other._artist;
	this->_album = other._album;
	this->_releaseYear = other._releaseYear;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Data &data) {
	os << YEL "Data:" NC << std::endl;
	os << "artist: " << data._artist << std::endl;
	os << "album: " << data._album << std::endl;
	os << "releaseYear: " << data._releaseYear << std::endl;
	return (os);
}
