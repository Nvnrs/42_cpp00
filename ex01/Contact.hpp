#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>

enum e_field_status
{
	OK,
	EMPTY,
	ONLY_SPACES,
	NOT_DIGITS,
};

class Contact
{
	public :
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		
		enum e_field_status	set_first_name(std::string input);
		enum e_field_status	set_last_name(std::string input);
		enum e_field_status	set_nickname(std::string input);
		enum e_field_status	set_phone_number(std::string input);
		enum e_field_status	set_darkest_secret(std::string input);
};
#endif