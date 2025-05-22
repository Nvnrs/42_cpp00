#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>

enum e_input_status
{
	OK,
	EMPTY,
	ONLY_SPACES,
	NOT_DIGITS,
};

// INPUT
enum 		e_input_status handle_errors_input(enum e_input_status status);
enum 		e_input_status	number_input_is_valid(std::string input);
enum 		e_input_status	text_input_is_valid(std::string input);

// UTILS
std::string	send_prompt(std::string prompt, bool &eof_detected);
void		print_red(std::string text);
void		print_green(std::string text);
void		print_blue(std::string text);
void		print_gray(std::string text);
std::string	trim_spaces(std::string input);
int	str_to_int(std::string	str);

#endif