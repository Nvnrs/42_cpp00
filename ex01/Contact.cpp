#include "Contact.hpp"
#include <ctype.h>

// CHECKS
bool	string_contain_only_space(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isspace(input[i]))
			return (false);
	}
	return (true);
}

bool	string_is_not_only_digits(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return (true);
	}
	return (false);
}

enum e_field_status	name_is_valid(std::string input)
{
	if (input.empty())
		return EMPTY;
	if (string_contain_only_space(input))
		return ONLY_SPACES;
	return OK;
}

enum e_field_status	number_is_valid(std::string input)
{
	if (input.empty())
		return EMPTY;
	if (string_contain_only_space(input))
		return ONLY_SPACES;
	if (string_is_not_only_digits(input))
		return NOT_DIGITS;
	return OK;
}


// ERRORS

enum e_field_status handle_errors(enum e_field_status status)
{
	switch (status)
	{
	case EMPTY:
	std::cout << "The field can't empty !" << std::endl;
		break;
	case ONLY_SPACES:
	std::cout << "The field can't contains only spaces/tabs !" << std::endl;
		break;
	case NOT_DIGITS:
	std::cout << "The field must be contains only digits" << std::endl;
		break;
	default:
		break;
	}
	return status;	
}

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

enum e_field_status	set_field(std::string input, std::string &target, 
	enum e_field_status (*checker)(std::string))
{
	enum e_field_status status;
	status = checker(input);
	if (status != OK)
		return handle_errors(status);
	target = trim_spaces(input);
	std::cout << target << std::endl;
	return status;
}

enum e_field_status	Contact::set_first_name(std::string input)
{
	return set_field(input, this->first_name, name_is_valid);
}
enum e_field_status	Contact::set_last_name(std::string input)
{
	return set_field(input, this->last_name, name_is_valid);
}
enum e_field_status	Contact::set_nickname(std::string input)
{
	return set_field(input, this->nickname, name_is_valid);
}
enum e_field_status	Contact::set_darkest_secret(std::string input)
{
	return set_field(input, this->darkest_secret, name_is_valid);
}
enum e_field_status	Contact::set_phone_number(std::string input)
{
	return set_field(input, this->phone_number, number_is_valid);
}