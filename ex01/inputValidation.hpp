#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <iostream>
#include <string>

enum e_input_status
{
	OK,
	EMPTY,
	ONLY_SPACES,
	NOT_DIGITS,
};

enum e_input_status handle_errors_input(enum e_input_status status);
enum e_input_status	number_input_is_valid(std::string input);
enum e_input_status	text_input_is_valid(std::string input);

#endif