#include "Peon.hpp"

Peon::Peon(std::string const &name)	{
	this->setName(name);
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &peon)	{
	this->setName(peon.getName());
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Victim const &vic)	{
	this->setName(vic.getName());
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void)	{
	std::cout << "Bleuark..." << std::endl;
}

void		Peon::getPolymorphed(void) const	{
	std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}

Peon & Peon::operator=(Peon const &peon)	{
	this->_name = peon.getName();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Peon const & peon)	{
	o << peon.introduce();
	return (o);
}
