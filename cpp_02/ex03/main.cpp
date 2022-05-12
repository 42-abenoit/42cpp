#include "Fixed.hpp"
#include <sstream>
#include <string>

int	main(int ac, char **av)	{
	int					i = 0;
	std::string			buff;
	float				tmp;
	Fixed				nb[256];

	(void)av;
	if (ac != 2)
		return (1);
	std::stringstream	inputStream(av[1]);
	while (std::getline(inputStream, buff, ' '))
	{
		tmp = std::stof(buff);
		nb[i] = Fixed(tmp);
		i++;
	}

	std::cout << nb[0] << std::endl;
	std::cout << nb[1] << std::endl;
}
