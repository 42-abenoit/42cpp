#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type)	{
	this->_name = name;
	this->_type = type;
	this->announce();
}

Zombie::~Zombie(void)	{
}

void	Zombie::announce(void)	{
	std::cout << "<" << this->_type << " " << this->_name << "> ";
	std::cout << "Braiiiiiiinnnssss ..." << std::endl;
}
