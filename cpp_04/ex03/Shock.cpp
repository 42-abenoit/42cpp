#include "Shock.hpp"

Shock::Shock()	{
	this->setType("shock");
	this->setXP(0);
}

Shock::Shock(Shock const & ref)	{
	this->setType(ref.getType());
	this->setXP(ref.getXP());
}

Shock::~Shock()	{
}

Shock* Shock::clone() const	{
	return (new Shock);
}

void Shock::use(ICharacter& target)	{
	this->AMateria::use(target);
	std::cout << "* shoots a thunder bolt at " << target.getName() << " *" << std::endl;
}

Shock & Shock::operator=(Shock const &ref)	{
	this->setType(ref.getType());
	this->setXP(ref.getXP());
	return (*this);
}
