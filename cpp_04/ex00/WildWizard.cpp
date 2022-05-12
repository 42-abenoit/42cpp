#include "WildWizard.hpp"

WildWizard::WildWizard(std::string const &name, std::string const &title)	{
	this->setName(name);
	this->setTitle(title);
	std::cout << this->getName() << ", " << this->getTitle() << ", appeared in our material plane!" << std::endl;
}

WildWizard::WildWizard(WildWizard const &wiz)	{
	this->setName(wiz.getName());
	this->setTitle(wiz.getTitle());
	std::cout << this->getName() << ", " << this->getTitle() << ", appeared in our material plane!" << std::endl;
}

WildWizard::WildWizard(Sorcerer const &sorc)	{
	this->setName(sorc.getName());
	this->setTitle(sorc.getTitle());
	std::cout << this->getName() << ", " << this->getTitle() << ", appeared in our material plane!" << std::endl;
}

WildWizard::~WildWizard(void)	{
	std::cout << this->getName() << ", " << this->getTitle() << ", returned to oblivion." << std::endl;
}

void		WildWizard::polymorph(Victim const &target) const 	{
	if (std::rand() % 10 < 4)
		target.getPolymorphed();
	else
	{
		std::cout << this->getName() << " " << this->getTitle() << "'s spell backfired!" << std::endl;
		this->getPolymorphed();
	}
}

void		WildWizard::polymorph(Sorcerer const &target) const 	{
	if (std::rand() % 10 < 4)
		target.getPolymorphed();
	else
	{
		std::cout << this->getName() << " " << this->getTitle() << "'s spell backfired!" << std::endl;
		this->getPolymorphed();
	}
}

WildWizard & WildWizard::operator=(WildWizard const &wiz)	{
	this->_name = wiz.getName();
	this->_title = wiz.getTitle();
	return *this;
}

std::ostream & operator<<(std::ostream & o, WildWizard const & wiz)	{
	o << wiz.introduce();
	return (o);
}
