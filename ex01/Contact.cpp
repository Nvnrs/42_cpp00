#include "Contact.hpp"
#include <ctype.h>
std::string send_prompt(std::string prompt);

// CLEAN VALUE
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
// SET FIELDS

enum e_input_status	set_field(std::string input, std::string &target, 
	enum e_input_status (*checker)(std::string))
{
	enum e_input_status status;
	status = checker(input);
	if (status != OK)
		return handle_errors_input(status);
	target = trim_spaces(input);
	return status;
}

enum e_input_status	Contact::set_first_name(std::string input)
{
	return set_field(input, this->first_name, text_input_is_valid);
}
enum e_input_status	Contact::set_last_name(std::string input)
{
	return set_field(input, this->last_name, text_input_is_valid);
}
enum e_input_status	Contact::set_nickname(std::string input)
{
	return set_field(input, this->nickname, text_input_is_valid);
}
enum e_input_status	Contact::set_darkest_secret(std::string input)
{
	return set_field(input, this->darkest_secret, text_input_is_valid);
}
enum e_input_status	Contact::set_phone_number(std::string input)
{
	return set_field(input, this->phone_number, number_input_is_valid);
}

// PRINT
void Contact::print()
{
	std::cout << "First name :" << this->first_name << std::endl;
	std::cout << "Last name :" << this->last_name << std::endl;
	std::cout << "Nickname :" << this->nickname << std::endl;
	std::cout << "Phone number :" << this->phone_number << std::endl;
	std::cout << "Darkest secret :" << this->darkest_secret << std::endl;
}
