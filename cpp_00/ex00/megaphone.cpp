#include <iostream>

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	tmp;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (i = 1 ; i < ac ; i++)
		{
			for (j = 0 ; av[i][j] ; j++)
			{
				tmp = av[i][j];
				if (tmp >= 'a' && tmp <= 'z')
					tmp -= ('a' - 'A');
				std::cout << tmp;
			}
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
	return (0);
}
