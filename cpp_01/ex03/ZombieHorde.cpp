#include "ZombieHorde.hpp"
#include <string>

ZombieHorde::ZombieHorde(int n)	{
	this->_horde = new Zombie[n];
	this->_size = n;
	this->announce();
}

ZombieHorde::~ZombieHorde(void)	{
	delete [] this->_horde;
}

void	ZombieHorde::announce(void)	{
	for (int i = 0; i < this->_size; i++)
		this->_horde[i].announce();
}
