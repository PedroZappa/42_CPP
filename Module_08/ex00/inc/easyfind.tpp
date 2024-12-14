// vim: set filetype=cpp:
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:15:14 by passunca          #+#    #+#             */
/*   Updated: 2024/12/14 09:15:15 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

// Template Definition
template <typename T> typename T::value_type easyfind(T &container, int n) {
	typename T::iterator it;
  it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw NotFound();
	return (*it);
}

#endif
