#include "RadScorpion.hpp"

RadScorpion::RadScorpion()	{
	std::cout << "* click click click *" << std::endl;
	this->setType("RadScorpion");
	this->setHp(80);
}

RadScorpion::RadScorpion(RadScorpion const & src)	{
	std::cout << "* click click click *" << std::endl;
	this->_type = src.getType();
	this->_hp = src.getHp();
}

RadScorpion::~RadScorpion()	{
	std::cout << "* SPROTCH *" << std::endl;
}

void	RadScorpion::takeDamage(int amount)	{
	if (amount - 3 >= 0)
	{
		if (this->_hp - (amount - 3) < 0)
			this->_hp = 0;
		else
			this->_hp -= (amount - 3);
	}
}
