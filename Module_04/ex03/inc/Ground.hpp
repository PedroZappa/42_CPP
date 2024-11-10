/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:55:43 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 17:09:48 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUND_HPP
#define GROUND_HPP

#include "AMateria.hpp"

/** @brief Linked list structure to store materia pointers */
struct MateriasList {
	AMateria *materia;
	MateriasList *next;
};

/** @brief Singleton class */
class Ground {
  public:
	/** @brief Public static methods
	 * these methods can be called without creating an instance of the class */
	static void dropMateria(AMateria *materia);
	static void printList(void);

  private:
	/** Private Constructor & Destructor
	 * They are private to prevent direct instantiation and deletion of the class */
	Ground();
	~Ground();
	/* Copy constructor and assignment operator is declared private without
	 * definition because it should not be used avoid copying the singleton instance
	 * */
	Ground(const Ground &src);
	Ground &operator=(const Ground &rhs);

	/** @brief Static method to create and return the single instance of the class */
	static Ground &getGround(void);

	/** @brief Add a materia to the linked list */
	void addMateria(AMateria *materia);
	void delMaterias(void);
	void IprintList(void);

	/** Pointer to the first element of a linked list of materias */
	MateriasList *_list;
};

#endif
