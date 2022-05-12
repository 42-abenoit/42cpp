#include "RustyKnife.hpp"

RustyKnife::RustyKnife()	{
	this->_name = "RustyKnife";
	this->_damage = 12;
	this->_apcost = 2;
}

RustyKnife::~RustyKnife()	{}

void	RustyKnife::attack() const	{
	std::cout << "* tchac swiifff.. tchac *" << std::endl;
}
