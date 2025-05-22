#include "PhoneBook.hpp"
#include <sstream>

enum e_border_col
{
	BORDER_NONE,
	BORDER_LEFT,
	BORDER_RIGHT,
	BORDER_LEFT_RIGHT,
};

#define COL_MAX 10

std::string create_empty_col()
{
	std::string col;

	while (col.length() != COL_MAX)
		col += ' ';
	return col;
}


void	add_text_in_col(std::string text, std::string &col)
{
	int i_col;
	int i_text;

	i_col = col.length() - 1;
	i_text = text.length() - 1;
	while (i_text >= 0)
	{
		col[i_col] = text[i_text];
		i_col--;
		i_text--;
	}
}

std::string create_col(std::string text)
{
	std::string col;

	col = create_empty_col();
	if (text.length() > (col.length()))
	{
		text = text.substr(0, col.length());
		text[text.length() - 1] = '.';
	}
	add_text_in_col(text, col);
	return (col);
}


void print_col(std::string info, enum e_border_col borders_config)
{
	std::string col;

	col = create_col(info);
	if (borders_config == BORDER_LEFT 
		|| borders_config == BORDER_LEFT_RIGHT)
		std::cout << "|";
	std::cout << col;
	if (borders_config == BORDER_RIGHT 
		|| borders_config == BORDER_LEFT_RIGHT)
		std::cout << "|";
}

void print_line(int index, Contact contact)
{
	std::ostringstream index_stream;

	index_stream << index;
	print_col(index_stream.str(), BORDER_LEFT);
	print_col(contact.first_name, BORDER_LEFT);
	print_col(contact.last_name, BORDER_LEFT);
	print_col(contact.nickname, BORDER_LEFT_RIGHT);
	std::cout << std::endl ;
}


void	print_line_separator()
{
	int	current_col = 0;
	const int border_left = 1;
	const int last_border = 1;
	const int nb_col = 4;

	while (current_col < (COL_MAX + border_left) * nb_col + last_border)
	{
		std::cout << "-";
		current_col++;
	}

	std::cout << std::endl;
}

void	print_header()
{
	print_line_separator();
	print_col("INDEX", BORDER_LEFT);
	print_col("FIRST NAME", BORDER_LEFT);
	print_col("LAST NAME", BORDER_LEFT);
	print_col("NICKNAME", BORDER_LEFT_RIGHT);
	std::cout << std::endl ;
	print_line_separator();
}

void PhoneBook::print()
{
	print_header();
	for (int i = 0; i < this->length(); i++)
		print_line(i, this->array[i]);
	print_line_separator();
}
