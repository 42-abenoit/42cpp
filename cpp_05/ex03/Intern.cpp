#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()	{
	ShrubberyCreationForm	*shrub = new ShrubberyCreationForm("none");
	RobotomyRequestForm		*robo = new RobotomyRequestForm("none");
	PresidentialPardonForm	*pardon = new PresidentialPardonForm("none");

	for (int i = 0; i < 4; i++)
	{
		this->_knownForm[i] = NULL;
	}
	this->learnForm(shrub);
	this->learnForm(robo);
	this->learnForm(pardon);
}

Intern::Intern(Intern const &ref)	{
	for (int i = 0; i < 4; i++)
	{
		if (ref._knownForm[i] != NULL)
			this->_knownForm[i] = ref._knownForm[i]->clone("none");
		else
			this->_knownForm[i] = NULL;
	}
}

Intern::~Intern() {
	for (int i = 0; i < 4; i++)
	{
		if (this->_knownForm[i] != NULL)
			delete this->_knownForm[i];
	}
}

void Intern::learnForm(Form *m)	{
	int	i;

	i = 0;
	while (i < 4 && this->_knownForm[i] != NULL)
		i++;
	if (i < 4)
		this->_knownForm[i] = m;
}

Form* Intern::makeForm(std::string const & type, std::string const target)	{
	for (int i = 0; i < 4; i++)
	{
		if (this->_knownForm[i] != NULL)
		{
			if (this->_knownForm[i]->getType() == type)
			{
				std::cout << "Intern creates " << this->_knownForm[i]->getType() << std::endl;
				return (this->_knownForm[i]->clone(target));
			}
		}
	}
	throw Intern::FormNotKnownException();
	return (NULL);
}


Intern & Intern::operator=(Intern const &ref)	{
	for (int i = 0; i < 4; i++)
	{
		if (this->_knownForm[i] != NULL)
			delete this->_knownForm[i];
		if (ref._knownForm[i] != NULL)
				this->_knownForm[i] = ref._knownForm[i]->clone("none");
		else
			this->_knownForm[i] = NULL;
	}
	return (*this);
}

