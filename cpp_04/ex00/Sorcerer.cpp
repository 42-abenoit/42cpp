#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string const &name, std::string const &title)	{
	this->setName(name);
	this->setTitle(title);
	std::cout << this->getName() << ", " << this->getTitle() << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &sorc)	{
	this->setName(sorc.getName());
	this->setTitle(sorc.getTitle());
	std::cout << this->getName() << ", " << this->getTitle() << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer(void)	{
	std::cout << this->getName() << ", " << this->getTitle() << ", is dead. " 
				<< "Consequences will never be the same!"<< std::endl;
}

Sorcerer & Sorcerer::operator=(Sorcerer const &sorc)	{
	this->_name = sorc.getName();
	this->_title = sorc.getTitle();
	return *this;
}

std::string	Sorcerer::getName(void) const	{
	return (this->_name);
}

void		Sorcerer::setName(std::string const &name)	{
	this->_name = name;
}

std::string	Sorcerer::getTitle(void) const	{
	return (this->_title);
}

void		Sorcerer::setTitle(std::string const &title)	{
	this->_title = title;
}

std::string	Sorcerer::introduce(void) const	{
	return ("I am " + this->getName() + ", " + this->getTitle() + ", and I like ponies!\n");
}

void		Sorcerer::polymorph(Victim const &target) const 	{
	target.getPolymorphed();
}

void		Sorcerer::getPolymorphed(void) const	{
	std::cout << this->getName() << ", " << this->getTitle() << ", has been turned into a chicken!" << std::endl;
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & sorc)	{
	o << sorc.introduce();
	return (o);
}
