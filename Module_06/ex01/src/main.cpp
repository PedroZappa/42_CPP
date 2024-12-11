/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:44:48 by passunca          #+#    #+#             */
/*   Updated: 2024/12/11 13:51:32 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"
#include "../inc/Data.hpp"
// #include <cstdint>
#include <stdint.h>

int main()
{
	Data* data = new Data();
	std::cout << data << std::endl;
	uintptr_t raw = Serializer::serialize(data);
	std::cout << raw << std::endl;
	Data* data2 = Serializer::deserialize(raw);
	std::cout << data2 << std::endl;

	return (0);
}
