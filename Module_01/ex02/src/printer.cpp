/**
 * @defgroup PrinterUtilities Utilities for printing formatted headers and separators.
 * @{
 *
 * This module provides functions to print formatted headers and separator lines
 * with adjustable widths. It is useful for creating visually appealing console
 * outputs with consistent formatting.
 *
 * @version 1.0
 */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:37:03 by passunca          #+#    #+#             */
/*   Updated: 2024/10/20 11:39:13 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

/** 
 * @brief Prints Header w/ adjustable width
 * @param headerText Header Title
 * @param inwidth Width of the header
 * */
void headerPrinter(const std::string &headerText, int inWidth)
{
	// Calculate the text length and minimum required width
	int textLen = headerText.length();
	int minWidth = textLen + 4; // Add padding around the text
	// Manually calculate the maximum of inWidth and minWidth
	int width = (inWidth > minWidth) ? inWidth : minWidth;
	// Calculate the padding for centering
	int totalPad = (width - textLen - 2); // account for text and 2 spaces
	int leftPad = (totalPad / 2);
	int rightPad = (totalPad - leftPad);

	// Print Header
	std::cout << GRN;
	std::cout << std::string(width, '=') << "\n";
	std::cout << BWHT;
	std::cout << std::string(leftPad, ' ') << " " << headerText << " "
			  << std::string(rightPad, ' ') << "\n";
	std::cout << GRN;
	std::cout << std::string(width, '=') << "\n" NC;
}

/**
 * @brief Prints a separator line
 * @param inWidth The width of the separator line
*/
void sepPrinter(int inWidth)
{
    std::cout << GRN;
    std::cout << std::string(inWidth, '=') << "\n";
    std::cout << std::string(inWidth, '=') << NC << "\n";
}

/** @} */

