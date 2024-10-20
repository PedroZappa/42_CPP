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
    int textLength = headerText.length();
    int requiredWidth = textLength + 4; // Add padding around the text
    // Manually calculate the maximum of inWidth and requiredWidth
    int width = (inWidth > requiredWidth) ? inWidth : requiredWidth;
    // Calculate the padding for centering
    int paddingTotal = width - textLength - 2; // Remaining width after accounting for text and 2 spaces
    int paddingLeft = paddingTotal / 2;
    int paddingRight = paddingTotal - paddingLeft;

    // Print Header
    std::cout << GRN;
    std::cout << std::string(width, '=') << "\n";
    std::cout << BWHT;
    std::cout << std::string(paddingLeft, ' ') << " " << headerText << " " << std::string(paddingRight, ' ') << "\n";
    std::cout << GRN;
    std::cout << std::string(width, '=') << NC << "\n";
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

