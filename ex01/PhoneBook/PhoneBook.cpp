#include "PhoneBook.hpp"
#include "utils.hpp"

bool PhoneBook::search()
{
	int					index;
	Contact				*contact;
	std::string			index_str;
	e_input_status		status;
	bool				eof_detected;

	if (this->length() == 0)
	{
		std::cout << "The Phonebook are empty" << std::endl;
		return true;
	}
	eof_detected = false;
	this->print();
	while (true)
	{
		index_str = send_prompt("Select a contact with index :", eof_detected);
		if (eof_detected)
			return false;
		status = number_input_is_valid(index_str);
		if (status != OK)
		{
			handle_errors_input(status);
			continue;
		}
		index = str_to_int(index_str);
		contact = this->find(index);
		if (contact == NULL)
		{
			print_red("The contact doesn't exist.\n");
			continue;
		}
		contact->print();
		break;
	}
	return true;
}
int PhoneBook::length()
{
	return this->size;
}
PhoneBook::PhoneBook()
{
	this->index = 0;	
	this->size = 0;	
}

Contact *PhoneBook::find(int index)
{
	Contact *contact_find;

	contact_find = NULL;
	if (index < 0 || index >= this->size)
		return contact_find;
	return &this->array[index];
}

void PhoneBook::push(Contact new_contact)
{
	this->array[this->index] = new_contact;
	this->index++;
	if (this->index == CONTACTS_MAX)
		this->index = 0;
	if (this->size != CONTACTS_MAX)
		this->size++;
}


bool PhoneBook::add()
{
	Contact new_contact;

	if (!new_contact.ask_first_name())
	    return false;
	if (!new_contact.ask_last_name())
	    return false;
	if (!new_contact.ask_nickname())
	    return false;
	if (!new_contact.ask_phone_number())
	    return false;
	if (!new_contact.ask_darkest_secret())
	    return false;
	this->push(new_contact);
	return true;
}