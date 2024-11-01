/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:14:46 by passunca          #+#    #+#             */
/*   Updated: 2024/10/20 20:56:57 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Replace.hpp"

static void checkArgs(int argc, char **argv);
static void usage(void);
static std::string readFile(const std::string &filename);
static std::string replace(const std::string &in,
						   const std::string &toReplace,
						   const std::string &replaceWith);
static void writeToFile(const std::string filename, const std::string &content);

int main(int argc, char **argv) {
	headerPrinter("Sed is for loosers", WIDTH, '*', BGRN);
	try {
		std::cout << "Checking input arguments...\n";
		checkArgs(argc, argv);
		std::string toReplace = argv[2];
		std::string replaceWith = argv[3];
		sepPrinter(WIDTH, '-', YEL, 1);
		std::cout << "Reading " BWHT << argv[1] << NC " file...\n";
		std::string in = readFile(argv[1]);

		sepPrinter(WIDTH, '-', YEL, 1);
		std::cout << "Replacing '" YEL << toReplace << NC "' with '" GRN
				  << replaceWith << NC "' in " BWHT << argv[1]
				  << NC " file...\n";
		std::string out = replace(in, toReplace, replaceWith);

		sepPrinter(WIDTH, '-', YEL, 1);
		std::cout << "Writing to '" BWHT << argv[1]
				  << ".replace'" NC " file...\n";
		writeToFile(argv[1], out);
		headerPrinter("Exiting now...", WIDTH, '*', HMAG);
	} catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << "\n" NC;
		sepPrinter(WIDTH, '.', BRED, 1);
		usage();
		return (EXIT_FAILURE);
	}
}

/**
 * @brief Check arguments
 * @param argc
 * @param argv
 * @throw std::invalid_argument
 */
static void checkArgs(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << RED "Error: Wrong number of arguments\n" NC;
		throw std::invalid_argument("Wrong number of arguments");
	}
	std::string toCheck = argv[2];
	if (toCheck.empty()) {
		std::cerr << RED "Error: Empty string\n" NC;
		throw std::invalid_argument("Empty string");
	}
}

/**
 * @brief Print usage
 */
static void usage(void) {
	std::cout << "Usage: ./replace <filename> <toReplace> <replaceWith>\n";
}

/**
 * @brief Read file
 * @param filename name of file to read from
 * @return std::string
 */
static std::string readFile(const std::string &filename) {
	std::ifstream file;
	std::string content;
	std::string buffer;

	file.open(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Failed to open file");
	else {
		while (std::getline(file, buffer))
			content.append(buffer + "\n");
		file.close();
		return (content);
	}
	return (NULL);
}

/**
 * @brief Replace all occurrences of toReplace with replaceWith in in file
 * @param in
 * @param toReplace
 * @param replaceWith
 * @return std::string
 */
static std::string replace(const std::string &in,
						   const std::string &toReplace,
						   const std::string &replaceWith) {
	std::string out;
	size_t nextReplace = 0;
	size_t start = 0;

	while ((nextReplace = in.find(toReplace, start)) != std::string::npos) {
		out.append(in, start, (nextReplace - start)); // append before/in-between
		out.append(replaceWith);                      // append replaceWith
		start = (nextReplace + toReplace.length());   // skip to_replace
	}
	out.append(in, start, in.length() - start); // append rest
	return (out);
}

/**
 * @brief Write content to filename
 * @param filename
 * @param content
 */
static void writeToFile(const std::string filename, const std::string &content) {
	std::ofstream out;
	std::string newFilename;

	newFilename = filename + ".replace";
	out.open(newFilename.c_str());
	if (!out.is_open())
		throw std::runtime_error("Failed to open file");
	else {
		out << content;
		out.close();
	}
}
