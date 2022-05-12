#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)	:
	Form("PresidentialPardonForm", 25, 5, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm & ref)	:
	Form(ref.getType(), ref.getSignReq(), ref.getExecReq(), ref.getTarget())
{
	this->setSign(ref.isSigned());
}

PresidentialPardonForm::~PresidentialPardonForm()	{

}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const	{
	Form::execute(executor);
		std::cout << this->getTarget() << " has been pardonned by Zafod Beeblerox."
					<< std::endl;
}
