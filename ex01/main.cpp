#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>

#define HEADER "\
  _____  _    _  ____  _   _ ______ ____   ____   ____  _  __\n\
 |  __ \\| |  | |/ __ \\| \\ | |  ____|  _ \\ / __ \\ / __ \\| |/ /\n\
 | |__) | |__| | |  | |  \\| | |__  | |_) | |  | | |  | | ' / \n\
 |  ___/|  __  | |  | | . ` |  __| |  _ <| |  | | |  | |  <  \n\
 | |    | |  | | |__| | |\\  | |____| |_) | |__| | |__| | . \\ \n\
 |_|    |_|  |_|\\____/|_| \\_|______|____/ \\____/ \\____/|_|\\_\\\n\n"

#define MENU_PRES "Here are the available commands in the PhoneBook:\n\
- ADD: Add a new contact to the PhoneBook.\n\
- SEARCH: Search for a specific contact among the existing ones.\n\
- EXIT: Exit the PhoneBook application.\n"

void	print_header_book()
{
	print_blue(HEADER);
	print_gray(MENU_PRES);
}

void	display_menu()
{
	PhoneBook phone_book;
	std::string user_input;
	bool 		eof_detected;
	enum e_input_status status;

	eof_detected = false;
	print_header_book();
	while (true)
	{
		print_blue("------\n");
		user_input = send_prompt("▶▶ ENTER CMD :", eof_detected);
		if (eof_detected)
			return;
		status = text_input_is_valid(user_input);
		if (status != OK)
		{
			handle_errors_input(status);
			continue;
		}
		user_input = trim_spaces(user_input);
		if (user_input == "ADD")
		{
			if (!phone_book.add())
				return;
		}
		else if (user_input == "SEARCH")
		{
			if (!phone_book.search())
				return;
		}
		else if (user_input == "EXIT")
			return;
		else
			print_red("Cmd not found.\n");
	}
}

int	main()
{
	display_menu();
}

// #include <sstream>
// int	main()
// {
// 	PhoneBook phonebook;
// 	Contact new_contact;
// 	std::ostringstream index;

// 	int i = 0;
// 	while (i < 16)
// 	{
// 		index << i;
// 		new_contact.set_first_name(index.str());
// 		new_contact.set_last_name(index.str());
// 		new_contact.set_nickname(index.str());
// 		new_contact.set_phone_number(index.str());
// 		new_contact.set_darkest_secret(index.str());
// 		phonebook.push(new_contact);
// 		index.str("");
// 		i++;
// 	}
// 	phonebook.print();
// }