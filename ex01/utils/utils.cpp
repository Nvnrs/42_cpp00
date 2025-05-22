#include "utils.hpp"
#include <sstream>

int	str_to_int(std::string	str)
{
	int					index;
	std::stringstream	index_stream;

	index_stream << str;
	index_stream >> index;
	return index;
}

void	print_red(std::string text)
{
	std::cout << "\033[31m" << text << "\033[0m";
}

void	print_green(std::string text)
{
	std::cout << "\033[32m" << text << "\033[0m";
}

void	print_blue(std::string text)
{
	std::cout << "\033[34m" << text << "\033[0m";
}

void	print_gray(std::string text)
{
	std::cout << "\033[2m" << text << "\033[0m";
}

std::string send_prompt(std::string prompt, bool &eof_detected)
{
	std::string user_input;

	// print_blue(prompt);
	std::cout << prompt;
	getline(std::cin, user_input);
	if (std::cin.eof())
		eof_detected = true;
	return user_input;
}

std::string	remove_spaces_at_end(std::string input)
{
	std::string output;

	for (long i = input.length() -1; i >= 0; i--)
	{
		if (!std::isspace(input[i]))
			return output = input.substr(0, i + 1);
	}
	return input;
}

std::string	remove_spaces_from_start(std::string input)
{
	std::string output;
	long len;

	len = input.length();
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isspace(input[i]))
			return output = input.substr(i, len);
		len--;
	}
	return input;
}

std::string	trim_spaces(std::string input)
{
	std::string output;

	output = remove_spaces_from_start(input);
	output = remove_spaces_at_end(output);
	return output;
}
