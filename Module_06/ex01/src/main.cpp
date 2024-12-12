/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:44:48 by passunca          #+#    #+#             */
/*   Updated: 2024/12/11 14:14:05 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"
#include "../inc/Data.hpp"
// #include <cstdint>
#include <stdint.h>

int main()
{
	headerPrinter( "Serializer", 50, '-', YEL);
	Data *data = new Data();
	std::cout << "Print" MAG " Data" NC ": " << std::endl;
	std::cout << data << std::endl;
	sepPrinter(50, '-', GRN, 1);

	std::cout << "Print " MAG "Serialized Data" NC ": " << std::endl;
	uintptr_t raw = Serializer::serialize(data);
	std::cout << raw << std::endl;
	sepPrinter(50, '-', GRN, 1);

	std::cout << "Print " MAG "Deserialized Data" NC ": " << std::endl;
	Data *data2 = Serializer::deserialize(raw);
	std::cout << data2 << std::endl;
	sepPrinter(50, '-', GRN, 1);

	delete data;
	return (0);
}
