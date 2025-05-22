#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>
#include "utils.hpp"


class Contact
{
	public :
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		
		enum e_input_status	set_first_name(std::string input);
		enum e_input_status	set_last_name(std::string input);
		enum e_input_status	set_nickname(std::string input);
		enum e_input_status	set_phone_number(std::string input);
		enum e_input_status	set_darkest_secret(std::string input);
		bool ask_first_name();
		bool ask_last_name();
		bool ask_nickname();
		bool ask_phone_number();
		bool ask_darkest_secret();
		void print();

};
#endif