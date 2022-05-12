#include "Pony.hpp"

pony::pony(void)
{
	std::string	buff;

	std::cout << "Name your new pony: ";
	std::getline(std::cin, buff);
	this->name = buff;
	this->alive = 1;
	this->age = 0;
}

pony::~pony(void)
{
	std::cout << this->name << " died at age " << this->age << std::endl;
}

void	pony::aging(void)
{
	int		tmp;
	this->age += 1;
	tmp = ((std::rand() % 100)) * (((age * age) / (std::rand() % 100)));
	if (tmp >= 70)
		this->alive = 0;
}

int		pony::health_check(void)
{
	std::srand(time(NULL));
	if (this->alive)
	{
		std::cout << this->name;
		if (this->age == 0)
			std::cout << " was just born !" << std::endl;
		else
			std::cout << " just turned " << this->age << "." << std::endl;
		return (1);
	}
	else
		return (0);
}
