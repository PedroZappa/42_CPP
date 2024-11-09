/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:13:04 by passunca          #+#    #+#             */
/*   Updated: 2024/11/09 11:42:42 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "interface.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &copy);
	~MateriaSource(void);

	MateriaSource &operator=(const MateriaSource &copy);

	AMateria *getMateria(std::string const &type) const;
	void learnMateria(AMateria *materia) = 0;
	AMateria *createMateria(std::string const &type) = 0;
	void printInventory(int idx, std::ostream &ofs) const;

  private:
	AMateria *_source[MAX_ITEMS];
};

std::ostream &operator<<(std::ostream &ofs, const MateriaSource &rhs);

#endif
