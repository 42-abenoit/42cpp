#include "PowerFist.hpp"

PowerFist::PowerFist()	{
	this->_name = "PowerFist";
	this->_damage = 50;
	this->_apcost = 8;
}

PowerFist::~PowerFist()	{}

void	PowerFist::attack() const	{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
