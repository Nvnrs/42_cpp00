/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputValidation.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveneros <nveneros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:33:19 by nveneros          #+#    #+#             */
/*   Updated: 2025/05/21 19:26:27 by nveneros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

enum e_input_status
{
	OK,
	EMPTY,
	ONLY_SPACES,
	NOT_DIGITS,
	CTRL_D
};

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


enum e_input_status handle_errors_input(enum e_input_status status)
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

enum e_input_status	number_input_is_valid(std::string input)
{
	if (input.empty())
		return EMPTY;
	if (string_contain_only_space(input))
		return ONLY_SPACES;
	if (string_is_not_only_digits(input))
		return NOT_DIGITS;
	return OK;
}

enum e_input_status	text_input_is_valid(std::string input)
{
	if (input.empty())
		return EMPTY;
	if (string_contain_only_space(input))
		return ONLY_SPACES;
	return OK;
}
