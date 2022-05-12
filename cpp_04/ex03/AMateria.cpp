#include "AMateria.hpp"

AMateria::AMateria()	{
}

AMateria::AMateria(std::string const & type)	{
	this->setType(type);
	this->setXP(0);
}

AMateria::AMateria(AMateria const & ref)	{
	this->setType(ref.getType());
	this->setXP(ref.getXP());
}

AMateria::~AMateria()	{
}

void			AMateria::setType(std::string const &type)	{
	this->_type = type;
}

std::string const & AMateria::getType() const	{
	return (this->_type);
}

void			AMateria::setXP(unsigned int const &amount)	{
	this->_xp = amount;
}

void			AMateria::incXP(unsigned int const &amount)	{
	this->_xp += amount;
}

unsigned int AMateria::getXP() const	{
	return (this->_xp);
}

void AMateria::use(ICharacter& target)	{
	(void)target;
	this->incXP(10);
}

AMateria & AMateria::operator=(AMateria const &ref)	{
	this->setType(ref.getType());
	this->setXP(ref.getXP());
	return (*this);
}
