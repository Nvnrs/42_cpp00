#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <string>


#include <cstdlib>

#define CONTACTS_MAX 8

class PhoneBook
{
	private :
		int 	index;
		int 	size;
		Contact	array[CONTACTS_MAX];

	public :

		PhoneBook();
		void push(Contact new_contact);
		void print();
		int length();
		bool search();
		bool	add();
		Contact *find(int index);
};
#endif