#include <iostream>
#include <string>

int	main(void)	{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*brainPtr = &brain;
	std::string	&brainRef = brain;

	std::cout << *brainPtr << std::endl;
	std::cout << brainRef << std::endl;
}
