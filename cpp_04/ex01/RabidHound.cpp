#include "RabidHound.hpp"

RabidHound::RabidHound()	{
	std::cout << "Grrrr.. Rrr" << std::endl;
	this->setType("Rabid Hound");
	this->setHp(110);
}

RabidHound::RabidHound(RabidHound const & src)	{
	std::cout << "Grrrr.. Rrr" << std::endl;
	this->_type = src.getType();
	this->_hp = src.getHp();
}

RabidHound::~RabidHound()	{
	std::cout << "* Barks *" << std::endl;
}

void	RabidHound::takeDamage(int amount)	{
	if (amount - 3 >= 0)
	{
		if (this->_hp - (amount - 3) < 0)
			this->_hp = 0;
		else
			this->_hp -= (amount - 3);
	}
}
