#include "Contact.hpp"
#include <ctype.h>
#include "utils.hpp"

bool Contact::ask_first_name()
{
	bool 		eof_detected;
	std::string user_input;

	eof_detected = false;
	while (true)
	{
		user_input = send_prompt("First name:", eof_detected);
		if (eof_detected == true)
			return false;
		if (this->set_first_name(user_input) == OK)
			break;
	}
	return (true);
}

bool Contact::ask_last_name()
{
	bool 		eof_detected;
	std::string user_input;

	eof_detected = false;
	while (true)
	{
		user_input = send_prompt("Last name:", eof_detected);
		if (eof_detected == true)
			return false;
		if (this->set_last_name(user_input) == OK)
			break;
	}
	return (true);
}

bool Contact::ask_nickname()
{
	bool 		eof_detected;
	std::string user_input;

	eof_detected = false;
	while (true)
	{
		user_input = send_prompt("Nickname:", eof_detected);
		if (eof_detected == true)
			return false;
		if (this->set_nickname(user_input) == OK)
			break;
	}
	return (true);
}

bool Contact::ask_phone_number()
{
	bool 		eof_detected;
	std::string user_input;

	eof_detected = false;
	while (true)
	{
		user_input = send_prompt("Phone number:", eof_detected);
		if (eof_detected == true)
			return false;
		if (this->set_phone_number(user_input) == OK)
			break;
	}
	return (true);
}

bool Contact::ask_darkest_secret()
{
	bool 		eof_detected;
	std::string user_input;

	eof_detected = false;
	while (true)
	{
		user_input = send_prompt("Darkest secret:", eof_detected);
		if (eof_detected == true)
			return false;
		if (this->set_darkest_secret(user_input) == OK)
			break;
	}
	return (true);
}
