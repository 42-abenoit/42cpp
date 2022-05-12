#include "Peasant.hpp"

Peasant::Peasant(std::string const &name)	{
	this->setName(name);
	std::cout << "Ready to work." << std::endl;
}

Peasant::Peasant(Peasant const &peasant)	{
	this->setName(peasant.getName());
	std::cout << "Ready to work." << std::endl;
}

Peasant::Peasant(Victim const &vic)	{
	this->setName(vic.getName());
	std::cout << "Ready to work." << std::endl;
}

Peasant::~Peasant(void)	{
	std::cout << "That's it. I'm dead." << std::endl;
}

void		Peasant::getPolymorphed(void) const	{
	std::cout << this->getName() << " has been turned into a newt!" << std::endl;
}

Peasant & Peasant::operator=(Peasant const &peasant)	{
	this->_name = peasant.getName();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Peasant const & peasant)	{
	o << peasant.introduce();
	return (o);
}
