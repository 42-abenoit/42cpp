#include "Fire.hpp"

Fire::Fire()	{
	this->setType("fire");
	this->setXP(0);
}

Fire::Fire(Fire const & ref)	{
	this->setType(ref.getType());
	this->setXP(ref.getXP());
}

Fire::~Fire()	{
}

Fire* Fire::clone() const	{
	return (new Fire);
}

void Fire::use(ICharacter& target)	{
	this->AMateria::use(target);
	std::cout << "* sets " << target.getName() << " on fire *" << std::endl;
}

Fire & Fire::operator=(Fire const &ref)	{
	this->setType(ref.getType());
	this->setXP(ref.getXP());
	return (*this);
}
