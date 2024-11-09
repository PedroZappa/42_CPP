/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:55:36 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 17:13:21 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ground.hpp"

/** @brief Constructor */
Ground::Ground() {
	_list = NULL;
	std::cout << "Ground singleton constructor called" << std::endl;
}

/** @brief Destructor */
Ground::~Ground() {
	delMaterias();
	std::cout << "Ground singleton destructor called" << std::endl;
}

/** @brief Add Materia to Ground */
void Ground::addMateria(AMateria *materia) {
	if (materia->getIsEquipped() == true) {
		std::cout << "Materia " << materia->getType() << " is already equiped" << std::endl;
		return;
	}
	if (_list == NULL) {
		_list = new MateriasList;
		_list->materia = materia;
		_list->next = NULL;
	} else {
		MateriasList *tmp = _list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new MateriasList;
		tmp->next->materia = materia;
		tmp->next->next = NULL;
	}
	std::cout << "Materia " << materia->getType() << " added to Ground"
			  << std::endl;
}

/** @brief Delete Materia from Ground */
void Ground::delMaterias(void) {
	MateriasList *tmp;

	if (_list == NULL)
		return;
	while (_list) {
		tmp = _list;
		_list = _list->next;
		delete tmp->materia;
		delete tmp;
	}
	std::cout << "Materias deleted from Ground"
			  << std::endl;
}

/** @brief Print Materias in Ground */
void Ground::printList(void) {
	std::cout << "Materias on the Ground: " << std::endl;
}

/** @brief Drop Materias in Ground */
void Ground::dropMateria(AMateria *materia) {
	getGround().addMateria(materia);
}

/** @brief Static method to create and return the single instance of the class */
Ground &Ground::getGround(void) {
	static Ground instance;
	return (instance);
}
