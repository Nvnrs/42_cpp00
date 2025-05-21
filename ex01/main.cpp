#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

std::string send_prompt(std::string prompt)
{
	std::string user_input;

	std::cout << prompt << std::endl;
	getline(std::cin, user_input);
	if (std::cin.eof())
		throw 500;
	return user_input;
}

int	main()
{
	PhoneBook main_phone_book;

	main_phone_book.add();
	main_phone_book.search();
}
