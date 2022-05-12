#include "SuperMutant.hpp"

SuperMutant::SuperMutant()	{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	this->setType("Super Mutant");
	this->setHp(170);
}

SuperMutant::SuperMutant(SuperMutant const & src)	{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	this->_type = src.getType();
	this->_hp = src.getHp();
}

SuperMutant::~SuperMutant()	{
	std::cout << "Aaargh..." << std::endl;
}

void	SuperMutant::takeDamage(int amount)	{
	if (amount - 3 >= 0)
	{
		if (this->_hp - (amount - 3) < 0)
			this->_hp = 0;
		else
			this->_hp -= (amount - 3);
	}
}
