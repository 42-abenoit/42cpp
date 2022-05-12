#include "Cure.hpp"

Cure::Cure()	{
	this->setType("cure");
	this->setXP(0);
}

Cure::Cure(Cure const & ref)	{
	this->setType(ref.getType());
	this->setXP(ref.getXP());
}

Cure::~Cure()	{
}

Cure* Cure::clone() const	{
	return (new Cure);
}

void Cure::use(ICharacter& target)	{
	this->AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure & Cure::operator=(Cure const &ref)	{
	this->setType(ref.getType());
	this->setXP(ref.getXP());
	return (*this);
}
