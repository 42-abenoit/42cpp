#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "IException.hpp"

OfficeBlock::OfficeBlock()	{
	this->_intern = NULL;
	this->_signer = NULL;
	this->_executor = NULL;
}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor)	{
	this->_intern = intern;
	this->_signer = signer;
	this->_executor = executor;
}
	
OfficeBlock::~OfficeBlock()	{

}

Intern	*OfficeBlock::getIntern()	{
	return (this->_intern);
}
	
void	OfficeBlock::setIntern(Intern *intern)	{
	this->_intern = intern;
}

Bureaucrat	*OfficeBlock::getSigner()	{
	return (this->_signer);
}

void	OfficeBlock::setSigner(Bureaucrat *signer)	{
	this->_signer = signer;
}

Bureaucrat	*OfficeBlock::getExecutor()	{
	return (this->_executor);
}

void	OfficeBlock::setExecutor(Bureaucrat *executor)	{
	this->_executor = executor;
}

void	OfficeBlock::doBureaucracy(std::string form, std::string target)	{
	Form	*ptr;

	if (this->_intern == NULL || this->_signer == NULL || this->_executor == NULL)
	{
		throw OfficeBlock::IncompleteTeam();
	}
	try
	{
		ptr = NULL;
		ptr = this->_intern->makeForm(form, target);
		this->_signer->signForm(*ptr);
		this->_executor->executeForm(*ptr);
	}
	catch (IException &e)
	{
		if (ptr != NULL)
		{
			delete ptr;
			ptr = NULL;
		}
		e.raise();
	}
	if (ptr != NULL)
	{
		delete ptr;
		ptr = NULL;
	}
}
