/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:19:49 by passunca          #+#    #+#             */
/*   Updated: 2024/12/11 13:36:08 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include "Ansi.h"

class Data {
  public:
	Data(void);
	Data(const Data &copy);
	~Data(void);

	Data &operator=(const Data &other);

	std::string _artist;
	std::string _album;
	int _releaseYear;
};

std::ostream &operator<<(std::ostream &os, const Data &data);
