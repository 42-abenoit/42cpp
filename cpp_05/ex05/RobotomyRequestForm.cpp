#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)	:
	Form("RobotomyRequestForm", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm & ref)	:
	Form(ref.getType(), ref.getSignReq(), ref.getExecReq(), ref.getTarget())
{
	this->setSign(ref.isSigned());
}

RobotomyRequestForm::~RobotomyRequestForm()	{

}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const	{
	Form::execute(executor);
	std::cout << "* Brzzzzzzzt.. Krrrrttz ... Brr.. *" << std::endl;
	if (std::rand() % 100 >= 50)
	{
		std::cout << "Something went horribly wrong, " << this->getTarget() 
					<< " won't be quite the same after that." << std::endl;
	}
	else
	{
		std::cout << this->getTarget() << " has been robotomized successfully!"
					<< std::endl;
	}
}

Form	*RobotomyRequestForm::clone(std::string target)	{
	return (new RobotomyRequestForm(target));
}
