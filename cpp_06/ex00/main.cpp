#include <iostream>
#include <cstdlib>
#include <limits.h>

int	main(int ac, char **av)
{
	double	d;
	
	if (ac != 2)
		return (1);
	d = std::atof(av[1]);
	if (d > CHAR_MIN && d < CHAR_MAX)
	{
		if (d >= 32 && d <= 126)
			std::cout << "char: " << static_cast<char>(d) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (d > INT_MIN && d < INT_MAX)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(d) 
				<< (d - static_cast<int>(d) == 0 ? ".0" : "") << "f" << std::endl;
	std::cout <<"double: " << d << (d - static_cast<int>(d) == 0 ? ".0" : "")
				<< std::endl;
}
