// afficher tous les arguments en majuscule

// si pas d'arguments afficher 

#include <iostream>

void	str_to_uppercase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
}

void	print_str(const char *str)
{
	std::cout << str;
}

void	print_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		str_to_uppercase(argv[i]);
		print_str(argv[i]);
		i++;
	}
	std::cout << '\n';
}

int	main(int argc, char **argv)
{
	argc--;
	argv++;
	if (argc < 1)
	{
		print_str("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
		std::cout << '\n';
		return (0);
	}
	print_args(argc, argv);
	return (0);
}