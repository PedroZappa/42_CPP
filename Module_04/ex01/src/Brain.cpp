/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:27:11 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 20:56:57 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

/** @brief Constructor ***/
Brain::Brain(void) : _nIdeas(0) {
	for (int i = 0; i < MAX_IDEAS; i++) {
		std::ostringstream oss;
		oss << "Idea " << i;
		this->_ideas[i] = oss.str(); 
	}
}

/** @brief Copy constructor ***/
Brain::Brain(const Brain &copy) {
	for (int i = 0; i < MAX_IDEAS; i++)
		this->_ideas[i] = copy._ideas[i];
	this->_nIdeas = copy._nIdeas;
}

/** @brief Destructor ***/
Brain::~Brain(void) {
}

/** @brief Copy assignment operator ***/
Brain &Brain::operator=(const Brain &copy) {
	if (this != &copy) {
		for (int i = 0; i < MAX_IDEAS; i++)
			this->_ideas[i] = copy._ideas[i];
		this->_nIdeas = copy._nIdeas;
	}
	return (*this);
}

/** @brief Get number of ideas ***/
int	Brain::getNideas(void) const {
	return (this->_nIdeas);
}

/** @brief Get idea ***/
std::string	Brain::getIdea(void) const {
	return (this->_ideas[rand() % this->_nIdeas]);
}

/** @brief Set idea ***/
void	Brain::setIdea(std::string &idea, int idx) {
	if (idx < 0 || idx >= MAX_IDEAS)
		throw std::out_of_range("Index out of bounds");
	this->_ideas[idx] = idea;
	++this->_nIdeas;
}

/** @brief Think ***/
void	Brain::think(void) const {
	std::cout << "..." << this->getIdea() << "..." << std::endl;
}
