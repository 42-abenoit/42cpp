#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()	{
	this->_name = "PlasmaRifle";
	this->_damage = 21;
	this->_apcost = 5;
}

PlasmaRifle::~PlasmaRifle()	{}

void	PlasmaRifle::attack() const	{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
