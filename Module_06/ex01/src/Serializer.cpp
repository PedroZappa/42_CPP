/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:19:48 by passunca          #+#    #+#             */
/*   Updated: 2024/12/11 13:44:30 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

Serializer::Serializer(void) {
}

Serializer::Serializer(const Serializer &copy) {
	*this = copy;
}

Serializer &Serializer::operator=(const Serializer &other) {
	(void)other;
	return (*this);
}

Serializer::~Serializer(void) {
}

/**
 * Methods
 * @see https://en.cppreference.com/w/cpp/language/reinterpret_cast
* */
uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
