#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() :
	_reqSign(150),
	_reqExec(150),
	_type("Form")
{
	this->_signed = 0;
	this->_target = "none";
}

Form::Form(std::string type, int reqSign, int reqExec, std::string target)	:
	_reqSign(checkGrade(reqSign)),
	_reqExec(checkGrade(reqExec)),
	_type(type)
{
	this->_signed = 0;
	this->_target = target;
}

Form::Form(Form & ref)	:
	_signed(checkGrade(ref.isSigned())),
	_reqSign(checkGrade(ref.getSignReq())),
	_reqExec(checkGrade(ref.getExecReq())),
	_type(ref.getType())
{
	this->_target = ref.getTarget();
}

Form::~Form()	{

}

int	Form::checkGrade(int Grade)
{
	if (Grade < 1)
		throw Form::GradeTooHighException();
	else if (Grade > 150)
		throw Form::GradeTooLowException();
	return (Grade);
}

void	Form::setSign(bool sign)	{
	this->_signed = sign;
}

bool	Form::isSigned()	const	{
	return (this->_signed);
}

std::string	Form::getType()	const	{
	return (this->_type);
}

std::string	Form::getTarget()	const	{
	return (this->_target);
}

void	Form::beSigned(Bureaucrat & ref)	{
	if (this->_signed == 1)
		throw Form::FormAlreadySignedException();
	if (ref.getGrade() <= this->_reqSign)
		this->_signed = 1;
	else
		throw Form::GradeTooLowException();
	std::cout << ref.getName() << " signs " << this->getType() << std::endl;
}

int		Form::getSignReq(void)	const	{
	return (this->_reqSign);
}

int		Form::getExecReq(void)	const	{
	return (this->_reqExec);
}

void	Form::execute(Bureaucrat const & executor) const	{
	if (!this->isSigned())
		throw Form::FormNotSignedException();
	if (executor.getGrade() > this->_reqExec)
		throw Form::GradeTooLowException();
	else
		std::cout << executor.getName() << " executes " << this->getType() << std::endl;
}

std::ostream & operator<<(std::ostream & o, Form const &ref)	{
	std::string	status;

	status = (ref.isSigned() ? "signed" : "unsigned");
	o << ref.getType() << " requires grade " << ref.getSignReq() 
		<< " for signature and grade " << ref.getExecReq()
		<< " for execution and is currently " << status << "." << std::endl;
	return (o);
}
