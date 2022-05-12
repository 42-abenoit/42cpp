#include "Ice.hpp"

Ice::Ice()	{
	this->setType("ice");
	this->setXP(0);
}

Ice::Ice(Ice const & ref)	{
	this->setType(ref.getType());
	this->setXP(ref.getXP());
}

Ice::~Ice()	{
}

Ice* Ice::clone() const	{
	return (new Ice);
}

void Ice::use(ICharacter& target)	{
	this->AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice & Ice::operator=(Ice const &ref)	{
	this->setType(ref.getType());
	this->setXP(ref.getXP());
	return (*this);
}
