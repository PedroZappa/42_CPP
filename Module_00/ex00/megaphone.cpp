#include <iostream>	// std::cout, std::endl

std::string ft_capitalize(const std::string &str);

/**
* @brief Broadcast the message in all CAPS
* @param str string to be converted to uppercase
* @return SUCCESS(0)
**/
int main(int argc, char **argv)
{
	std::string out = "";

	if (argc == 1)
		out += "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int word_i = 1; (word_i < argc); word_i++)
			out.append(ft_capitalize(argv[word_i]).append(" "));

	std::cout << out << std::endl;
	return (0);
}

/**
* @brief Capitalize a string
* @param str string to be converted to uppercase
* @return uppercase string
**/
std::string ft_capitalize(const std::string &str)
{
	std::string ret;

	for (unsigned int i = 0; i < str.length(); i++)
	{
		while ((str[i] == ' ') && (i < str.length()) && (i > 0)
			&& (str[i] == ' ') && ((str[i + 1] == '\0') || (str[i + 1] == ' ')))
			++i;
		ret += (char)std::toupper(str[i]);
	}

	return (ret);
}
