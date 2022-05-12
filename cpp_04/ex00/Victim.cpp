#include "Victim.hpp"

Victim::Victim(std::string const &name)	{
	this->setName(name);
	std::cout << "Some random victim called " << this->getName() << " just appeared!" << std::endl;
}

Victim::Victim(Victim const &vic)	{
	this->setName(vic.getName());
	std::cout << "Some random victim called " << this->getName() << " just appeared!" << std::endl;
}

Victim::~Victim(void)	{
	std::cout << "Victim " << this->getName() << " just died for no apparent reason!" << std::endl;
}

std::string	Victim::getName(void) const	{
	return (this->_name);
}

void		Victim::setName(std::string const &name)	{
	this->_name = name;
}

std::string	Victim::introduce(void) const	{
	return ("I'm " + this->getName() + ", and I like otters!\n");
}

void		Victim::getPolymorphed(void) const	{
	std::cout << this->getName() << " has been turned into a cute little sheep!" << std::endl;
}

Victim & Victim::operator=(Victim const &vic)	{
	this->_name = vic.getName();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Victim const & vic)	{
	o << vic.introduce();
	return (o);
}
