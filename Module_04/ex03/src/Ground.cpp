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
Ground::Ground() : _list()  {
#ifdef DEBUG
	std::cout << GRN "Ground" NC " singleton constructor called" << std::endl;
#endif
}

/** @brief Destructor */
Ground::~Ground() {
	delMaterias();
#ifdef DEBUG
	std::cout << GRN "Ground " NC "singleton destructor called" << std::endl;
#endif
}

/** @brief Add Materia to Ground */
void Ground::addMateria(AMateria *materia) {
	if (materia->getIsEquipped() == true) {
		std::cout << "Materia " << materia->getType() << " already equiped" << std::endl;
		return ;
	}
	MateriasList *tmp = new MateriasList;
	tmp->materia = materia;
	tmp->next = _list;
	_list = tmp;
#ifdef DEBUG
	std::cout << "Materia " << materia->getType() << " added to Ground"
			  << std::endl;
#endif
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
#ifdef DEBUG
	std::cout << "Materias deleted from Ground"
			  << std::endl;
#endif
}

/** @brief Print Materias in Ground */
void Ground::IprintList(void) {
	MateriasList *curr = _list;
	while (curr) {
		std::cout << curr->materia->getType() << std::endl;
		curr = curr->next;
	}
}

/** @brief Print Materias in Ground */
void Ground::printList(void) {
	std::cout << "Materias on the Ground: " << std::endl;
	getGround().IprintList();
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
