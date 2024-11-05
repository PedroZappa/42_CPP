/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:23:01 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 20:55:26 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "AAnimal.hpp"
#include <iostream>

#define MAX_IDEAS 100

class Brain {
  public:
	Brain(void);
	Brain(const Brain &copy);
	~Brain(void);

	Brain &operator=(const Brain &copy);

	int getNideas(void) const;
	std::string getIdea(void) const;
	void setIdea(std::string &idea, int idx);
	void think(void) const;

  private:
	std::string _ideas[MAX_IDEAS];
	int _nIdeas;
};

#endif
