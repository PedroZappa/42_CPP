
#include "../inc/Ansi.h"
#include <iostream>

/** @brief Prints Header w/ adjustable width
 * @param headerText Header Title
 * @param inwidth Width of the header
 * */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor) {
	// Calculate minimum required width
	int textLen = headerText.length();
	int minWidth = textLen + 4; // Add padding around the text
	// Manually calculate the maximum of inWidth and minWidth
	int width = (inWidth > minWidth) ? inWidth : minWidth;
	// Calculate the padding for centering
	int totalPad = (width - textLen); // account for text
	int leftPad = (totalPad / 2);
	int rightPad = (totalPad - leftPad);

	// Print Header
	std::cout << sepColor << std::string(width, sep) << "\n";
	std::cout << BWHT << std::string(leftPad, ' ') << headerText
			  << std::string(rightPad, ' ') << "\n";
	std::cout << sepColor << std::string(width, sep) << "\n" NC;
}

/** @brief Prints a separator line
 * @param inWidth The width of the separator line
 */
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines) {
	std::cout << color;
	for (int i = 0; i < nLines; ++i) {
		std::cout << std::string(inWidth, sepChar) << "\n";
	}
	std::cout << NC;
}

/** @brief Clears the screen */
void clearScreen(void) {
	std::cout << "\033c";
}


