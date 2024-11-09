/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:55:36 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 12:24:09 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ground.hpp"

/** @brief Constructor */
Ground::Ground() {
	_list = NULL;
	std::cout << "Ground constructor called" << std::endl;
}

/** @brief Copy Constructor */
Ground::Ground(const Ground &src) {
	*this = src;
	std::cout << "Ground copy constructor called" << std::endl;
}

/** @brief Add Materia to Ground */
void Ground::addMateria(AMateria *materia) {
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
}

/** @brief Delete Materia from Ground */
void Ground::delMaterias(AMateria *materia) {
	if (_list == NULL)
		return;
	if (_list->materia == materia) {
		MateriasList *tmp = _list;
		_list = _list->next;
		delete tmp;
		return;
	}
	MateriasList *tmp = _list;
	while ((tmp->next != NULL) && (tmp->next->materia != materia))
		tmp = tmp->next;
	if (tmp->next != NULL) {
		MateriasList *tmp2 = tmp->next;
		tmp->next = tmp2->next;
		delete tmp2;
	}
}
