/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:34:19 by passunca          #+#    #+#             */
/*   Updated: 2025/03/02 11:22:50 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
#define LOGGER_H

#include "Ansi.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

#define _DEBUG(msg) Logger::debug(typeid(*this).name(), __func__, msg)

class Logger {
  private:
	static const std::string currentTime();
	static void printLog(const std::string &header,
						 const std::string &message,
						 bool err);

  public:
	static void debug(const std::string &message);
	static void debug(const std::string &funcName, const std::string &message);
	static void debug(const std::string &className,
					  const std::string &funcName,
					  const std::string &message);

	static void info(const std::string &message);
	static void warn(const std::string &message);
	static void error(const std::string &message);
};

/// @brief Template to print containers
/// @tparam C The container type
/// @param funcName The name of the function
/// @param contName The name of the container
/// @param cont The container
template <typename C>
void showContainer(const std::string &funcName,
				   const std::string &contName,
				   const C &cont) {
#ifndef DEBUG
	return;
#endif

	Logger::debug(funcName, "Printing container: " + contName);

	std::ostringstream output;
	typename C::const_iterator it;

	for (it = cont.begin(); it != cont.end(); ++it) {
		output << *it;
		typename C::const_iterator next = it;
		++next;
		if (next != cont.end())
			output << ", ";
		else
			output << "\n";
	}

	std::cout << output.str() << "\n";
}

#endif
