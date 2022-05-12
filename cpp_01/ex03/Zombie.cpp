#include "Zombie.hpp"

Zombie::Zombie()	{
	this->_name = randomChump();
	this->_type = setZombieType();
}

Zombie::~Zombie(void)	{
}

std::string	Zombie::setZombieType(void)	{
	const std::string types[] = {"Braindead", "Infected", "Rotten"};

	return (types[std::rand() % 3]);
}

std::string	Zombie::randomChump(void)	{
	const std::string	names[] = {"Bob",
		"Bill", "Jim", "Kate", "Kim", "Doug",
		"James", "Tom", "Ellen", "Jack", "Cindy",
		"Pete", "Sam", "Meg"};
	
	return (names[std::rand() % 14]);
}


void	Zombie::announce(void)	{
	std::cout << "<" << this->_type << " " << this->_name << "> ";
	std::cout << "Braiiiiiiinnnssss ..." << std::endl;
}
